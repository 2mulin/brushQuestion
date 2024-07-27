/**
 * @date 2022/3/16
 * @author 2mu
 * @brief medium 最大网络秩
 *
 * 一、枚举
 * 2 <= n <= 100，可以发现实际上城市数量并不多，因此这种涉及 图 遍历的数据结构
 * 可以考虑使用邻接矩阵，邻接矩阵虽然浪费空间，但是代码清晰易懂
 * 
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(n*n)
 * 
 * 二、贪心
 * 
 * 显然，拥有最大秩的城市对 他们的 度 应该是最大的（第一大和第二大，或者两者都是最大）
 * 可以缩小范围。
 * 
 * 多个城市的秩可能相等，所以代码计算 秩最大 和 次大 的程序不太好实现。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    // 最后一列记录城市的秩
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n + 1, 0));
    for(size_t i = 0; i < roads.size(); ++i)
    {
        int city1 = roads[i][0], city2 = roads[i][1];
        matrix[city1][city2] = 1;
        matrix[city2][city1] = 1;

        matrix[city1][n] += 1;
        matrix[city2][n] += 1;
    }

    // 也就是 n*n - 100 种组合可能，所有组合的 秩 都计算出来，用最大的就行。

    int ans = 0;
    for(size_t i = 0; i < n - 1; ++i)
    {
        for(size_t j = i + 1; j < n; ++j)
        {
            int degree = matrix[i][n] + matrix[j][n];
            if(matrix[i][j] == 1)
                --degree;
            ans = std::max(ans, degree);
        }
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> roads{ 
        {0,1},{1,2},{2,3},{2,4},{5,6},{5,7}
    };
    std::cout << maximalNetworkRank(8, roads) << std::endl;

    roads = { 
        {0,1},{0,3},{1,2},{1,3},{2,3},{2,4}
    };
    std::cout << maximalNetworkRank(5, roads) << std::endl;
    return 0;
}
