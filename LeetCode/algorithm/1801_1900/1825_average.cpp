/**
 * @date 2022/1/18
 * @author 2mu
 * @brief hard 求出MK平均值
 * 
 * 一、简单模拟
 * 按照要求进行模拟，碰到计算平均值的时候，就老老实实排序，然后取前K个和后K个外的元素。
 * 先做出来，再讲优化（好吧，实际上不知道怎么优化）
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 
 * 二、有序集合，队列
 * 官方题解：
 * 
 * 借助queue保存最后m个元素，同时维护入队顺序。
 * 借助了有序集合（红黑树）的效率，它的插入，删除，查找都是O(logN)。其中使用3个集合
 * 来分别维护最小的k个数，最大的k个数，剩余的所有数。这个操作太秀了。
 * 
 * 时间复杂度：O(logN)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class MKAverage
{
public:
    MKAverage(int m, int k)
        : m(m), k(k)
    {
        m_sum = 0;
    }

    void addElement(int num)
    {
        m_que.push(num);
        if(m_que.size() <= m)
        {
            s2.insert(num);
            m_sum += num;
            if(m_que.size() == m)
            {
                while(s1.size() < k)
                {
                    int num = *s2.begin(); 
                    s1.insert(num);
                    m_sum -= num;
                    s2.erase(s2.begin());
                }
                while(s3.size() < k)
                {
                    int num = *s2.rbegin();
                    s3.insert(num);
                    m_sum -= num;
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }
        if(num < *s1.rbegin())
        {
            s1.insert(num);         // 插入到s1中
            s2.insert(*s1.rbegin());// 将s1的最大元素移动到s2中。
            m_sum += *s1.rbegin();
            s1.erase(prev(s1.end()));// 将s1的最大元素删除。
        }
        else if(num > *s3.begin())
        {
            s3.insert(num);
            s2.insert(*s3.begin());
            m_sum += *s3.begin();
            s3.erase(s3.begin());
        }
        else
        {
            s2.insert(num);
            m_sum += num;
        }
        // 经过上面if esif else，s2元素变多了一个。此时需要删除一个元素，谁呢？que的队首。
        // 下面的if elif else 需要和上面的对应，否则会出bug。
        int frontNum = m_que.front();
        m_que.pop();
        if(s1.count(frontNum) > 0)
        {
            s1.erase(s1.find(frontNum));
            s1.insert(*s2.begin());
            m_sum -= *s2.begin();
            s2.erase(s2.begin());
        }
        else if(s3.count(frontNum) > 0)
        {
            s3.erase(s3.find(frontNum));
            s3.insert(*s2.rbegin());
            m_sum -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        }
        else
        {
            m_sum -= frontNum;
            s2.erase(s2.find(frontNum));
        }
    }

    int calculateMKAverage()
    {
        if(m_que.size() < m)
            return -1;
        return m_sum / (m - 2*k);
    }

private:
    int m, k;
    std::queue<int> m_que;
    std::multiset<int> s1, s2, s3;
    long long m_sum;      // 满足条件的除k外元素的数组之和。
};

// class MKAverage 
// {
// public:
//     MKAverage(int m, int k)
//         : m_maxWidth(m)
//         , k(k)
//     {
        
//     }
    
//     void addElement(int num)
//     {
//         m_vctNums.push_back(num);
//         if(m_windows.size() >= m_maxWidth)
//             m_windows.pop_front();

//         m_windows.push_back(num);
//     }
    
//     int calculateMKAverage() 
//     {
//         if(m_vctNums.size() < m_maxWidth)
//             return -1;
//         std::vector<int> tmpArr(m_windows.begin(), m_windows.end());
//         std::sort(tmpArr.begin(), tmpArr.end());
//         int count = tmpArr.size() - 2*k;
//         int sum = 0;
//         for(int i = k; i < k + count; ++i)
//             sum += tmpArr[i];
//         return sum / count;
//     }

// private:
//     int k;
//     int m_maxWidth;
//     std::deque<int> m_windows;// 滑动窗口
//     std::vector<int> m_vctNums;
// };


int main()
{
    MKAverage mkaverage(3, 1);
    mkaverage.addElement(3);
    mkaverage.addElement(1);
    std::cout << mkaverage.calculateMKAverage() << std::endl;
    mkaverage.addElement(10);
    std::cout << mkaverage.calculateMKAverage() << std::endl;
    mkaverage.addElement(5);
    mkaverage.addElement(5);
    mkaverage.addElement(5);
    std::cout << mkaverage.calculateMKAverage() << std::endl;
    return 0;
}
