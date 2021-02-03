/********************************************************************************************
 * @author reddragon
 * @date 2021/2/3
 * @brief medium 除自身以外数组的乘积
 * 
 * 1.两个前缀数组
 * 分别用数组记录前后乘积,left[i]表示左边前i个元素乘积,right[i]表示从右到第i个元素的乘积
 * output[i]就等于left[i-1] * right[i+1]
 * 时间复杂度：O(n)		空间复杂度：O(3n)
 * 
 * 2.空间优化
 * 可以利用输出数组output代替left,一个整型变量代替right.遍历从后往前,用right累乘上来
 * 时间复杂度: O(n)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
	int len = nums.size();
	vector<int> output(len), left(len), right(len);
	left[0] = nums[0];
	right[len - 1] = nums[len - 1];
	for(int i = 1; i < len; ++i)
		left[i] = left[i - 1] * nums[i];
	for(int i = len - 2; i >= 0; --i)
		right[i] = right[i + 1] * nums[i];
	output[0] = right[1];
	output[len - 1] = left[len - 2];
	for(int i = 1; i < len - 1; ++i)
		output[i] = left[i - 1] * right[i + 1];
	return output;
}

int main()
{
	vector<int> arr{1,2,3,4};
	vector<int> ans = productExceptSelf(arr);
	for(auto i : ans)
		cout << i << endl;
	return 0;
}