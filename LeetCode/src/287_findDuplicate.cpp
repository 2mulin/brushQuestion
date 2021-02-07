/********************************************************************************************
 * @author reddragon
 * @date 2021/2/7
 * @brief medium 找到重复的数字
 * 
 * 最容易想到就是暴力, 使用两层for循环就可以看到重复的数字了
 * 
 * 1. 哈希表
 * 使用unordered_multiset保存所有数字, 找到重复的数字就只要调用一下count就OK了
 * 时间复杂度: O(N)				空间复杂度: O(N)哈希表
 * 
 * 2. 原地哈希
 * 题目说数组大小必然是n+1, 元素的值都是1~n, 并且只有一个重复值
 * 那么可以使用当前数组直接存储, 把每个元素放回原位, 一个萝卜一个坑, 最后多出来的那个
 * 就是重复的元素
 * 时间复杂度: O(N)				空间复杂度: O(1)
 * 
 * 3. 二分
 ********************************************************************************************/
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 原地哈希
int findDuplicate(vector<int> &nums)
{
	// nums[0] 必然是不会被占住的, 因为元素值大小在0之上
	while(nums[0] != nums[nums[0]])
	{
		swap(nums[0], nums[nums[0]]);
	}
	return nums[0];
}

// 哈希表
// int findDuplicate(vector<int> &nums)
// {
// 	unordered_multiset<int> hashset;
// 	for (int i = 0; i < nums.size(); ++i)
// 	{
// 		if (hashset.find(nums[i]) != hashset.end())
// 			return nums[i];
// 		hashset.insert(nums[i]);
// 	}
// 	return 0;
// }

int main()
{
	struct timeval tm1, tm2;
	if (gettimeofday(&tm1, nullptr) == -1)
		perror("gettimeofday");

	vector<int> arr{1,3,4,2,2};
	cout << findDuplicate(arr) << endl;

	if (gettimeofday(&tm2, nullptr) == -1)
		perror("gettimeofday");
	cout << "消耗时间: " << tm2.tv_usec - tm1.tv_usec << "微秒." << endl;
	return 0;
}