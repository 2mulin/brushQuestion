/********************************************************************************************
 * @author reddragon
 * @date 2021/3/30
 * @brief medium 搜索二叉矩阵
 * 
 * 1，循环
 * 双重循环检查所有元素
 * 时间复杂度: O(m*n)           空间复杂度: O(1)
 * 
 * 2. 二分查找
 * 先写了个retVal函数将二维矩证的访问 变成 一维矩阵的访问
 * 时间复杂度: O(logM*N)        空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int retVal(const vector<vector<int>> &matrix, int idx)
{
    int row = idx / matrix[0].size();
    int col = idx % matrix[0].size();
    return matrix[row][col];
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int sz = matrix.size() * matrix[0].size();
    int low = 0, high = sz;
    while(low < high)
    {
        int mid = (high - low) / 2 + low;
        int val = retVal(matrix, mid);
        if(val > target)
            high = mid - 1;
        else if(val < target)
            low = mid + 1;
        else
            return true;      
    }
    return false;
}

/* 双重循环
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
} */

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    // for(int i = 0; i < 12; ++i)
    //     cout << retVal(vec, i);
    cout << searchMatrix(matrix, 50);
    return 0;
}