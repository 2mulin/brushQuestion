/*******************************************************************************
 * @author reddragon
 * @date 2020/8/7
 * @brief 搜索旋转排序数组 medium
 * 没有官方题解，不知道自己到底get到点了没，下面代码能过
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