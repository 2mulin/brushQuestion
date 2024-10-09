/*************************************************************
 * @author reddragon
 * @date 2020/7/20
 * @brief medium 螺旋矩阵
 * 
 * 二刷
 * 和螺旋矩阵I差不多，还比I容易，因为这里就是正方形矩阵
 * 注意控制四个循环就行了
 * 时间复杂度: O(N*N)   空间复杂度: O(1)
 *************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> arr(n, vector<int>(n, 0));
    if (n == 1)
    {
        arr[0][0] = 1;
        return arr;
    }
    int num = 1;
    int left = 0, top = 0;
    int right = n - 1, button = n - 1;
    while (num <= n * n)
    {
        for (int i = left; i <= right; ++i)
            arr[top][i] = num++;
        for (int i = top + 1; i <= button; ++i)
            arr[i][right] = num++;
        for (int i = right - 1; i > left; --i)
            arr[button][i] = num++;
        for (int i = button; i > top; --i)
            arr[i][left] = num++;
        ++left;
        --right;
        ++top;
        --button;
    }
    return arr;
}

// vector<vector<int>> generateMatrix(int n)
// {
//     vector<vector<int>> ans(n, vector<int>(n));
//     int count = 1;
//     int up = 0, down = n - 1;
//     int left = 0, right = n - 1;
//     while (count <= n * n)
//     {
//         // up
//         for (int i = left; i <= right; i++)
//             ans[up][i] = count++;
//         // right
//         for (int i = up + 1; i < down; i++)
//             ans[i][right] = count++;
//         if (up < down)
//         {
//             // down
//             for (int i = right; i >= left; i--)
//                 ans[down][i] = count++;
//             // left
//             for (int i = down - 1; i > up; i--)
//                 ans[i][left] = count++;
//         }
//         left++;
//         right--;
//         up++;
//         down--;
//     }
//     return ans;
// }

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