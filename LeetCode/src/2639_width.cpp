/**
 * @date 2023/4/27
 * @author 2mu
 * @brief easy 查询网格图中每一列的宽度
 *
 * 1. 简单思路
 * 遍历数组中的每一个数字, 每次遍历一列, 将每个数字转化为字符串, 求其长度;
 * 然后就可以统计一列数组的宽度;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findColumnWidth(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    std::vector<int> ans;
    for (int j = 0; j < col; ++j)
    {
        int max_len = 0;
        for (int i = 0; i < row; ++i)
        {
            int len = std::to_string(grid[i][j]).length();
            max_len = std::max(len, max_len);
        }
        ans.push_back(max_len);
    }
    return ans;
}

int main(int argc, char **argv)
{
    return 0;
}