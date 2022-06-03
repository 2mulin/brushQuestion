/**
 * @date 2022/6/3
 * @author 2mu
 * @brief hard 连续整数之和
 *
 * 1. 暴力枚举
 * 列举出所有连续整数的可能性，只要和是n，就满足条件。
 *
 * 时间复杂度：假设连续的数只有一个，那就是n种，连续的数有2个，那就是n-1种。所以时间复杂度是前n项和，(1 + n)*n / 2，大概就是O(n*n)
 * 空间复杂度：O(1)
 *
 * 2. 前缀和数组
 * 只要使用一个前缀和数组，就不需要重复计算和了，连续数的和就是arr[y] - arr[x]。是很小的优化。
 * 时间复杂度还是N的平方
 *
 * 3. 数学
 * 通过反证法证明，如果n可以与连续的整数和相等。这一定满足一些条件。看官方题解吧。
 */

#include <iostream>
#include <vector>

// int consecutiveNumbersSum(int n)
// {
//     long long sum = 0;
//     int start = 1, result = 0;
//     while(start <= n && start <= 1e9)
//     {
//         int i = start;
//         while(sum < n)
//         {
//             sum += i;
//             i++;
//         }
//         if(sum == n)
//             result++;
//         start++; // 设置新起点,重新尝试
//         sum = 0;
//     }
//     return result;
// }

// int consecutiveNumbersSum(int n)
// {
//     std::vector<long long> arr {0 , 1};
//     long long sum = 1;
//     for(int i = 2;  i <= n / 2 + 1; ++i)
//     {
//         sum += i;
//         arr.push_back(sum);
//     }
//     int result = 1;
//     for(int i = arr.size() - 1; i >= 2; --i)
//     {
//         if(arr[i] == n)
//             ++result;
//         for(int j = i - 1; j >= 1; --j)
//         {
//             int sub = arr[i] - arr[j];
//             if(sub == n)
//                 ++result;
//             if(sub >= n)
//                 continue;
//         }
//     }
//     return result;
// }


bool isKConsecutive(int n, int k)
{
    if (k % 2 == 1)
        return n % k == 0;
    else
        return n % k != 0 && 2 * n % k == 0;
}

int consecutiveNumbersSum(int n)
{
    int ans = 0;
    int bound = 2 * n;
    for (int k = 1; k * (k + 1) <= bound; k++)
    {
        if (isKConsecutive(n, k))
            ans++;
    }
    return ans;
}

int main()
{
    std::cout << consecutiveNumbersSum(5) << std::endl;
    std::cout << consecutiveNumbersSum(9) << std::endl;
    std::cout << consecutiveNumbersSum(15) << std::endl;

    std::cout << consecutiveNumbersSum(34624713) << std::endl;
    return 0;
}
