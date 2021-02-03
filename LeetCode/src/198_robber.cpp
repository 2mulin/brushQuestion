/********************************************************************************************
 * @author reddragon
 * @date 2021/1/23
 * @brief medium 打家劫舍
 * 
 * 1，动态规划
 * 首先分析一下，相邻的只能偷一个。
 * 使用一个dp数组，dp[i]表示偷到第i个房子的时候最多能偷盗的钱财总和。
 * 可以得到一个状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + 1);
 * 时间复杂度：O(n)			空间复杂度：O(n)
 * 
 * 2. 滚动数组
 * 仙儿空间可以优化，使用滚动数组就行了
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int> &nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	else if (size == 1)
		return nums[0];
	else if (size == 2)
		return max(nums[0], nums[1]);
	else
	{
		vector<int> dp(2);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		int be = 0, ed = 1;
		for (int i = 2; i < size; ++i)
		{
			dp[be] = max(dp[ed], dp[be] + nums[i]);
			swap(be, ed);
		}
		return max(dp[0], dp[1]);
	}
}

int main()
{
	vector<int> arr{1, 2 ,3, 2, 4};
	cout << rob(arr) << endl;
	return 0;
}
