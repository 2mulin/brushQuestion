/**
 * @date 2022/7/12
 * @author 2mu
 * @brief easy 单元格中奇数的个数
 *
 * 1. 模拟
 * 按照要求进行累加，最后遍历一遍，根据奇偶，记录结果。
 * 
 * 时间复杂度：O(q * (m + n) + m * n), q为indices的大小。
 * 空间复杂度：O(M*N)
 * 
 * 2. 优化空间
 * 一个数组表示所有行，一个数组表示所有列。
 * 
 * 时间复杂度：O(m * n), N为indices的大小。
 * 空间复杂度：O(M + N)
 * 
 * 3. 优化计数
 * 看题解
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

// 暴力模拟
// void RowChange(vector<vector<int>>& nums, int row)
// {
//     for(size_t i = 0; i < nums[row].size(); ++i)
//     {
//         ++nums[row][i];
//     }
// }

// void ColChange(vector<vector<int>>& nums, int col)
// {
//     for(size_t i = 0; i < nums.size(); ++i)
//     {
//         ++nums[i][col];
//     }
// }

// int oddCells(int m, int n, vector<vector<int>> &indices)
// {
//     std::vector<std::vector<int>> nums(m, std::vector<int>(n, 0));
//     for(size_t i = 0; i < indices.size(); ++i)
//     {
//         int x = indices[i][0], y = indices[i][1];
//         RowChange(nums, x);
//         ColChange(nums, y);
//     }
//     int ans = 0;
//     for(size_t i = 0; i < m; ++i)
//     {
//         for(size_t j = 0; j < n; ++j)
//         {
//             if(nums[i][j] % 2)
//                 ++ans;
//         }
//     }
//     return ans;
// }

int oddCells(int m, int n, vector<vector<int>> &indices)
{
    std::vector<int> row(m, 0);
    std::vector<int> col(n, 0);

    for(size_t i = 0; i < indices.size(); ++i)
    {
        int x = indices[i][0], y = indices[i][1];
        ++row[x];
        ++col[y];
    }
    
    int ans = 0;
    for(size_t i = 0; i < m; ++i)
    {
        for(size_t j = 0; j < n; ++j)
        {
            if((row[i] + col[j]) % 2)
                ++ans;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
