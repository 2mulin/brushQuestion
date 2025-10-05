/**
 * @date 2025/10/5
 * @author 2mu
 * @brief medium 太平洋太西洋水流问题
 *
 * 1. BFS
 * 搜索的思路很容易想到，主要是代码编写。因为搜索过程中需要同时考虑高度，以及单元格的传递性。
 * 
 * 官方题解的思路就比较棒，我自己想的不行。题解分为两个搜索步骤，先搜索到大西洋的所有格子。
 * 再搜索到太平洋的所有格子，这样代码写起来就会相对简单些。
 *
 * 时间复杂度：O(m*n)
 * 空间复杂度: O(m*n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


static const std::vector<std::vector<int>> direction = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};


void bfs(int row, int col, vector<vector<bool>>& ocean, const vector<vector<int>> &heights)
{
    if (ocean[row][col])
        return;
    
    // 用户调用该函数传进来的入口参数一定是合法的
    ocean[row][col] = true;
    
    int m = heights.size();
    int n = heights[0].size();
    queue<pair<int, int>> que;
    que.emplace(row, col);

    while(!que.empty())
    {
        row = que.front().first;
        col = que.front().second;
        que.pop();

        for(int i = 0; i < direction.size(); ++i)
        {
            int newRow = row + direction[i][0], newCol = col + direction[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol])
            {
                ocean[newRow][newCol] = true;
                que.emplace(newRow, newCol);
            }
        }
    }
}


vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        bfs(i, 0, pacific, heights);
    }
    for (int j = 1; j < n; j++)
    {
        bfs(0, j, pacific, heights);
    }

    for (int i = 0; i < m; i++)
    {
        bfs(i, n - 1, atlantic, heights);
    }
    for (int j = 0; j < n - 1; ++j)
    {
        bfs(m - 1, j, atlantic, heights);
    }

    vector<vector<int>> result;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                result.push_back({i, j});
            }
        }
    }
    return result;
}


int main()
{
    std::vector<std::vector<int>> heights = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}};
    std::vector<std::vector<int>> tuples = pacificAtlantic(heights);
    for(auto tuple : tuples)
    {
        for(auto num : tuple)
        {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
