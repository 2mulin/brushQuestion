/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/17
 * @brief medium 三角形路径最小值
 * 1. 暴力，深搜得到所有的可能值。显而易见深搜是过不了的
 * 算N层，时间复杂度：O(2^N-1)        空间复杂度；O(N*N)
 * 
 * 2. 暴力，从下往上，本地没事，leetcode heap溢出，
 * 
 * 2. 动态规划
 * 从上往下走，dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j].
 * 注意边界（最左边一列和最右边一列）
 * 时间复杂度:O(N*N)      空间复杂度:O(N*N)
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// dp
int minimumTotal(vector<vector<int>>& triangle)
{
    // dp[i][j]表示triangle[0][0]到triangle[i][j]的最短路径和
    vector<vector<int>> dp(1, vector<int>(1,triangle[0][0]));
    for(int i = 1; i < triangle.size(); i++)
    {// 行
        vector<int> arr(i + 1, 0);
        for(int j = 0; j <= i; j++)
        {// 列
            if(j == 0)
            {// 最左边一列
                arr[j] = dp[i - 1][j] + triangle[i][j];
            }
            else if(j == i)
            {// 最右边一列
                arr[j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                arr[j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
        dp.push_back(arr);
    }
    int n = dp.size() - 1;
    int minVal = INT_MAX;
    for(int i = 0; i <= n; i++)
    {
        minVal = minVal > dp[n][i] ? dp[n][i] : minVal;
    }
    return minVal;
}


/* 从下往上搜
int minSum = INT_MAX;

void dfs(vector<vector<int>>& triangle, int x, int y, int sum)
{
    if(x == y && x == 0)
    {
        sum += triangle[x][y];
        if(minSum > sum)
            minSum = sum;
        return;
    }
    if(y < triangle[x].size())
        dfs(triangle, x - 1, y, sum + triangle[x][y]);
    if(y - 1 >= 0)
        dfs(triangle, x - 1, y - 1, sum + triangle[x][y]);
    return;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    size_t n = triangle.size();
    // 最后一行往上搜
    for(int i = 0; i < n; i++)
    {
        dfs(triangle, n - 1, i, 0);
    }
    return minSum;
}
 */
/* 暴力，直接深搜
int minSum = INT_MAX;

void dfs(const vector<vector<int >> &triangle, int x, int y, int sum)
{
    if (x == triangle.size())
    { // 递归基
        if (sum < minSum)
            minSum = sum;
        return;
    }
    sum += triangle[x][y];
    dfs(triangle, x + 1, y, sum);
    dfs(triangle, x + 1, y + 1, sum);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    // 暴力，得到所有可能的路径
    dfs(triangle, 0, 0, 0);
    return minSum;
}
 */

int main()
{
    vector<vector<int>> arr;
    arr.push_back(vector<int>{2});
    arr.push_back(vector<int>{3,4});
    arr.push_back(vector<int>{6,5,7});
    arr.push_back(vector<int>{4,1,8,3});
    cout << minimumTotal(arr) << endl;
    return 0;
}