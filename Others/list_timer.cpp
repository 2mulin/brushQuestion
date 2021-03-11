/********************************************************************************************
 * @author reddragon
 * @date 2021/3/6
 * @brief 处理非活跃连接
 ********************************************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>

#include "list_timer.h"

#define FD_LIMITS 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 6

static int sockfd[2];
static sort_timer_lst timer_lst;
static int epollfd = 0;

int setNonBlocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    if(-1 == fcntl(fd, F_SETFL, new_option))
    {
        perror("fcntl");
        return -1;
    }
    return 0;
}

void addfd(int epoll_fd, int fd)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);
    setNonBlocking(fd);
}

// 信号处理函数
void sig_handler(int sig)
{
    int save_errno = errno;
    int msg = sig;
    send(sockfd[1], (char*)&msg, 1, 0);
    errno = save_errno;
    printf("%d信号已发送\n",sig);
}

// 设置信号处理函数
void addsig(int sig)
{
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = sig_handler;
    act.sa_flags |= SA_RESTART;
    sigfillset(&act.sa_mask);
    assert(sigaction(sig, &act, nullptr) != -1);
    printf("信号处理函数设置成功!\n");
}

void timer_handler()
{
    // 定时处理任务
    timer_lst.tick();
    alarm(TIMESLOT);
}

// 删除user_data
void cb_func(client_data* user_data)
{
    epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->sockfd, NULL);
    assert(user_data);
    close(user_data->sockfd);
    printf("close fd %d\n", user_data->sockfd);
}


int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("usage: %s port_number\n", basename(argv[0]));
        return -1;
    }
    int port = atoi(argv[1]);

    struct sockaddr_in address;
    bzero(&address,  sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int listenFd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenFd >= 0);
    int ret = bind(listenFd, (struct sockaddr*)&address, sizeof(address));
    assert(ret >= 0);
    ret = listen(listenFd, 10);
    assert(ret != -1);
    
    // 创建epoll实例
    int epollfd = epoll_create(10);
    assert(epollfd != -1);
    addfd(epollfd, listenFd);

    // 创建一对相互连接的socket对
    ret = socketpair(AF_UNIX, SOCK_STREAM, 0, sockfd);
    assert(ret != -1);
    setNonBlocking(sockfd[1]);
    addfd(epollfd, sockfd[0]);

    // 设置信号处理函数
    addsig(SIGALRM);
    addsig(SIGTERM);// kill命令默认发送的信号

    alarm(TIMESLOT);// 到期发送SIGALRM信号

    bool timeout = false;

    struct epoll_event events[MAX_EVENT_NUMBER];
    client_data* users = new client_data[FD_LIMITS];
    bool stop_server = false;
    while(!stop_server)
    {
        // 阻塞, 直到触发
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(number < 0 && errno != EINTR)
        {
            perror("epoll_wait");
            break;
        }
        for(int i = 0; i < number; ++i)
        {
            int fd = events->data.fd;
            // 处理新到的客户链接
            if(fd == listenFd)
            {
                struct sockaddr_in client_addr;
                socklen_t len = sizeof(client_addr);
                int connfd = accept(listenFd, (struct sockaddr*)&client_addr, &len);
                addfd(epollfd, connfd);
                // 一个萝卜一个坑
                users[connfd].address = client_addr;
                users[connfd].sockfd = connfd;

                // 指针互指
                // 创建定时器, 设置好回调函数
                util_timer* timer = new util_timer;
                timer->user_data = &users[connfd];
                timer->cb_func = cb_func;
                time_t cur = time(nullptr);
                timer->expire = cur + 3*TIMESLOT;
                users[connfd].timer = timer;
                // 添加到定时器链表中
                timer_lst.addTimer(timer);
            }
            else if(fd == sockfd[0] && events[i].events & EPOLLIN)
            {// 被信号处理函数写过来的数据触发
                char signals[1024];
                ret = recv(sockfd[0], signals, sizeof(signals), 0);
                if(ret == -1)
                    continue;
                else if(ret == 0)
                    continue;
                else
                {
                    for(int i = 0; i < ret; ++i)
                    {
                        switch (signals[i])
                        {
                        case SIGALRM:
                            timeout = true;// 延迟处理
                            break;
                        case SIGTERM:
                            stop_server = true;
                        default:
                            break;
                        }
                    }
                }
            }
            else if(events[i].events & EPOLLIN)
            {// 处理客户连接上接收到的数据
                memset(users[fd].buf, '\0', BUFFER_SIZE);
                ret = recv(fd, users[fd].buf, BUFFER_SIZE - 1, 0);
                printf("get %d bytes of client data %s from %d\n", ret, users[fd].buf, fd);
                util_timer* timer = users[fd].timer;
                if(ret < 0)
                {
                    if(errno != EAGAIN)
                    {
                        cb_func(&users[fd]);
                        if(timer)
                            timer_lst.delTimer(timer);
                    }
                }
                else if(ret == 0)
                {
                    cb_func(&users[fd]);
                    if(timer)
                        timer_lst.delTimer(timer);
                }
                else
                {
                    // 重置定时器时间
                    if(timer)
                    {
                        time_t cur = time(nullptr);
                        timer->expire = cur + 3 * TIMESLOT;
                        printf("定时器已经重置\n");
                        timer_lst.adjust_timer(timer);
                    }
                }
            }
            else
            {
                
            }
        }
        if(timeout)
        {
            timer_handler();
            timeout = false;
        }
    }
    close(listenFd);
    close(sockfd[0]);
    close(sockfd[1]);
    delete [] users;
    return 0;
}
