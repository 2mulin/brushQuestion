/**
 * @date 2022/8/7
 * @author 2mu
 * @brief easy 爬楼梯的最少成本
 *
 * 1. dp
 * 题目给一个数组，里面是每一层的cost，花费cost，就能前往下一层，或者下两层。起始点可以从idx=0或者idx=1的位置出发。
 * 
 * 使用一个dp数组，保存到第i点所需的最小花费。那么dp[i] = min(dp[i-1] + cost[i+1], dp[i-2] + cost[i+1]) 
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 2. 空间优化
 * 
 * 使用滚动数组
 */

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    size_t sz = cost.size();
    // 可以站在0，1任选一个起点，所以到达起点开销为0
    int a = 0;
    int b = 0;
    int ans;
    for(int i = 2; i < sz+1; ++i)
    {
        ans = min(a + cost[i-2], b + cost[i-1]);
        a = b;
        b = ans;
    }
    return ans;
}

int main()
{
    return 0;
}
