/**
 * @date 2025/8/24
 * @author 2mu
 * @brief easy s删除一个元素以后全为1的最长子数组
 *
 * 1. 遍历
 * 遍历一次，遍历的同时记录好当前出现了多少个数字1
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>


int longestSubarray(std::vector<int> &nums)
{
    int max_value = 0;
    int left_len = 0, right_len = 0, pos = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            right_len++;
        }
        else
        {
            max_value = std::max(max_value, left_len + right_len);
            left_len = right_len;
            right_len = 0;
            pos = i;
        }
    }
    max_value = std::max(max_value, left_len + right_len);
    if (pos == 0 && max_value == 0)
        return 0; // 数组中全是0，没有结果
    if (pos == -1)
        max_value--; // 必须至少删除一个元素
    return max_value;
}


int main()
{
    std::vector<int> nums{0};
    std::cout << longestSubarray(nums) << std::endl;
    return 0;
}
