/**
 * @date 2023/9/17
 * @author 2mu
 * @brief medium 打家劫舍II
 *
 * 1. dp
 * 印象中已经做过这一题了, 再做一次; 要求是不能偷两个相邻的房间;
 * 假设第i个房间的现金数是 nums[i], 假设nums数组长度为len, 
 * 再设置dp数组, dp[i]表示nums长度为i+1时, 最多能偷到的现金数;
 * 则状态转移方程:
 *      则 i = 0 时, dp[i] = nums[0]
 *         i = 1 时, dp[i] = max(nums[0], nums[1])
 *         i > 1 时, dp[i] = max(dp[i - 1],  dp[i - 2] + nums[i])
 * 
 * 由于有环, 以上方案用不了, 那能不能破解这个环? 可以的, 先忽视最后一个房间, 做一次dp; 然后忽视第一个房间, 做一次dp;
 * 然后两次dp中选取最大值, 就可以解决了;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int len = nums.size();
    if(len == 1)
        return nums[0];
    if(len == 2)
        return max(nums[0], nums[1]);
    std::vector<int> dp(len);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < len - 1; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int ans = dp[len - 2];
    // 再做一次dp, 这次不考虑nums[0]
    
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i = 3; i < len; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    ans = std::max(dp[len - 1], ans);
    return ans;
}

int main()
{
    std::vector<int> arr{1, 2, 3};
    std::cout << rob(arr) << std::endl;
    arr = {2, 3, 2};
    std::cout << rob(arr) << std::endl;
    return 0;
}
