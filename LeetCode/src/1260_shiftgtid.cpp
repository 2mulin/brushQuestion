/**
 * @date 2022/7/20
 * @author 2mu
 * @brief easy 二维网格迁移
 *
 * 1. 模拟
 * 按照“迁移”的要求做就行了吧，先试一下。
 * 
 * 一定要注意迁移的先后顺序。避免元素值被覆盖。
 * 
 * 时间复杂度：O(M*N*K)
 * 空间复杂度：O(N)
 * 
 * 2. 一维展开
 * 多尝试几个，你就会发现将二维数组转化为一维数组后，每次迁移，实际上就是做一次数组循环右移。
 * 
 * 时间复杂度：O(M*N)
 * 空间复杂度：O(N)
 * 
 * 反思：数组操作实际工作也非常常见，而且也算是我做的非常多题目之一了，但是每次都会做错，为什么呢？
 * 
 * 没有形成方法论，都是很有方法的，
 * 1. 这里原地操作数组赋值的时候，一定要反着来，避免覆盖刚设置的正确的值。
 * 2. 二维数组转化为一维数组，大学到现在最常见的题目，还能错？ row行col列二维数组：arr[i][j] = arr[i*col + j]
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int row = grid.size(), col = grid[0].size();
    std::vector<int> vecNums(row * col);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            vecNums[i*col + j] = grid[i][j];
        }
    }
    std::vector<int> vecNumsCopy = vecNums;
    size_t len = vecNums.size();
    for(size_t i = 0; i < len; ++i)
    {
        int Idx = (i + k) % len;
        vecNums[Idx] = vecNumsCopy[i];
    }

    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            grid[i][j] = vecNums[i*col + j];
        }
    }
    return grid;
}

/*
void TransferGrid(std::vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    // 暂时保存最后一列的值
    std::vector<int> endCol(row, 0);
    for (int i = 0; i < row; ++i)
        endCol[i] = grid[i][col - 1];

    for (int i = 0; i < row; ++i)
    {
        // 只能从后往前赋值，否则会被覆盖。
        for (int j = col - 1; j > 0; --j)
            grid[i][j] = grid[i][j - 1];
    }
    for (int i = row - 1; i > 0; --i)
        grid[i][0] = endCol[i - 1];
    grid[0][0] = endCol[row - 1];
}

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    while (k--)
    {
        TransferGrid(grid);
    }
    return grid;
}
*/

int main()
{
    std::vector<std::vector<int>> arr{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    arr = shiftGrid(arr, 1);
    for(auto vec : arr)
    {
        for(auto val : vec)
            std::cout << val << ' ';
        std::cout << std::endl;
    }

    arr = {{1},{4},{7}};
    arr = shiftGrid(arr, 1);
    for(auto vec : arr)
    {
        for(auto val : vec)
            std::cout << val << ' ';
        std::cout << std::endl;
    }
    return 0;
}
