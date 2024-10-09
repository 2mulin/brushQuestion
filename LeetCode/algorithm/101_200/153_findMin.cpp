/********************************************************************************************
 * @author reddragon
 * @date 2021/4/8
 * @brief medium 寻找排序数组的最小值
 * 
 * 1，全部遍历一遍
 * 全部遍历一遍就可以了.
 * 时间复杂度: O(N)        空间复杂度: O(1)
 * 
 * 2. 二分查找
 * 经过旋转得到数组是一个两段有序数组. 而且, 左边这一段 必定 比右边这一段大
 * 因此, 我们可以二分查找. 
 * 注意这个左边这段所有元素 比 右边这段小的特点. 我们关注nums[high]和nums[mid]
 * 的大小关系, 就能确定mid在前半段还是后半段.以此二分
 * 时间复杂度: O(N)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int findMin(vector<int> &nums)
{
    int high = nums.size() - 1, low = 0;
    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(nums[high] < nums[mid])
            low = mid + 1;      // 前半段有序不需要
        if(nums[high] > nums[mid])
            high = mid;// 后半段
    }
    return nums[low];
}

/*// 一次循环
int findMin(vector<int> &nums)
{
    int minVal = INT_MAX;
    for (auto i : nums)
        minVal = min(i, minVal);
    return minVal;
}
 */
int main()
{
    vector<int> nums{3,4,5,1,2};
    cout << findMin(nums) << endl;
    return 0;
}