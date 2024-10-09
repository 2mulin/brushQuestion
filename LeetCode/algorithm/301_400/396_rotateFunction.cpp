/**
 * @author ling
 * @date 2021/4/22
 * @brief medium 旋转函数
 *
 * 1. 枚举
 * 找出旋转函数的最大值。计算出所有旋转函数可能，然后计算出最大值。
 * 时间复杂度: O(N*N)           空间复杂度: O(N)
 * 
 * 2. 数学
 * 这是一个类似前n项和的数学题，把和列出来，可以找到每个旋转函数的关系式。
 * 最终得到一个公式。
 * 时间复杂度：O(N)             空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

int maxRotateFunction(std::vector<int> &nums)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int init_val = 0;
    for(size_t i = 0; i < nums.size(); ++i)
        init_val = init_val + nums[i] * i;

    int ans = init_val;
    // 计算func(1) ~ func(n-1)
    size_t sz = nums.size();
    for(size_t i = 1; i < sz; ++i)
    {
        init_val = init_val + sum - sz * nums[sz - i];
        ans = std::max(init_val, ans);
    }
    return ans;
}

// 枚举超时
// int maxRotateFunction(std::vector<int> &nums)
// {
//     int ans = INT_MIN;
//     size_t count = 0;
//     while(count < nums.size())
//     {
//         int sum = 0;
//         int idx = count;
//         size_t sz = 0;
//         while(sz != nums.size())
//         {
//             sum += nums[idx] * sz;
//             ++sz;
//             idx = (idx + 1) % nums.size();
//         }
//         ans = std::max(sum, ans);
//         ++count;
//     }
//     return ans;
// }

int main()
{
    std::vector<int> nums{4,3,2,6};
    std::cout << maxRotateFunction(nums) << std::endl;
    return 0;
}