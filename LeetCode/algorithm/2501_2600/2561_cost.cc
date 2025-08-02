/**
 * @date 2025/8/2
 * @author 2mu
 * @brief hard 重排水果
 *
 * 1. 贪心
 * 直接抄题解的答案，实在是太难想到了。
 * 
 * 题目要求两个数组完全相等，不是和相等，而是元素数量一摸一样。
 * 如果 数组1中的x数量 + 数组2中的x数量是偶数，则最终可能有答案。一旦两个数组中某个数字出现次数不为偶数，
 * 最终怎么分配都不会有答案，直接返回-1。
 *
 * 剩下来就是交换成本最小化的方法。首先每个数字交换次数可以确定为 （nums1中出现次数-num2中出现次数）的绝对值 / 2
 * 剩下问题怎么让交换成本小？
 * 
 * 有两种情况需要考虑，主要是还有个间接交换实在是难以想到。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;


long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    std::unordered_map<int, int> frequency_map;
    int m = INT_MAX;
    for (int b1 : basket1)
    {
        frequency_map[b1]++;
        m = min(m, b1);
    }
    for (int b2 : basket2)
    {
        frequency_map[b2]--;
        m = min(m, b2);
    }

    std::vector<int> merge;
    for(auto iter = frequency_map.begin(); iter != frequency_map.end(); ++iter)
    {
        if (iter->second % 2 != 0) {
            return -1;
        }
        for (int i = 0; i < abs(iter->second) / 2; ++i)
        {
            merge.push_back(iter->first);
        }
    }
    // 这代码写得太妙了... 反正左右都会交换，所以只需要中心点左右大小正确即可
    nth_element(merge.begin(), merge.begin() + merge.size() / 2, merge.end());
    return std::accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
            [&](long long res, int x) -> long long {
                return res + min(2 * m, x);
            });
}


int main()
{
    std::vector<int> basket1{4, 2, 2, 2}, basket2{1, 4, 1, 2};
    std::cout << minCost(basket1, basket2) << std::endl;
    return 0;
}
