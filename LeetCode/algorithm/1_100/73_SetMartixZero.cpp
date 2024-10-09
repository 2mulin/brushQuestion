/***********************************************************************
 * @author reddragon
 * @date 2020/7/28
 * @brief 矩阵置0 medium
 * 主要是题目限制空间复杂度为O(1)
 * 
 * 1.使用标记数组
 * 使用两个set, 分别记录下来需要变成0的行和列
 * 最后统一变成0
 * 时间复杂度: O(m*n)       空间复杂度: O(m+n)
 * 
 * 2.原地
 * 直接使用矩阵的第一行和第一列做标记. 如n行中有0
 * 那么标记matrix[n][0] = 0; n列中有0, 标记matrix[0][n] = 0;
 * 但是这里需要注意的是, 如果第一行或者第一列也有0
 * 我们不能使用matrix[0][0], 有歧义. 所以单独增加两个
 * 变量分别表示第一行和第一列是否有0
 * 时间复杂度: O(m*n)       空间复杂度: O(1)
 ************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 使用两个set分别存放当前需要变成0的row和col. 最后统一变成0
// 时间复杂度: O(m*n)       空间复杂度: O(m+n)
void setZeroes(vector<vector<int>> &matrix)
{
    set<int> rowflags;
    set<int> colflags;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                rowflags.insert(i);
                colflags.insert(j);
            }
        }
    }
    int row = matrix.size();
    int col = matrix[0].size();
    for (auto num : rowflags)
    {
        for (int i = 0; i < col; ++i)
            matrix[num][i] = 0;
    }
    for (auto num : colflags)
    {
        for (int i = 0; i < row; ++i)
            matrix[i][num] = 0;
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
    vector<vector<int>> vec{{1,1,1}, {1,0,1}, {1,1,1}};
    setZeroes(vec);
    for(auto arr : vec)
    {
        for(auto it : arr)
            cout << it << '\t';
        cout << endl;
    }
    return 0;
}