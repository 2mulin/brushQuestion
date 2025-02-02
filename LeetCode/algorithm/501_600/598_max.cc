/**
 * @date 2025/2/2
 * @author 2mu 
 * @brief medium 区间加法
 * 
 * 1. 模拟
 * 最简单的方法，先按照规则把所有加法都做完，然后遍历一遍看看找最大值。
 * 那么还需要确认最大值是多少... 再去查询最大值有多少个
 * 
 * 仔细想想，最大值一定是左上角这个值，所以不需要去找最大值是多少，减少一次遍历。
 * 
 * 时间复杂度：O(m*n)  空间复杂度：O(m*n)
 * 
 * 2. 只判断ops横坐标纵坐标最小值
 * 简单模拟会超过内存限制，因为数组元素太多了。
 * 
 * 仔细想想实际上只需要判断ops数组中出现过的最小横坐标和最小纵坐标即可。
 * 然后ops数组元素个数就是最大值。
 * 
 * 根据最小横坐标和最小纵坐标就可以判断出有多少个最大值。
 * 
 * 时间复杂度：O(n)    空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int maxCount(int m, int n, vector<vector<int>> &ops)
{
    if (ops.empty())
        return m * n;
    int min_row = INT_MAX, min_col = INT_MAX;
    for(auto op : ops)
    {
        min_row = std::min(op[0], min_row);
        min_col = std::min(op[1], min_col);
    }
    return min_row * min_col;
}

/**
int maxCount(int m, int n, vector<vector<int>> &ops)
{
    std::vector<std::vector<int>> tmp(m, std::vector<int>(n, 0));
    for (auto op : ops)
    {
        for(int i = 0; i < op[0]; ++i)
        {
            for(int j = 0; j < op[1]; ++j)
            {
                ++tmp[i][j];
            }
        }
    }
    int max_value = tmp[0][0], result = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (tmp[i][j] == max_value)
             ++result;
        }
    }
    return result;
}
*/


int main()
{
    std::vector<std::vector<int>> ops{{2, 2}, {3, 3}};
    std::cout << maxCount(3, 3, ops) << std::endl;
    return 0;
}
