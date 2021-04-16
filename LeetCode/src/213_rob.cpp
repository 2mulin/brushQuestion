/********************************************************************************************
 * @author ling
 * @date 2021/4/16
 * @brief medium 打家劫舍2
 * 
 * 1. 枚举
 * 最简单的思路，就是说注意细节，比如说由于是循环的数组，所以在检测0号元素的左侧和右侧的时候
 * 需要注意数组是否越界，越界如何调整。
 * 时间复杂度： O(2^n)      空间复杂读：O(n)和栈递归栈深度相关
 * 
 * 2. dp
 * 这一题比较难的地方就是数组首尾相连，首部和尾部不能同时选择。
 * 所以说，就是两种情况，首部和尾部，必定有一个没选。那么我们可以假设
 * 首部或者尾部有一个没有选择，那么接下来的处理不就是和打家劫舍1类似了吗。
 * 设dp[i]
 * 时间复杂度： O(n)        空间复杂度：O(n)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int robRange(vector<int> nums, int start, int end)
{
    vector<int> dp(end + 1, 0);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for(int i = start + 2; i <= end; ++i)
    {// 这里可能有疑问：怎么知道dp[i - 1]里面就一定选了nums[i - 1]呢？如果dp[i - 1]里面没有选择nums[i - 1],那么是不是应该是
    // 还要判断dp[i - 1] + nums[i]的值呢？实际上可以dp[i - 1]选了nums[i-1]没有并不重要，因为dp[i-1]要是没选，那他和dp[i - 2]
    // 的值就是一样的。选了他就要大一些。
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[end];
}

int rob(vector<int> &nums)
{
    int sz = nums.size();
    if(sz == 1)
        return nums[0];
    else if(sz == 2)
        return max(nums[0], nums[1]);
    else
        // 先确定了一个必不选
        return max(robRange(nums, 0, sz - 2), robRange(nums, 1, sz - 1));
}

/* 
// 枚举  flag为true表示上一个选了
int backTrace(const vector<int> &nums, int curr, vector<int> flag)
{
    int sz = nums.size();
    if (curr >= sz)
        return 0;
    // 不选
    int ret = backTrace(nums, curr + 1, flag);
    // 选
    int left = (sz + curr - 1) % sz;
    int right = (curr + 1) % sz;
    cout << left << ' ' << right << endl;
    if (!flag[left] && !flag[right])
    {
        flag[curr] = true;
        ret = max(ret, backTrace(nums, curr + 2, flag) + nums[curr]);
    }
    return ret;
}

int rob(vector<int> &nums)
{
    int sz = nums.size();
    vector<int> flag(sz, 0);
    return backTrace(nums, 0, flag);
} */

int main()
{
    vector<int> arr{2,3,2};
    cout << rob(arr) << endl;
    return 0;
}