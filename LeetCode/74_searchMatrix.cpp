/**********************************************
 * @author reddragon
 * @date 2020/7/30
 * @brief 搜索二维矩阵 midden
 * 把二维数组视作一维数组，使用二分查找
 * 时间：O(logm*n) 空间：O(1)
 **********************************************/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// 把二维数组视作一维数组，使用二分查找
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    size_t row = matrix.size();
    if (row == 0)
        return false;
    size_t col = matrix[0].size();
    int low = 0, high = row * col - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int x = mid / col; // 第x行
        int y = mid % col; // 第y列

        if (matrix[x][y] > target)
            high = mid - 1;
        else if (matrix[x][y] < target)
            low = mid + 1;
        else
            return true;
    }
    return false;
}

// 暴力，全部遍历一遍
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     size_t row = matrix.size();
//     if (row == 0)
//         return false;
//     size_t col = matrix[0].size();
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (target == matrix[i][j])
//                 return true;
//         }
//     }
//     return false;
// }

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    cout << searchMatrix(matrix, 50);
    return 0;
}