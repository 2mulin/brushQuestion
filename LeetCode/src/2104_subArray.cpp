/**
 * @author ling
 * @date 2021/3/4
 * @brief medium 子数组范围和
 *
 * 1. 遍历
 * 第一次想错了，这里的子数组是按照顺序的。不能打乱顺序。
 * 双层for循环，枚举所有子数组的情况，然后计算找到最大最小值，计算差值。
 * 时间复杂度：O(N*N)       空间复杂度：O(1)
 *
 * 2.单调栈
 * 有点麻烦呀，
 * 时间复杂度：O(N)       空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

long long subArrayRanges(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;

    long long ans = 0;
    for (auto i = 0; i < nums.size(); ++i)
    { 
        int maxVal = nums[i];
        int minVal = nums[i];
        for(auto j = i + 1; j < nums.size(); ++j)
        {
            maxVal = std::max(nums[j], maxVal);
            minVal = std::min(nums[j], minVal);
            ans =  ans + (maxVal - minVal);
        }
    }
    return ans;
}

int main()
{

    return 0;
}