/********************************************************************************************
 * @author reddragon
 * @date 2021/1/17
 * @brief medium 乘积最大的子数组
 * 
 * 1，暴力
 * 直接枚举所有可能，计算最大的乘积
 * 时间复杂度：O(n*n)       空间复杂度：O(N)
 * 
 * 2.动态规划
 * 
 * 得到乘积最大可以是正数乘积越多越好，或者偶数个负数乘起来, 我们可以维护两个dp数组
 * 分别表示以第 i 个元素结尾的乘积最大子数组的乘积 fmax(i)，和最小的乘积 fmin(i).
 * 如果当前nums[i]是负数，那么当然是nums[i]*fmin[i]最大，负负得正嘛。
 * 如果当前nums[i]是正数，那么当然是nums[i]*fmax[i]最大，
 * 如果是0， 那以它结尾的子数组最大值，最小值都是0。
 * 可以得到状态转移方程
 * 		fmax[i] = max(fmax[i -1]*nums[i], max(fmin[i -1]*nums[i], nums[i]));
 * 		fmin[i] = min(fmax[i -1]*nums[i], min(fmin[i -1]*nums[i], nums[i]));
 * 利用俩个dp数组的空间需要O(n), 但是这里可以看到只是和i和i-1有关，所以只需要四个int就够了
 * 利用滚动数组优化
 * 时间复杂度：O(n)			空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 动态规划
int maxProduct(vector<int> &nums)
{
    if(nums.size() == 1)
    	return nums[0];
	vector<int> fmax(nums.begin(), nums.begin() + 2);	// 乘积最大值,正数
	vector<int> fmin = fmax;							// 成绩最小值,负数
	// 滚动数组(利用坐标滚动)
	int front = 0, back = 1;
	int ret = fmax[front]; // 答案
	for(size_t i = 1; i < nums.size(); ++i)
	{
		fmax[back] = max(fmax[front]*nums[i], max(fmin[front]*nums[i], nums[i]));
		ret = max(ret,fmax[back]);
		fmin[back] = min(fmax[front]*nums[i], min(fmin[front]*nums[i], nums[i]));
		swap(back, front);
	}
	return ret;
}	

// 暴力法
// int maxProduct(vector<int> &nums)
// {
// 	if (nums.empty())
// 		return 0;
// 	int ret = nums[0];
// 	for (auto num : nums)
// 		ret = max(ret, num);
// 	for (int i = 0; i < nums.size() - 1; ++i)
// 	{
// 		int total = nums[i];
// 		for (int j = i + 1; j < nums.size(); ++j)
// 		{
// 			total *= nums[j];
// 			ret = max(ret, total);
// 		}
// 	}
// 	return ret;
// }
int main()
{
	vector<int> arr{2,3,-2,4};
	cout << maxProduct(arr) << endl;
	return 0;
}
