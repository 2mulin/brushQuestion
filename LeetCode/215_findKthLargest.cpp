/********************************************************************************************
 * @author reddragon
 * @date 2021/2/1
 * @brief medium 第K大的数
 * 
 * 1.暴力
 * 先排序，然后输出
 * 时间复杂度：O(nlogn)		空间复杂度：O(n)
 * 
 * 2. 堆排序
 * 建立一个大根堆，然后做k-1次删除操作
 * 时间复杂度：O(nlogn)				空间复杂度：O(1)
 * 
 * 3. 快速排序
 * 题解还有一个快排的思想，但是我认为，快排选择的基点是随机的，
 * 不一定最后就是我要的第K大的元素，实际也是靠运气。
 * 
 * 我们知道快速排序的性能和「划分」出的子数组的长度密切相关。
 * 直观地理解如果每次规模为 n 的问题我们都划分成 1 和 n - 1，
 * 每次递归的时候又向 n - 1n−1 的集合中递归，
 * 这种情况是最坏的，时间代价是 O(n*n)。
 * 我们可以引入随机化来加速这个过程，它的时间代价的期望是 O(n)，
 * 证明过程可以参考「《算法导论》9.2：期望为线性的选择算法」。
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 暴力法
// int findKthLargest(vector<int>& nums, int k) 
// {
// 	sort(nums.begin(), nums.end(), std::greater<int>());
// 	return nums[k - 1];
// }

// 从第nums[K]个节点下滤
void donwSort(vector<int>& nums, int k, int len)
{
	int i = k;
	while(1)
	{
		int pos1 = i * 2 + 1;
		int pos2 = pos1 + 1;
		// 在左右孩子中找到最大值
		if(pos1 < len && nums[pos1] > nums[k])
			k = pos1;
		if(pos2 < len && nums[pos2] > nums[k])
			k = pos2;
		if(i == k)
			break;// 该节点是最大值，无需下滤
		swap(nums[i], nums[k]);
		i = k;
	}
}

// 堆排序
int findKthLargest(vector<int>& nums, int k)
{
	// 建一个大根堆
	int len = nums.size();
	int be = len / 2 - 1;// 第一个非叶子节点
	while(be >= 0)
	{
		donwSort(nums, be, len);
		--be;
	}

	// 找到第K大
	while(--k)
	{
		swap(nums[0], nums[--len]);
		donwSort(nums, 0, len);
	}
	return nums[0];
}

int main()
{
	vector<int> arr{1,2,9,5,4};
	cout << findKthLargest(arr, 2) << endl;
    return 0;
}