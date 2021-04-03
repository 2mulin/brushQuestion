/********************************************************************************************
 * @author reddragon
 * @date 2021/4/3
 * @brief medium 最长公共子序列
 * 
 * 1，二维动态规划
 * 最长公共子序列是经典的二维动态规划题目.
 * 解决这个问题通常的想法是找到两个string的所有子集，然后一一对比，找到最长的那个子集。
 * 显然这个复杂度无法接受， 2^n
 * 最好的办法还是dp，使用一个二维数组dp。
 * dp[i][j] 表示text1[0 ~ i] 和 text2[0 ~ j]的最长公共子序列
 * 状态转移方程：
 * 当text1[i] != text2[j]时
 *          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
 * 当text1[i] == text2[j]时
 *          dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), 1 + dp[i - 1][j - 1]);
 * 时间复杂度: O(M*N)        空间复杂度: O(M*N)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int row = text1.length();
    int col = text2.length();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1));
    for (int i = 0; i < row + 1; ++i)
        dp[i][0] = 0;
    for (int i = 0; i < col + 1; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
    }
    return dp[row][col];
}

int main()
{
    cout << longestCommonSubsequence("abc", "def") << endl;
    return 0;
}