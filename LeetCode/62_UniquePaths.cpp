/**********************************************
 * @author reddragon
 * @date 2020/7/23
 * @brief 深搜+记忆化搜索
 * 这是比较简单的搜索。如果不用记忆化，会超时。
 * 每次格子的值是确定的，不要重复搜索
 **********************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DFS(int m, int n, int x, int y, vector<vector<int>> &arr)
{
    int ans = 0;
    if (x == m && y == n)
        return 1;
    else
    {
        if (x + 1 <= m)
        {
            if (arr[x + 1][y])
                ans += arr[x + 1][y];
            else
                ans += DFS(m, n, x + 1, y, arr);
        }
        if (y + 1 <= n)
        {
            if (arr[x][y + 1])
                ans += arr[x][y + 1];
            else
                ans += DFS(m, n, x, y + 1, arr);
        }
    }
    arr[x][y] = ans;
    return ans;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
    return DFS(m, n, 1, 1, arr);
}

int main()
{
    cout << 2 % 3;
    return 0;
}