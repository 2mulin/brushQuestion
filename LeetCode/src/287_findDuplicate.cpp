/********************************************************************************************
 * @author reddragon
 * @date 2021/2/8
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
 * 缺点: 改变了数组的值, 副作用函数
 * 
 * 3. 二分查找
 * 也是利用哈希的思想,由于只有一个重复的数, 所以保证数组中小于index的数, 再组成一个数组是具有单调性的.
 * 二分查找比较复杂, 而且时间效率不高,需要结合抽屉原理节省空间
 * 
 * 4. 双指针
 * 双指针非常巧妙, 大意就是说, 我们可以把数组当作图, 也就是index作为源点, nums[index]作为下一个节点
 * 的index, 这里题目保证nums[index]的值在1-n之间, 所以保证了数组不会越界. 就是说这个数组装化成的图
 * 一定有环, 但是如何找到环的起点呢?
 * 首先找到利用快慢指针可以得到一个快慢指针的相遇点, 再创建一个新的指针指向0, 新指针和slow每次各走
 * 一步, 最终相遇时, 就是圆环的起点.
 * 具体查看 142.环状链表2 的题解
 * 时间复杂度: O(N)				空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <dataStruct.h>
using namespace std;

// 双指针
int findDuplicate(vector<int> &nums)
{
	int slow = 0, fast = 0;
	do{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	while(slow != fast);// 得到slow和fast相遇点
	// 推导出数组成环的起始点
	int newPtr = 0;
	while(nums[newPtr] != nums[slow])
	{
		newPtr = nums[newPtr];
		slow = nums[slow];
	}
	return nums[slow];
}

// 原地哈希
// int findDuplicate(vector<int> &nums)
// {
// 	// nums[0] 必然是不会被占住的, 因为元素值大小在0之上
// 	while (nums[0] != nums[nums[0]])
// 	{
// 		swap(nums[0], nums[nums[0]]);
// 	}
// 	return nums[0];
// }

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
	long long tm1 = getTime();
	vector<int> arr{2,5,9,6,9,3,8,9,7,1};
	cout << findDuplicate(arr) << endl;

	long long tm2 = getTime();
	cout << "消耗时间: " << tm2 - tm1 << "毫秒" << endl;
	return 0;
}