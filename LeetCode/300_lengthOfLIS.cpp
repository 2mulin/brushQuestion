/********************************************************************************************
 * @author reddragon
 * @date 2020/11/13
 * @brief medium 最长上升子序列
 * 
 * 最暴力的方法就是枚举所有的可能，但是时间复杂度很高O(N!)
 * 
 * 1. 动态规划
 * 定义dp[i]以第i个元素为终点的最长上升子序列的长度。
 * 状态转移方程
 *      dp[i] = max(dp[j] + 1, 其中0 <= j < i且nums[j] < nums[i]), 其中j是i前面的任何一个
 * 每次for循环从前往后找最大值
 * 时间复杂度：O(N*N)           空间复杂度：O(N)
 * 
 * 2. 贪心+二分查找
 * 
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int len = nums.size();
    vector<int> dp(len, 0);// dp[i]表示以i为终点的最大上升子序列的长度。
    dp[0] = 1;
    for(int i = 1; i < len; ++i)
    {
        int maxLen = 1;
        // 确定dp[i], 将i前面所有的dp[]中找到最大值
        for(int j = 0; j < i; ++j)
        {
            if(nums[i] > nums[j])
                maxLen = max(maxLen, dp[j] + 1);
        }
        dp[i] = maxLen;
    }
    int ans = 0;
    for(int i = 0; i < len; ++i)
        ans = max(ans, dp[i]);
    return ans;
}

int main()
{
    vector<int> arr{10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(arr) << endl;
    return 0;
}