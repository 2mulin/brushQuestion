/**
 * @date 2025/7/27
 * @author 2mu
 * @brief easy 统计数组中峰和谷的数量
 *
 * 1. 遍历一遍
 * 遍历每个元素，遍历的同时进行判断，如果满足条件就累计加一
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

int countHillValley(vector<int> &nums)
{
    int count = 0;
    int pre_value = -1;
    for(int i = 1; i < nums.size() - 1; ++i)
    {
        if (pre_value == nums[i] && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i - 1, right = i + 1;
        while(left >= 0 && nums[left] == nums[i])
            --left;
        while(right < nums.size() && nums[right] == nums[i])
            ++right;
        
        if (left < 0 || right >= nums.size())
            continue;

        if (nums[left] > nums[i] && nums[i] < nums[right])
        {
            pre_value = nums[i];
            ++count;
        }
        else if (nums[left] < nums[i] && nums[i] > nums[right])
        {
            pre_value = nums[i];
            ++count;
        }
    }
    return count;
}

int main()
{
    std::vector<int> nums{2,4,1,1,6,5};
    std::cout << countHillValley(nums) << std::endl;
    return 0;
}
