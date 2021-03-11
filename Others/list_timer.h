/********************************************************************************************
 * @author reddragon
 * @date 2021/3/6
 * @brief 基于升序定时器链表
 * 按照定时器的超时时间作升序排序
 * 
 * 添加定时器的时间复杂度为O(n)
 * 删除定时器的时间复杂度为O(1)
 ********************************************************************************************/
#ifndef LIST_TIMER
#define LIST_TIMER

#define BUFFER_SIZE 64
#include <cstdio>
#include <time.h>
#include <arpa/inet.h>

class util_timer;

struct client_data{
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer* timer;
};

// 定时器类
struct util_timer{
    time_t expire;// 超时时间
    void (*cb_func)(client_data*);
    client_data* user_data;
    util_timer* prev;
    util_timer* next;

    util_timer()
        :prev(nullptr), next(nullptr){}
};


class sort_timer_lst
{
private:
    util_timer* head;
    util_timer* tail;
    // 重载
    void addTimer(util_timer* timer, util_timer* head)
    {
        util_timer* prev = head;
        util_timer* tmp = head->next;
        // 遍历整个head链表, 将timer放到合适的地方
        while(tmp)
        {
            if(timer->expire < tmp->expire)
            {
                prev->next = timer;
                timer->next = tmp;
                timer->prev = prev;
                tmp->prev = timer;
                break;
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        // 插入到尾部
        if(!tmp)
        {
            prev->next = timer;
            timer->prev = prev;
            timer->next = nullptr;
            tail = timer;
        }
    } 

public:
    sort_timer_lst()
        : head(nullptr), tail(nullptr){}
    ~sort_timer_lst()
    {// 删除链表上所有的定时器
        util_timer* tmp = head;
        while(tmp)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    // 添加定时器
    void addTimer(util_timer* timer)
    {
        if(!timer)
        {// 参数无效
            return ;
        }
        if(!head)
        {
            head = tail = timer;
            return ;
        }
        // 比头部还小, 直接插入到头部, 否则调用重载函数
        if(timer->expire < head->expire)
        {
            timer->next = head;
            head->prev = timer;
            head = timer;
            return ;
        }
        else
            addTimer(timer, head);
    }

    // 当定时器超时时间变化时, 调整定时器在链表中的位置(往后调, 不考虑往前跳的情况)
    void adjust_timer(util_timer* timer)
    {
        if(!timer)
        {
            return;
        }
        util_timer *tmp = timer->next;
        // 定时器处于尾部, 或超时时间变化后仍然小于next, 则不调整
        if(timer == tail || timer->expire < tmp->expire)
            return;
        // 如果是头结点
        if(timer == head)
        {
            head = head->next;
            head->prev = nullptr;
            timer->next = nullptr;
            addTimer(timer, head);
        }
        else{
            timer->next->prev = timer->prev;
            timer->prev->next = timer->next;
            timer->prev = timer->next = nullptr;
            addTimer(timer, tmp);// 从下一个结点开始搜索
        }
    }

    void delTimer(util_timer* timer)
    {
        if(!timer)
            return;
        if((timer == head) && (timer == tail))
        {
            delete timer;
            head = nullptr;
            tail = nullptr;
            return;
        }
        if(timer == head)
        {
            head = head->next;
            head->prev = nullptr;
            delete timer;
            return;
        }
        if(timer == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete timer;
            return;
        }
        // 定时器处于链表中间
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        delete timer;
    }

    // 处理`时间到期的定时器
    void tick()
    {
        if(!head)
        {
            return;
        }
        printf("timer tick\n");
        time_t cur = time(NULL);
        util_timer* tmp = head;
        // 从头结点依次删除到期的timer, 知道第一个未到期的timer
        while(tmp)
        {
            if(cur < tmp->expire)
            {// 未超时
                break;
            }
            tmp->cb_func(tmp->user_data);// 到期执行回调函数
            // 执行完定时任务之后, 将他从链表中删除
            head = tmp->next;
            if(head)
                head->prev = nullptr;
            delete tmp;
            tmp = head;
        }
    }
};

#endif 