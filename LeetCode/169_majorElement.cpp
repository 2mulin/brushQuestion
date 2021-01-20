/********************************************************************************************
 * @author reddragon
 * @date 2021/1/20
 * @brief easy 多数元素
 * 
 * 1，暴力
 * 说白了，就是找出现次数最多的那个元素， 出现n/2次，不就是出现次数最多的元素了吗
 * 一个哈希表存储出现次数，输出出现次数最多的元素
 * 时间复杂度：O(n)			空间复杂度: O(n)
 * 
 * 2. 排序
 * 出现了，n/2次以上，那么排序后，第n/2个元素不就是我要的答案吗，现在的问题就是如何最快的找到排在
 * 第n/2个的元素，
 * 时间复杂度：O(nlogn)			空间复杂度：O(logn)
 * 注意：有点像快排，但是不是的，如果写成快排，那就是抽奖，因为你不知道什么时候确定的位置是n/2
 * 不过肯定比直接排序号。
 * 
 * 3. Boyer-Moore 投票算法
 * 我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
 * 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：
 *      如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
 *      如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
 * 在遍历完成后，candidate 即为整个数组的众数。
 * 正确性比较难证明，可以用反证法证明
 * 时间复杂度：O(n)			空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 摩尔算法
int majorityElement(vector<int>& nums) 
{
	int candidate = 0, count = 0;
	for(auto num : nums)
	{
		if(count == 0)
			candidate = num;
		if(candidate == num)
			++count;
		else
			--count;
	}
	return candidate;
}

// // 排序
// int majorityElement(vector<int>& nums) 
// {
// 	int n = nums.size();
// 	sort(nums.begin(), nums.end());
// 	return nums[n / 2];
// }

// // 暴力
// int majorityElement(vector<int>& nums) 
// {
// 	int n = nums.size();
// 	// 桶排序
// 	unordered_map<int, int> ma;
// 	for(auto num : nums)
// 	{
// 		ma[num]++;
// 	}

// 	int ret;
// 	int count = 0;
// 	for(auto it : ma)
// 	{
// 		if(it.second > count)
// 		{
// 			ret = it.first;
// 			count = it.second;
// 		}
// 	}

// 	return ret;
// }

int main()
{
	vector<int> arr{-1,100,2,100,100,4,100};
	cout << majorityElement(arr) << endl;
	return 0;
}
