/**
 * @date 2022/7/16
 * @author 2mu
 * @brief easy 滑动窗口的平均值
 *
 * 1. 队列
 * 使用一个deque或者queue保存maxLen个元素，一旦next插入新的元素，就队列首元素删除。
 * 同时使用sum变量维护队列所有值的和。这样就可以快速计算出平均值。
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(maxLen)
 */

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


class MovingAverage 
{
public:
    MovingAverage(int size) 
    {
        m_maxLen = size;
    }
    
    double next(int val) 
    {
        if(m_windows.size() < m_maxLen)
        {
            m_windows.push_back(val);
            m_sum += val;
            return m_sum / m_windows.size();
        }
        else
        {
            m_sum -= m_windows.front();
            m_windows.pop_front();
            m_windows.push_back(val);
            m_sum += val;
            return m_sum / m_maxLen;
        }
    }

private:
    size_t          m_maxLen;
    double          m_sum = 0;
    std::deque<int> m_windows;
};

int main()
{
    MovingAverage test = MovingAverage(3);
    std::cout << test.next(1) << std::endl;
    std::cout << test.next(10) << std::endl;
    std::cout << test.next(3) << std::endl;
    std::cout << test.next(5) << std::endl;
    return 0;
}
