/**
 * @date 2024/7/5
 * @author 2mu
 * @brief easy 修改矩阵
 *
 * 1. 遍历一遍
 * 先创建额外变量, 记录一列的最大值; 再创建一个数组, 记录该列有哪些位置是-1
 * 开始遍历矩阵, 从第一列, 第二列开始遍历...每遍历完一列, 找到-1位置, 再将-1替换为该列最大值;
 * 
 * 时间复杂度: O(m*n)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
{
    std::vector<int> row_pos;
    int row = matrix.size(), col = matrix[0].size();
    std::vector<std::vector<int>> answer(row, std::vector<int>(col, 0));

    for(int j = 0; j < col; ++j)
    {
        int max_val = -1;
        for(int i = 0; i < row; ++i)
        {
            if(matrix[i][j] == -1)
            {
                row_pos.push_back(i);
                continue;
            }
            max_val = std::max(max_val, matrix[i][j]);
            answer[i][j] = matrix[i][j];
        }
        
        for(auto x : row_pos)
        {
            answer[x][j] = max_val;    
        }
        row_pos.clear();
    }
    return answer;
}

int main(int argc, char **argv)
{
    return 0;
}

