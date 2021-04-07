/*******************************************************************************
 * @author reddragon
 * @date 2020/8/7
 * @brief medium 搜索旋转排序数组2
 * 1. 暴力
 * 一层for循环每个元素看一遍就是了
 * 时间复杂度: O(N)     空间复杂度: O(1)
 * 
 * 2. 二分查找
 * 由于这个数组只有分成了两部分有序, 所以每次二分的时候
 * 需要判断当前区间是否有序.
 * 这个二分查找写起来比较麻烦.
 * 时间复杂度: O(logN)     空间复杂度: O(1)
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// 前半段使用顺序查找，后半段使用二分查找
bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    for (; low <= high; low++)
    {
        if (nums[low] == target)
            return true;
        // 逆序，说明在此处旋转了
        if (low < high && nums[low] > nums[low + 1])
            break;
    }
    low++;
    // 对后半部分进行二分查找
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            return true;
    }
    return false;
}

// 顺序查找 O(n)
// bool search(vector<int> &nums, int target)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//             return true;
//     }
//     return false;
// }

int main()
{
    vector<int> arr{2, 5, 6, 0, 0, 1, 2};
    cout << search(arr, 2);
    return 0;
}