/**
 * @date 2024/10/20
 * @author 2mu
 * @brief easy 最小差值I
 *
 * 1. 排序
 * 题目要求是把nums元素中操作之后, nums中最大元素 - 最小元素 的差值达到最小;
 * 仔细想想, 其实只需要考虑操作之前的数组中的最大值和最小值; 
 * 因为最大值, 最小值要么是当前最大值, 最小值; 要么是+k, -k替换后的;
 * 
 * 但如果是+k, -k替换后的实际上只是加大 diff(最大值 - 最小值), 所以没必要考虑;
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int smallestRangeI(vector<int> &nums, int k)
{
    int max_val = INT_MIN, min_val = INT_MAX;
    for(int i = 0; i < nums.size(); ++i)
    {
        max_val = std::max(max_val, nums[i]);
        min_val = std::min(min_val, nums[i]);
    }
    // 差值一定是正整数, 最小是0, 因为操作后的最大值 > 操作后的最小值...
    if(max_val - min_val <= 2 * k)
        return 0;
    return max_val - min_val - 2 * k;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{0, 50, 50, 100};
    std::cout << smallestRangeI(nums, 3) << std::endl;
    return 0;
}
