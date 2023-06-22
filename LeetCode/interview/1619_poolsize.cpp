/**
 * @date 2023/6/22
 * @author 2mu
 * @brief medium 水域大小
 *
 * 1. bfs
 * 遍历这个数组, 当发现0的时候, 表示这是个水域, 同时搜索它的四面八方, 确认是否
 * 有相连的0, 标记为访问过; 最后排序, 返回结果
 * 
 * 时间复杂度: O(m*n + nlogn)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 任意一点的其后左右8个方向
int dir[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};

int _calSize(const std::vector<std::vector<int>> &land, std::vector<std::vector<bool>>& vctVisited, int i, int j)
{
    vctVisited[i][j] = true;
    if(land[i][j])
        return 0;

    int poolSize = 0;
    std::queue<std::pair<int, int>> que;
    que.push({i, j});
    while(!que.empty())
    {
        std::pair<int, int> currentPoint = que.front();
        int x = currentPoint.first, y = currentPoint.second;
        que.pop();
        ++poolSize;
        for(int k = 0; k < 8; ++k)
        {
            int newX = dir[k][0] + x, newY = dir[k][1] + y;
            if(newX >= 0 && newY >= 0 && newX < land.size() && newY < land[0].size()
                && !vctVisited[newX][newY] && land[newX][newY] == 0)
            {
                que.push({newX, newY});
                vctVisited[newX][newY] = true;
            }
        }
    }
    return poolSize;
}

std::vector<int> pondSizes(vector<vector<int>> &land)
{
    size_t n = land.size();
    size_t m = land[0].size();
    std::vector<std::vector<bool>> vctVisited(n, std::vector<bool>(m, false));

    std::vector<int> ans;
    for(size_t i = 0; i < n; ++i)
    {
        for(size_t j = 0; j < m; ++j)
        {
            if(vctVisited[i][j] == false && land[i][j] == 0)
            {
                int sz = _calSize(land, vctVisited, i, j);
                ans.push_back(sz);
            }
            vctVisited[i][j] = true;
        }
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    std::string s = "abcda";
    std::vector<std::vector<int>> land{
        {0, 2, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1}
    };
    auto ans = pondSizes(land);
    for(auto elem : ans)
        std::cout << elem << '\t';
    return 0;
}