/**
 * @author ling
 * @date 2021/5/29
 * @brief easy 按序打印
 *
 * 1. 条件变量
 * C++17标准，没有信号量，所以不能使用。虽然linux的posix线程库中有信号量。但是这里没有使用。
 * 使用mutex可以吗？ 不可以，因为这里是按顺序打印一次，并不是死循环一直打印。所以如果单纯使用
 * mutex而没有条件变量的通知机制，无法保证2，3会抢锁唤醒。
 */

#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
public:
    Foo()
        :m_id(1)
    {}

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        std::lock_guard<std::mutex> lk(m_mtx);
        printFirst();
        m_id++;
        m_cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(m_mtx);
        while(m_id != 2)
            m_cv1.wait(lk, [this]{return m_id == 2;});
        printSecond();
        m_cv2.notify_one();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(m_mtx);
        while(m_id!=3)
            m_cv2.wait(lk, [this]{return m_id == 3;});
        printThird();
    }

private:
    int                     m_id;
    std::mutex              m_mtx;
    std::condition_variable m_cv1;
    std::condition_variable m_cv2;
};

int main()
{
    return 0;
}