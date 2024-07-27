/**
 * @author ling
 * @date 2021/2/26
 * @brief easy 增量元素之间的最大差值
 *
 * 1. 枚举
 * 枚举所有情况，找到所有差值，然后找出差值的中的最小值。
 * 时间复杂度: O(N*N)      空间复杂度: O(N)
 *
 * 2. 遍历
 * 分区，以记录的idx为基准，分为两边。idx记录当前碰到的数组最小值。
 * 如果当前值比nums[idx]大，可以将其差值和记录的最小差值比较，更新最小差值。
 * 如果当前值比nums[idx]小，那就跟新idx。
 * 
 * 只需要一次遍历。
 * 时间复杂度：O(N*N)       空间复杂度：O(1)
 */

#include <iostream>
#include <climits>
#include <vector>

/**
 * @brief 枚举所有情况 o(N*N)
 */
// int maximumDifference(const std::vector<int> &nums)
// {
//     int maxDifference = INT_MIN;
//     for (size_t i = 0; i < nums.size(); ++i)
//     {
//         for (size_t j = i + 1; j < nums.size(); ++j)
//         {
//             int difference = nums[j] - nums[i];
//             maxDifference = maxDifference > difference ? maxDifference : difference;
//         }
//     }
//     if (maxDifference < 0)
//         return -1;
//     return maxDifference;
// }

// 一次便利
int maximumDifference(const std::vector<int> &nums)
{
    int minIdx = 0;
    int ans = INT_MIN;
    for(size_t i = 1; i < nums.size(); ++i)
    {
        int diff = nums[i] - nums[minIdx];
        if(diff > 0)
        {
            ans = diff > ans ? diff : ans;
        }
        else
        {
            minIdx = i;
        }
    }

    return ans;
}

int main()
{
    std::cout << maximumDifference({1,2,3,4}) << std::endl;
    return 0;
}