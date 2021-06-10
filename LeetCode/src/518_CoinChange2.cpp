/**
 * @author ling
 * @date 2021/6/10
 * @brief medium 零钱兑换II
 * 
 * 1. 递归（超时）
 * 尝试每一种找零钱的方法. 每次两个选择, 1. 使用当前数字, 2. 不使用当前数字, idx++
 * 这样就可以尝试所有的方法。
 * 时间复杂度：O(N^N)           空间复杂度：O(递归深度)
 * 
 * 2. 完全背包问题
 * 定义一个dp数组，dp[i][j]表示coins数组的前i个硬币能组成j的种类数。
 * 状态转移方程。
 * 1. 在dp[i][j]中，如果不选择当前coins[i]，那么dp[i][j] = dp[i-1][j]。
 * 2. 在dp[i][j]中，如果选择当前coins[i], 
 *    使用1次：那么dp[i][j] = dp[i-1][j - coins[i] ]
 *    使用2次: 那么dp[i][j] = dp[i-1][j - coins[i]* 2]
 *    使用3次: 那么dp[i][j] = dp[i-1][j - coins[i]* 3]
 *    ...
 * 
 *    下面程序不是这样的
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 动态规划解法
 */
int change(int amount, vector<int>& coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for(auto coin : coins)
    {
        for(int i = coin; i <= amount; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

/* 
int dfs(int amount, const vector<int> &coins, int idx)
{
    if (amount == 0)
        return 1;
    else if (amount < 0 || idx == coins.size())
        return 0;
    else
    {
        int sum = 0;
        sum += dfs(amount - coins[idx], coins, idx);
        sum += dfs(amount, coins, idx + 1);
        return sum;
    }
}

// 枚举
int change(int amount, vector<int> &coins)
{
    if (coins.empty())
        return 0;
    return dfs(amount, coins, 0);
}

*/

int main()
{
    vector<int> coins{1, 2, 5};
    cout << change(5, coins) << endl;
    return 0;
}