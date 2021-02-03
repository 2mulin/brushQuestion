/***************************************************************************
 * @date 2020/7/6
 * @author reddragon
 * @description: medium 不同路径2
 * 
 * 暴力法: 借助队列实现的BFS  时间复杂度O(nm)，空间复杂度O(1)
 * 
 * 动态规划：显而易见，dp[i][j]表示到达点（i，j）的路径条数
 * 状态转移方程：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 * 注意判断边界和障碍物
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int row = obstacleGrid.size();
    if (row == 0 || obstacleGrid[0][0])
        return 0;
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1;

    // 第一行遍历
    for (int i = 1; i < col; i++)
        if (!obstacleGrid[0][i])
            dp[0][i] = dp[0][i - 1];
    // 第一列遍历
    for (int i = 1; i < row; i++)
        if (!obstacleGrid[i][0])
            dp[i][0] = dp[i - 1][0];

    // dp遍历
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (!obstacleGrid[i][j])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}

/*****************************************************************
 * 暴力法：直接bfs。直接超时
struct site
{
    int x;
    int y;
    site(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int row = obstacleGrid.size();
    if(row == 0 || obstacleGrid[0][0])
        return 0;
    int col = obstacleGrid[0].size();
    queue<site> qu;
    int ans = 0;
    qu.push(site(0,0));
    while (!qu.empty())
    {
        site s = qu.front();
        qu.pop();
        if (s.x == row - 1 && s.y == col - 1)
        {
            ans++;
            continue;
        }
        if (s.x + 1 < row && !obstacleGrid[s.x + 1][s.y])
            qu.push(site(s.x + 1, s.y));
        if (s.y + 1 < col && !obstacleGrid[s.x][s.y + 1])
            qu.push(site(s.x, s.y + 1));
    }
    return ans;
}
****************************************************************************/
int main()
{
    vector<vector<int>> nums{{0, 0, 0}};
    cout << uniquePathsWithObstacles(nums);
    return 0;
}
