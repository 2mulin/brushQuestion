/*************************************************************
 * @author reddragon
 * @date 2020/7/20
 * @brief midden
 * 和螺旋矩阵差不多，还跟容易，因为他是正方形矩阵
 * 注意控制四个循环就行了
 *************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    int count = 1;
    int up = 0, down = n - 1;
    int left = 0, right = n - 1;
    while (count <= n * n)
    {
        // up
        for (int i = left; i <= right; i++)
            ans[up][i] = count++;
        // right
        for (int i = up + 1; i < down; i++)
            ans[i][right] = count++;
        if (up < down)
        {
            // down
            for (int i = right; i >= left; i--)
                ans[down][i] = count++;
            // left
            for (int i = down - 1; i > up; i--)
                ans[i][left] = count++;
        }
        left++;
        right--;
        up++;
        down--;
    }
    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}