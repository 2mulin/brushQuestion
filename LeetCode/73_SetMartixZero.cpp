/**********************************************
 * @author reddragon
 * @date 2020/7/28
 * @brief 矩阵置0 medium
 * 主要是题目限制空间复杂度为O(1)
 **********************************************/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// 记录下来会变成全0的行和列。时间O(m*n) 空间O(m+n)
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return;
    int col = matrix[0].size();
    // 记录row或者col为全0
    vector<bool> rows(row, false);
    vector<bool> cols(col, false);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!matrix[i][j])
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (rows[i])
        {
            for (int j = 0; j < col; j++)
                matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < col; i++)
    {
        if (cols[i])
        {
            for (int j = 0; j < row; j++)
                matrix[j][i] = 0;
        }
    }
    return;
}

// 将会变成0的位置非0整数设置为一个没有用到的数字作为标记。时间O(m*n) 空间O(1)
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return;
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!matrix[i][j])
            {
                for (int k = 0; k < col; k++)
                {
                    if (matrix[i][k])
                        matrix[i][k] = -999999;
                }

                for (int k = 0; k < row; k++)
                {
                    if (matrix[k][j])
                        matrix[k][j] = -999999;
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -999999)
                matrix[i][j] = 0;
        }
    }
    return;
}

int main()
{
    return 0;
}