/********************************************************************************************
 * @author reddragon
 * @date 2020/11/14
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
 * 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
 * 因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
 * 基于上面的贪心思路：我们维护一个数组d, d[i]表示nums数组最长上升子序列长度为i时，最末尾最小的数
 * 一次遍历数组nums的元素，并且更新数组d
 * 如果 nums[i] > d[i], maxLen++
 * 否则，在 d 数组中二分查找，找到第一个比 nums[i] 小的数 d[k] ，并更新 d[k+1] = nums[i]。
 * 以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：
 * 
 * 第一步插入 00，d = [0]d=[0]；
 * 第二步插入 88，d = [0, 8]d=[0,8]；
 * 第三步插入 44，d = [0, 4]d=[0,4]；
 * 第四步插入 1212，d = [0, 4, 12]d=[0,4,12]；
 * 第五步插入 22，d = [0, 2, 12]d=[0,2,12]。
 * 
 * 最终得到最大长度是3
 * 
 * 时间复杂度：O(NlogN)         空间复杂度: O(N)
 * 
 * 只有一个for循环，循环内部一个二分查找更新d数组，所以比动态规划好一些
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int lengthOfLTS(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int n = nums.size();
    int maxLen = 1;
    // d数组规定是一个单调递增数组
    vector<int> d(n + 1, 0);
    d[maxLen] = nums[0];
    for(int i = 1; i < n; ++i)
    {
        if(nums[i] > d[maxLen])
            d[++maxLen] = nums[i];// 大于，直接加进去
        else
        {
            // 二分查找，找到第一个最接近nums[i]却又比nums[i]大的元素，
            int left = 1, right = maxLen, pos = 0;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(d[mid] < nums[i])
                {
                    pos = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            d[pos + 1] = nums[i];
        }
    }
    return maxLen;
}

/* int lengthOfLIS(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int len = nums.size();
    vector<int> dp(len, 1);// dp[i]表示以i为终点的最大上升子序列的长度。
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
    // 找到dp数组中的最大值
    int ans = 0;
    for(int i = 0; i < len; ++i)
        ans = max(ans, dp[i]);
    return ans;
}
 */
int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << lengthOfLTS(arr) << endl;
    }
    return 0;
}