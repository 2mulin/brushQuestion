/**
 * @date 2022/10/7
 * @author 2mu
 * @brief easy 最大升序子数组和
 *
 * 一. dp
 * 首先需要确定子数组的定义是什么，题意表示子数组是连续的。
 * 那么显然可以使用动态规划：
 * 创建一个dp数组，dp[i]表示当前nums从0~i的数，最大升序子数组和，设sum表示当前统计的连续子数组和(随着i的移动，时时更新)。
 * 状态转移方程：
 *  dp[i] = max(dp[i - 1]， sum) 
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 
 * 二. 滚动数组优化空间
 * 由于状态转移过程只和上一个状态相关，所以使用两个变量替代数组。可以节省空间。
 */

#include <iostream>
#include <vector>
#include <algorithm>

int maxAscendingSum(std::vector<int> &nums)
{
    int sum = nums[0];
    std::vector<int> dp(nums);
    int ans = sum;
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i - 1] < nums[i])
            sum += nums[i];
        else
            sum = nums[i];
        int maxVal = std::max(dp[i - 1], sum); 
        ans = std::max(maxVal, ans);
    }
    return ans;
}

int main()
{
    std::vector<int> arr{10,20,30,5,10,50};
    std::cout << maxAscendingSum(arr) << std::endl;
    return 0;
}
