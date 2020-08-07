/***************************************************************************
 * @date 2020/7/6
 * @author reddragon
 * @description: medium 在排序数组中查找元素
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
 * 找出给定目标值在数组中的开始位置和结束位置。
 * 暴力法: 顺序查找  时间复杂度O(n)，空间复杂度O(1)
 * 
 * 二分法：找到其中一个target值，然后向左，向右遍历，就能得到两个边界了
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    int low = 0, high = nums.size() - 1;
    int x = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
        {
            x = mid;
            break;
        }
    }
    if (x == -1)
        return ans;
    for (int i = x; i >= 0 && nums[i] == target; i--)
        ans[0] = i;
    for (int i = x; i < nums.size() && nums[i] == target; i++)
        ans[1] = i;
    return ans;
}
// 暴力
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     vector<int> ans(2, -1);
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//         {
//             ans[0] = i;
//             break;
//         }
//     }
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         if (nums[i] == target)
//         {
//             ans[1] = i;
//             break;
//         }
//     }
//     return ans;
// }

int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 6);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}
