/**
 * @date 2023/9/15
 * @author 2mu
 * @brief easy 宝石补给
 *
 * 1. 模拟
 * 挺简单的, 按照题目模拟即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int giveGem(vector<int> &gem, vector<vector<int>> &operations)
{
    for(auto& operation : operations)
    {
        int x = operation[0], y = operation[1];
        int cnt = gem[x] / 2;
        gem[x] -= cnt;
        gem[y] += cnt;
    }

    int maxVal = gem.front(), minVal = gem.front();
    for(auto cnt : gem)
    {
        maxVal = std::max(maxVal, cnt);
        minVal = std::min(minVal, cnt);
    }
    return maxVal - minVal;
}

int main()
{
    vector<int> gem{3, 1, 2};
    std::vector<std::vector<int>> operation{{0,2}, {2,1}, {2,0}};
    std::cout << giveGem(gem, operation) << std::endl;
    return 0;
}
