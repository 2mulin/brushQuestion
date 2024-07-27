/**
 * @date 2022/6/14
 * @author 2mu
 * @brief medium 对角线遍历
 *
 * 1. 模拟
 * 从左上角开始，走Z字。就是直接模拟走Z字。难点在于判断边界条件，以及到达边界进行转向。
 * 我使用偷懒的方法，全部按右上往左下走，记录下来。处理边界条件简单。最后合成结果时，将一半斜线反过来记录。
 * 
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    size_t rowNum = mat.size(), colNum = mat[0].size();
    vector<vector<int>> my_mat(rowNum + colNum - 1, vector<int>());
    int idx = 0;
    // 不按z字走，全部按右上往左下走。最后处理Z字。
    // 起点：第一行和最后一列
    for(size_t i = 0; i < colNum - 1; ++i)
    {
        int row = 0, col = i;
        while(row < rowNum && col >= 0)
        {
            my_mat[idx].push_back(mat[row][col]);
            ++row;
            --col;
        }
        ++idx;
    }
    for(size_t i = 0; i < rowNum; ++i)
    {
        int row = i, col = colNum - 1;
        while(row < rowNum && col >= 0)
        {
            my_mat[idx].push_back(mat[row][col]);
            ++row;
            --col;
        }
        ++idx;
    }

    vector<int> result;
    for(size_t i = 0; i < my_mat.size(); ++i )
    {
        if(i % 2)
            result.insert(result.end(), my_mat[i].begin(), my_mat[i].end());
        else
            result.insert(result.end(), my_mat[i].rbegin(), my_mat[i].rend());
    }
    return result;
}

int main()
{
    std::vector<vector<int>> mat{
        {1,2,3},
        {4,5,6}
    };
    vector<int> ans = findDiagonalOrder(mat);
    for(auto val : ans)
        std::cout << val << '\t';
    std::cout << std::endl;
    return 0;
}
