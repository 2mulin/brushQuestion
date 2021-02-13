/********************************************************************************************
 * @author reddragon
 * @date 2021/2/13
 * @brief easy 找到数组中所有缺失的数字
 * 
 * 1. 哈希表
 * 使用unordered_multiset保存所有数字, 最后遍历一次, 看1~n中那个数字不存在
 * 时间复杂度: O(N)				空间复杂度: O(N)哈希表
 * 
 * 2.原地哈希
 * 具体来说，遍历 nums，每遇到一个数 x，就让 nums[x-1] 增加 n。
 * 由于 nums 中所有数均在 [1,n] 中，增加以后，这些数必然大于 n。
 * 最后我们遍历 nums，若 nums[i] 未大于 n，就说明没有遇到过数 i+1。这样我们就找到了缺失的数字。
 * 时间复杂度: O(N)				空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <dataStruct.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
	int n = nums.size();
	for(int i = 0; i < n; ++i)
	{
		int pos = (nums[i] - 1) % n;// 避免越界
		int& num = nums.at(pos);
		num += n;
	}
	vector<int> ret;
	for(int i = 0; i < n; ++i)
	{
		if(nums[i] <= n)
			ret.push_back(i + 1);
	}
	return ret;
}

// // 哈希表
// vector<int> findDisappearedNumbers(vector<int> &nums)
// {
// 	int n = nums.size();
// 	for(int i = 0; i < n; ++i)
// 	{
// 		if(nums[i] != i + 1)
// 			swap(nums[i], nums[nums[i] - 1]);
// 	}

// 	vector<int> ret;
// 	for(int i = 0; i < n; ++i)
// 		if(nums[i] != i + 1)
// 			ret.push_back(i + 1);
// 	return ret;
// }

int main()
{
	vector<int> arr{4,3,2,7,8,2,3,1};
	vector<int> ret = findDisappearedNumbers(arr);
	for(auto i : ret)
		cout << i << '\t';
	cout << endl;
	return 0;
}