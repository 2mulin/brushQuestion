/*******************************************************************************
 * @author reddragon
 * @date 2020/8/10
 * @brief medium hard
 * 最目前为为止最难的一题，需要把问题拆分，就可以使用84题的思路
 * 1. 暴力法。两点确定一个矩形，找出所有的矩形，判断每个矩形是否合法，最终得到最大
 * 的矩形。
 * 2. 利用一个辅助数组arr，arr[i][j]表示正上方最多有多少个连续的‘ 1 ’。就可以
 * 将问题转化为84题那样的柱状图最大矩形的子问题。然后利用84题的解法就可以解决了
 * 时间复杂度：O(M*M*N)     空间复杂度：O(MN)
 * 
 * 利用单调栈可以优化到 O(MN)
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 将问题转化为84题那样的柱状图最大矩形的子问题。然后利用84题的解法就可以了
int maximalRectangle(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return 0;
    int col = matrix[0].size();

    // 辅助数组,记录当前点为底边，高度最大为多少
    vector<vector<int>> arr(row,vector<int>(col));

    // 初始化第一行
    for(int i = 0; i < col; i++)
        if(matrix[0][i] == '1')
            arr[0][i] = 1;

    for(int i = 1; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] == '1')
                arr[i][j] = arr[i - 1][j] + 1;
            else
                arr[i][j] = 0;
        }
    }

    //vector<int> left(col),right(col);
    int ans = 0;
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int left = j, right = j;
            while (left >= 0 && arr[i][j] <= arr[i][left])
                left--;
            while(right < col && arr[i][j] <= arr[i][right])
                right++;
            ans = max(ans,arr[i][j] * (right - left - 1));
        }
    }
    return ans;
}

// 辅助函数，给两个点，检测是否是矩形 O(n*m)
// bool isRectangle(vector<vector<char>> &matrix, int x1, int y1, int x2, int y2)
// {
//     for (int i = x1; i <= x2; i++)
//     {
//         for (int j = y1; j <= y2; j++)
//             if (matrix[i][j] == '0')
//                 return false;
//     }
//     return true;
// }

// // 暴力，O(n的3次方*m的3次方)
// int maximalRectangle(vector<vector<char>> &matrix)
// {
//     int row = matrix.size();
//     if (row == 0)
//         return 0;
//     int col = matrix[0].size();
//     int ans = 0;
//     // 暴力，两个点可以确定一个矩形
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         { // 以当前点(i,j)为左上角，遍历一遍，就知道以他为起点的矩形面积最大有多大了
//             for (int k = i; k < row; k++)
//             {
//                 for (int l = j; l < col; l++)
//                 { // 以当前点(k,l)为右下角
//                     if (isRectangle(matrix, i, j, k, l))
//                         ans = max(ans, (k - i + 1) * (l - j + 1));
//                 }
//             }
//         }
//     }
//     return ans;
// }



int main()
{
    vector<vector<char>> arr{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(arr) << endl;
    return 0;
}