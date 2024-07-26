/**
 * @date 2024/7/26
 * @author 2mu
 * @brief medium 找出分区值
 *
 * 1. 排序
 * 根据题意, 最小的分区值 实际上就是数组中两个大小最接近的元素 做差的绝对值;
 * 那么怎么得到数组大小最接近的两个元素呢? 
 * 
 * 思路就是排序数组, 然后遍历数组相邻的两个元素, 最后就能得到答案;
 * 
 * 备注: 没想到题解也是排序, 还以为有什么高级方法呢...
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findValueOfPartition(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    int min_val = INT_MAX;
    for (int i = 1; i < nums.size(); ++i)
    {
        min_val = std::min(min_val, std::abs(nums[i] - nums[i - 1]));
    }
    return min_val;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{1, 3, 2, 4};
    std::cout << findValueOfPartition(nums) << std::endl;
    return 0;
}

