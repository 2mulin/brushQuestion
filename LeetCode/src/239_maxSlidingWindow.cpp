/********************************************************************************************
 * @author reddragon
 * @date 2021/2/4
 * @brief hard 滑动窗口最大值
 * 
 * 1.暴力法
 * 最简单的思路就是保存每次k个元素,并且从其中找到最大值,保存下来就OK了
 * 使用deque可以确保插入和删除都是O(1)的,但是最后还是超时了
 * 时间复杂度：O(N*N)		空间复杂度：O(k)
 * 
 * 2.暴力法改进(单调队列)
 * 概念: 满足单调性的双端队列叫做单调队列
 * 通过暴力可以发现,时间的消耗主要是在查找最大值上面,如果这里可以优化的,问题就可以降到
 * O(n)的复杂度.
 * 可以发现,我们每次只需要知道最大值,和以后可能成为最大值的数,其它的数根本没有用处,
 * 也就是说,可以用一个deque保存最大值和可能成为最大值的数.
 * 维护它: 保证第一个数是当前最大值, 
 * 如 k = 3; 	arr{1,3,-1,-3,5,3,6,7}
 * 最开始 {1} -> {3}删除1,放3进去 -> {3, -1} -> {3, -1, -3} -> {5}前面的数都小于5,全部放弃,
 * 再也用不到了
 * 实际上就是保持一个单调性.
 * 时间复杂度: O(N) 		空间复杂度: O(K)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
	int len = nums.size();
	deque<int> ls;
	ls.push_back(nums[0]);
	for (int i = 1; i < k; ++i)
	{
		while(!ls.empty() && nums[i] > ls.back())
			ls.pop_back();
		ls.push_back(nums[i]);
	}
	vector<int> ans;
	ans.push_back(ls.front());
	for (int i = k; i < len; ++i)
	{
		if(ls.front() == nums[i - k])
			ls.pop_front();// 最大值要离开滑动窗口了
		if(ls.front() >= nums[i])
		{// 为了保持单调,需要把所有比nums[i]效地元素都删除
			while(!ls.empty() && nums[i] > ls.back())
				ls.pop_back();
			ls.push_back(nums[i]);
		}
		else
		{
			ls.clear();
			ls.push_back(nums[i]);
		}
		ans.push_back(ls.front());								// O(1)
	}
	return ans;
}

// 暴力: O(N*K)
// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
// 	int len = nums.size();
// 	deque<int> ls(k);
// 	for (int i = 0; i < k; ++i)
// 		ls[i] = nums[i];
// 	vector<int> ans;
// 	ans.push_back(*max_element(ls.begin(), ls.end()));
// 	for (int i = k; i < len; ++i)
// 	{
// 		ls.pop_front();											// O(1)
// 		ls.push_back(nums[i]);									// O(1)
// 		ans.push_back(*max_element(ls.begin(), ls.end()));		// O(K)
// 	}
// 	return ans;
// }

int main()
{
	vector<int> arr{1,1,0,0,0,0};
	vector<int> ans = maxSlidingWindow(arr, 2);
	for(auto it : ans)
		cout << it << '\t';
	return 0;
}