/**
 * @date 2025/1/29
 * @author 2mu 
 * @brief easy 存在重复元素II
 * 
 * 1. 哈希表
 * 创建一个哈希表，使用该哈希表维护一个k大的哈希表。该方案需要考虑k 大于 nums数量的情况。
 * 还有其他一些情况也需要考虑。
 * 
 * 时间复杂度：O(n)  空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    std::unordered_set<int> setNums;
    int len = std::min(nums.size(), (std::size_t)k + 1);
    for(int i = 0; i < len; ++i)
    {
        if (setNums.find(nums[i]) != setNums.end())
            return true;
        setNums.insert(nums[i]);
    }

    for(int i = k + 1; i < nums.size(); ++i)
    {
        setNums.erase(nums[i - k - 1]);
        if (setNums.find(nums[i]) != setNums.end())
            return true;
        setNums.insert(nums[i]);
    }
    return false;
}


int main()
{
    std::vector<int> nums{99, 99};
    std::cout << containsNearbyDuplicate(nums, 1) << std::endl;
    return 0;
}
