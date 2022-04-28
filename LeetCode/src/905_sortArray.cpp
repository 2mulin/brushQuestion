/**
 * @author ling
 * @date 2021/4/28
 * @brief easy 按照奇偶顺序排序
 *
 * 1. 模拟
 * 要求很简单，只要数组中所有偶数在奇数前面就是合法的。
 * 时间复杂度：O(N)             空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <queue>

// 方法一：利用deque，奇数往前面加，偶数往后面加。
// std::vector<int> sortArrayByParity(std::vector<int> &nums)
// {
//     std::deque<int> ans;
//     for(auto num : nums)
//     {
//         if (num % 2)
//             ans.push_back(num);
//         else
//             ans.push_front(num);
//     }
//     return std::vector<int>(ans.begin(),ans.end());
// }

// 优化方法一，构造指定大小的数组。无需动态增长

std::vector<int> sortArrayByParity(std::vector<int> &nums)
{
    std::vector<int> ans(nums.size(), 0);
    int left = 0, right = ans.size() - 1;
    for (auto num : nums)
    {
        if (num % 2)
            ans[right--] = num;
        else
            ans[left++] = num;
    }
    return ans;
}

int main()
{
    std::vector<int> nums{4, 3, 2, 6};
    sortArrayByParity(nums);
    return 0;
}