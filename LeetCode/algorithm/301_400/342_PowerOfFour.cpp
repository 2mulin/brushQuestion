/**
 * @author 2mu
 * @date 2025/8/15
 * @brief easy 4的幂
 * 
 * 1. 数学+位运算
 * 
 * 首先负数肯定不是4的幂次方，全部排除。
 * 
 * 当数字n是4的幂次方时，那么数字n也一定是2的幂次方。
 * 那么n(正整数情况下)的二进制表示有且仅有一个1，其余位都是0，并且1是在从左往右数 的偶数位置上。
 * 
 * 所以方案：先判断n的正负，然后判断二进制表示中1的个数。最后判断是否在偶数位置上，如16出现在第4位(从0位开始计算)，10000。
 * 
 * 判断1的位置是否在偶数位。可以构造一个32位二进制数num（10101010 10101010 10101010 10101010）也就是0xaaaaaaaa
 * 如果n和num进行按位与 得到的是0，那就表示1的位置在偶数位，是4的幂次方。否则就不是
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 * 
 * 2. 暴力
 * 
 * 直接使用一个循环不断地判断该数字与4取余，如果余数不为0，说明除不尽，肯定不是4的幂次方。
 * 
 * 时间复杂度：O(logN)
 * 空间复杂度：O(n)
 */

#include <iostream>


// // 暴力方法
// bool isPowerOfFour(int n)
// {
//     while(n >= 4)
//     {
//         int num = n % 4;
//         if (num != 0)
//             return false;
//         n /= 4;
//     }
//     if (n == 1)
//         return true;
//     return false;
// }


bool isPowerOfFour(int n)
{
    // 1. 负数不可能是4的幂次方
    // 2. n&(n−1)的操作会​​清除n的最低有效位（LSB）中的1​​，并将所有更低位的位（如果有）置为 0。也就是判断n的二进制表示只有1个1
    // 3. 判断1的位置是不是在偶数位
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
}


int main()
{
    std::cout << isPowerOfFour(1) << std::endl;
    std::cout << isPowerOfFour(14) << std::endl;
    std::cout << isPowerOfFour(16) << std::endl;
    return 0;
}