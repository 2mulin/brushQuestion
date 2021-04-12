/********************************************************************************************
 * @author reddragon
 * @date 2021/4/11
 * @brief medium 丑数
 * 
 * 1，数学
 * 利用数学性质, 直接从1开始,往上乘2,3,5,就能得到所有的丑数.
 * 但是需要排序. 所以使用堆, 但是可能乘的时候有重复的丑数出现
 * 所以使用set去重. 防止count计数出错.
 * 时间复杂度: O(NlogN)         空间复杂度: O(N)
 * 
 * 2. 动态规划
 * 留着下次写
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>
using namespace std;

// 得到第N个丑数
int nthUglyNumber(int n)
{
    int count = 1;
    priority_queue<long, deque<long>, std::greater<long>> qu;
    set<long> s;
    s.insert(1);
    qu.push(1);
    vector<int> nums{2, 3, 5};
    // O(N)
    while (count < n)
    {
        long curr = qu.top();
        qu.pop();
        for (auto i : nums)
        {
            if (s.find(curr * i) == s.end())
            {
                // O(logN)
                qu.push(curr * i);
                s.insert(curr * i);
            }
        }
        ++count;
    }
    return qu.top();
}

int main()
{
    cout << nthUglyNumber(10) << endl;
    return 0;
}