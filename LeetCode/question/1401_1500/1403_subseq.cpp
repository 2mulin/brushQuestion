/**
 * @date 2022/8/4
 * @author 2mu
 * @brief easy 非递增顺序的最小子序列
 *
 * 1. 模拟
 * 先将数组所有元素之和sum求出来，同时求出来一个最长非递增子序列。
 * 按照要求来看，答案一定就是最长非递增子序列的 子序列。
 *
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

std::vector<int> minSubsequence(std::vector<int> &nums)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    std::vector<int> result;
    int resultSum = 0;
    for(auto num : nums)
    {
        resultSum += num;
        result.push_back(num);
        if(resultSum > (sum - resultSum))
            break;
    }
    return result;
}

int main()
{
    std::vector<int> nums{4, 3, 10, 9, 8};
    std::vector<int> ans = minSubsequence(nums);
    for(auto val : ans) 
        std::cout << val << '\t';
    std::cout << std::endl;
    return 0;
}
