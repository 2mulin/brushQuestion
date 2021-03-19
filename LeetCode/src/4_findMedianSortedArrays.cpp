/********************************************************************************************
 * @author reddragon
 * @date 2021/3/19
 * @brief hard 寻找两个有序数组的中位数
 * 
 * 1. 归并排序的思路
 * 使用归并排序合并的方式把两个数组合并, 然后找出中位数
 * 时间复杂度: O(N)     空间复杂度: O(1)
 * 
 * 2. 二分查找
 * 可以使用两天分割线将数组切分开来, 并且满足两个条件: 
 * 1. 两条分割线 左边所有元素个数比右边所有元素个数多一个或者相等
 * 2. 两条分割线 左边所有元素都小于等于右边所有元素
 * 
 * 只要确定分割线满足上面连个请求, 最终中位数只取决于分割线两端的
 * 4个元素. 如果两数组之和是奇数, 那么中位数就是分割线左边两个元素
 * 最小的那个. 入宫是偶数, 那就是左边最大的,加上右边最小的 / 2;
 * 
 * 而确定分割线的位置只需要二分查找就好了
 * 
 * 这题实现非常麻烦, 主要是不能越界, 分割线的表示也很讲究, 参考下面
 * 时间复杂度: O(lg N)      空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// 要找出中位数需要满足两个条件, 
// 1. 分割线左右两边元素基本相等
// 2. 分割线左边元素全部小于分割小右边元素

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    if(m > n)
        return findMedianSortedArrays(nums2, nums1);// 不然nums2[mid2]会越界

    // 分割线分开后, 左边所有元素个数, 右边所有元素个数
    int left_size = (m + n + 1) / 2;

    // 确定满足条件的分隔线, 左边所有元素大于右边所有元素
    int left = 0, right = m;
    while(left < right)
    {
        // 确定分割线, mid1表示nums1分割线右边的第一个元素下标
        int mid1 = left + (right - left + 1) / 2;
        int mid2 = left_size - mid1;
        if(nums1[mid1 - 1] > nums2[mid2])
        {// 分割线需要往左移
            right = mid1 - 1;
        }
        else
        {// 分割线需要左移
            left = mid1;
        }
    }
    int mid1 = left;
    int mid2 = left_size - mid1;

    int leftVal1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
    int rightVal1 = (mid1 == m ? INT_MAX: nums1[mid1]);
    int leftVal2 = (mid2 == 0 ? INT_MIN: nums2[mid2 - 1]);
    int rightVal2 = (mid2 == n ? INT_MAX: nums2[mid2]);
    if((m + n) % 2 == 1)
    {// 和是奇数
        return max(leftVal1, leftVal2);
    }
    else
        return (double)(max(leftVal1, leftVal2) + min(rightVal1, rightVal2)) / 2; 
}

int main()
{
    vector<int> arr1{1,3};
    vector<int> arr2{4};
    cout << findMedianSortedArrays(arr1, arr2) << endl;
    return 0;
}
