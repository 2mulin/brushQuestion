/********************************************************************************************
 * @author reddragon
 * @date 2021/3/17
 * @brief hard 不同的子序列
 * 
 * 1. 枚举
 * 每一个元素只有两种状态, 选或不选.
 * 使用枚举尝试过了, 超时
 * 时间复杂度: O(2的N次方)N是字符串长度         空间复杂度: O(1)
 * 
 * 2. 动态规划
 * 主要是找到状态转移方程, 找到之后就容易了
 * 使用二维数组, dp[i][j] 表示s[i]对应的t[j]的子序列个数
 * 当s[i] == t[i]时
 *      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
 * else
 *      dp[i][j] = dp[i - 1][j];
 * 时间复杂度: O(mn)                    空间复杂度:O(mn)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 动态规划
int numDistinct(string s, string t)
{
    if (s.empty() || s.size() < t.size())
        return 0;
    long long row = s.size(), col = t.size();
    vector<vector<long long>> dp(row + 1, vector<long long>(col + 1, 0));
    // 0行表示s为空, 0列表示t为空
    for (int i = 0; i <= row; ++i)
        dp[i][0] = 1; // 空串就是字串
    // dp
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[row][col];
}

// 枚举
/* int numDistinct(string s, string t)
{
    if(t.empty())
        return 1;
    if(s.empty() || s.size() < t.size())
        return 0;
    // 枚举: 每一个元素都是可选可不选两种状态
    int ans = 0;
    // 不选
    ans += numDistinct(s.substr(1), t);
    // 选
    if (s[0] == t[0])
        ans += numDistinct(s.substr(1), t.substr(1));
    return ans;
} */

int main()
{
    cout << numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
