/**
 * @date 2023/7/27
 * @author 2mu
 * @brief easy 删除每行中的最大值
 * 
 * 1. 冒泡
 * 直接采用遍历, 每次遍历一行, 找到该行最大值, 并移动到改行末尾(类似冒泡)
 * 
 * 看题解: 直接先将每一行排序, 然后再遍历搜索最大值; 时间复杂度O(n*n*logn)差不多, 我就不改了; 
 * 
 * 时间复杂度: O(n*n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int deleteGreatestValue(vector<vector<int>> &grid)
{
    if(grid.empty())
        return 0;
    int ans = 0;
    while(!grid.front().empty())
    {
        int colMaxVal = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            std::vector<int>& currLine = grid[i];
            // 遍历该行最大值
            for(int j = 0; j < currLine.size() - 1; ++j)
            {
                if(currLine[j] > currLine[j + 1])
                {
                    std::swap(currLine[j], currLine[j + 1]);
                }
            }
            colMaxVal = std::max(colMaxVal, currLine.back());
            currLine.pop_back();
        }
        ans += colMaxVal;
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int> > grid{{1,2,4}, {3,3,1}};
    std::cout << deleteGreatestValue(grid) << std::endl;
    return 0;
}
