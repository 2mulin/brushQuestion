/**
 * @date 2025/1/16
 * @author 2mu
 * @brief easy 或值至少k得最短子数组I
 *
 * 1. 枚举
 * 注意是非空子数组，也就是至少1个元素，且是连续的数组元素
 * 从子数组长度为1开始枚举，枚举到子数组长度为nums原长度，如果这都没有
 * 说明没有
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 滑动窗口
 * 
 * 该方法能想到是真牛逼，第一个是满足单调性，第二个是滑动窗口的维护
 */

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int minimumSubarrayLength(vector<int> &nums, int k)
{
    int num = 0, count = 0;
    for(int count = 1; count <= nums.size(); ++count)
    {
        // 枚举每一种可能
        for(int start = 0; start <= nums.size() - count; ++start)
        {
            int num = 0;
            for(int i = start; i < start + count; ++i)
            {
                num |= nums[i];
            }
            if (num >= k)
                return count;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = {32,2,24,1};
    std::cout << minimumSubarrayLength(nums, 35) << std::endl;
    return 0;
}
