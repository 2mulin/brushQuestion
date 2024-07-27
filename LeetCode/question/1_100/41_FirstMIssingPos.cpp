/*****************************************************************
 * @date 2020/7/10
 * @author reddragon
 * @description:hard 
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 * 1. 哈希表。      时间复杂度:O(n)      空间复杂度: O(n)
 * 2. 原地哈希。    时间复杂度:O(n)      空间复杂度: O(1)
 ****************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int ans = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            ans = -1; // 说明1存在，答案不是1
        if (nums[i] <= 0 || nums[i] > n)
            nums[i] = 1; // 负数和大于n的数肯定不是答案
    }
    if (ans == 1)
        return ans;
    for (int i = 0; i < n; i++)
    {
        int num = abs(nums[i]);
        nums[num - 1] = -abs(nums[num - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans = i + 1;
            break;
        }
    }
    if (ans == -1)
        ans = n + 1;
    return ans;
}

// 哈希表
// int firstMissingPositive(vector<int> &nums)
// {
//     int ans;
//     unordered_set<int> s;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         s.insert(nums[i]);
//     }
//     for (int i = 1;; i++)
//     {
//         if (s.find(i) != s.end())
//             continue;
//         else
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

int main()
{
    vector<int> nums{3, 4, -1, 1};
    cout << firstMissingPositive(nums) << endl;
    return 0;
}