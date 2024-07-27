/**
 * @date 2023/9/16
 * @author 2mu
 * @brief medium 打家劫舍
 *
 * 1. dp
 * 印象中已经做过这一题了, 再做一次; 要求是不能偷两个相邻的房间;
 * 假设第i个房间的现金数是 nums[i], 假设nums数组长度为len, 
 * 再设置一个dp数组, dp[i]表示nums长度为i + 1(<= len)时, 且**nums[i]必偷**, 最多能偷到的现金数;
 * 
 * 状态转化: i=0, dp[i] = nums[0]
 *          i=1, dp[i] = nums[1]
 *          i=2, dp[i] = nums[0] + nums[i]
 *          i>=3, dp[i] = max(dp[i-3] + nums[i], dp[i-2] + nums[i])
 * 
 * 最终答案就是 max(dp[len - 1], dp[len - 2], dp[len - 3])
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. 官方题解 dp
 * 
 * 官方题解dp思路更加清晰, 看我下次能否想起来 所以说dp写得好不好, 就看状态解析方程好不好...
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
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    for(int i = 3; i < len; ++i)
    {
        dp[i] = std::max(dp[i - 3] + nums[i], dp[i - 2] + nums[i]);
    }
    int ans = std::max(dp[len - 1], dp[len - 2]);
    ans = std::max(ans, dp[len - 3]);
    return ans;
}

int main()
{

    return 0;
}
