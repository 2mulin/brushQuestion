/**
 * @author ling
 * @date 2021/5/8
 * @brief medium 统计数组出现两次的数字
 *
 * 1. 空间换时间
 * 额外使用array记录每个数字出现的次数。最后统计出现两次的数字。
 * 时间复杂度：O(N)             空间复杂度：O(N)
 * 
 * 2. 原地统计
 * 由于数字大小被限制，且全部是正整数。可以使用正负号统计数字出现次数。
 * 时间复杂度：O(N)             空间复杂度：O(1)
 */

#include <iostream>
#include <array>
#include <vector>

// std::vector<int> findDuplicates(std::vector<int>& nums)
// {
//     std::vector<int> ans;
//     for()
// }

std::vector<int> findDuplicates(std::vector<int> &nums)
{
    int n = nums.size(); // 还有一个条件：所有nums[i] < n ， 不然这个方法不对，数组直接越界了。
    std::vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        int x = abs(nums[i]);
        if (nums[x - 1] > 0)
        {
            nums[x - 1] = -nums[x - 1];
        }
        else
        {
            ans.push_back(x);
        }
    }
    return ans;
}

// std::vector<int> findDuplicates(std::vector<int>& nums)
// {
//     std::array<int, 10005> arr{0};
//     for(auto num : nums)
//     {
//         ++arr[num];
//     }
//     std::vector<int> ans;
//     for(int i = 0; i < 10005; ++i)
//     {
//         if(arr[i] == 2)
//             ans.push_back(i);
//     }
//     return ans;
// }

int main()
{
    std::vector<int> arr{1,2552,3,4,2,3,4};
    auto ans = findDuplicates(arr);
    for (auto val : ans)
        std::cout << val << std::endl;
    return 0;
}