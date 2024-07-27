/**
 * @author ling
 * @date 2021/3/15
 * @brief medium 统计按位或能得到的最大值,子集个数
 *
 * 1. 枚举
 * 说先思考下，按位或的最大值是什么？就是把数组提前按位或一遍，得到最大值。预处理。
 * 就是按位或子集结果等于该值的集合数量。
 * 
 * 然后题目条件是数组长度最大16，说明可以使用枚举。
 * 时间复杂度：O(2的N次方*N)       空间复杂度：O(1)
 * 
 * 2. 回溯
 * 显然易见，每次按位或的值，可以由上一个按位或的值求出来。记录下来，
 * 使用回溯节省枚举过程中做一遍按位或的开销。
 * 时间复杂度：O(2的N次方)          空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

int dfs(const std::vector<int> &nums, size_t idx, int orSum, int maxNum)
{
    if(idx == nums.size())
        return orSum == maxNum ? 1 : 0;
    int newNum = orSum | nums[idx];
    return dfs(nums, idx+1, orSum, maxNum) + dfs(nums, idx+1, newNum, maxNum);
}

int countMaxOrSubsets(std::vector<int> &nums)
{
    int maxNum = 0;
    for(auto num : nums)
        maxNum |= num;
    return dfs(nums, 0, 0, maxNum);
}

int main()
{
    std::vector<int> arr{3,1};
    std::cout << countMaxOrSubsets(arr) << std::endl;
    arr = {2,2,2};
    std::cout << countMaxOrSubsets(arr) << std::endl;
    arr = {3,2,1,5};
    std::cout << countMaxOrSubsets(arr) << std::endl;
    return 0;
}