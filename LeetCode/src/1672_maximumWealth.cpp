/**
 * @author ling
 * @date 2021/4/14
 * @brief easy 最富有客户的资产总量
 *
 * 1. 二维数组求一行和的最大值
 * 暴力解法，直接将一行数加起来。
 * 时间复杂度: O(N*N)         空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int maximumWealth(vector<vector<int>>& accounts) 
{
    int ans = INT_MIN;
    for(int i = 0; i < accounts.size(); ++i)
    {
        int rowSum = 0;
        for(int j = 0; j < accounts[i].size(); ++j)
        {
            rowSum += accounts[i][j];
        }
        ans = rowSum > ans ? rowSum : ans;
    }
    return ans;
}

int main()
{
    return 0;
}
