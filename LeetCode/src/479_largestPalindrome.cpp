/**
 * @author ling
 * @date 2021/4/16
 * @brief hard 最大回文数的乘积
 *
 * 1. 枚举
 * 两层for循环硬求，把n位数所有可能乘积全部枚举一遍。取出最大值。
 * 显然会超时，但是可以打表
 * 时间复杂度: O(N位数*N位数)         空间复杂度: O(1)
 * 
 * 2. 枚举优化
 * 要有逆向思维，反过来想，总共1 ~ 99999999个数，这里面有几个回文数，并且这个回文数是两个
 * n位数相乘的结果。然后找到最大的。
 * 
 * 但是怎么判断这个回文数是可以用两个n位数相乘，这就是数学问题了。
 */

#include <iostream>
#include <string>
#include <cmath>

// 省时省力，之打表。
// int largestPalindrome(int n) {
//     switch(n)
//     {
// #define func(num, ans) case num: return ans
//         func(1, 9);
//         func(2, 987);
//         func(3, 123);
//         func(4, 597);
//         func(5, 677);
//         func(6, 1218);
//         func(7, 877);
//         func(8, 475);
//     };
// #undef func
//     return 0;
// }

bool isPalindromes(long long n)
{
    std::string num = std::to_string(n);
    int len = num.length();
    for(int i = 0; i < len / 2; ++i)
    {
        if(num[i] != num[len - 1 - i])
            return false;
    }
    return true;
}

int largestPalindrome(int n)
{
    long min_num = std::pow(10, n - 1);
    long long max_num = 0;
    while(n)
    {
        max_num *= 10;
        max_num += 9;
        --n;
    }

    long long ans = 0;
    for(long long i = max_num; i >= min_num; --i)
    {
        for(long long j = i; j >= min_num; --j)
        {
            long long tmp = i * j;
            if(isPalindromes(tmp))
            {
                ans = ans < tmp ? tmp : ans; 
            }
        }
    }
    return ans % 1337;
}

int main()
{
    for(int i = 1; i < 9; ++i)
        std::cout << largestPalindrome(i) << std::endl;
}