/**********************************************
 * @author reddragon
 * @date 2020/7/24
 * @brief 最小路径和 miden
 * 动态规划。每次移动都和上方和左方两者的最小值有关
 * 时间复杂度：O(mn)   空间复杂度：O(mn)
 * 可以使用一维数组优化空间为 O(n)
 **********************************************/
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int ans = 0;
    int row = grid.size();
    if (row == 0)
        return 0;
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < col; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    for (int i = 1; i < row; i++)
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[row - 1][col - 1];
}

int main()
{
    return 0;
}