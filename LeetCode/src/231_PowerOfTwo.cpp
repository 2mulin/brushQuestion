/**
 * @author ling
 * @date 2021/5/30
 * @brief easy 2的幂
 * 
 * 1. 暴力
 * 每次除2, 一旦出现余数说明不是2的幂,最后可以除到1并且一直没有出现余数
 * 说明是2的幂次方。负数和0都不是2的幂次方。int类型，所以最多除32次，所以
 * 时间复杂度是O(1)
 * 时间复杂度： O(1)          空间复杂度：O(1)
 * 
 * 2. 位运算
 * 当n是2的幂次方时，那么n一定是正整数，并且n的二进制表示中，有且仅有一个1，其余位都是0
 * 所以可以先判断n的正负，然后判断1的个数
 * 时间复杂度： O(1)          空间复杂度：O(1)
 * 
 * 3. 位运算PLUS
 * 假设 n 的二进制表示为 (a1000..)其中a表示若干个高位，1表示最低位的那个 1。
 * 000..表示后面的若干个0，那么 n−1 的二进制表示为：(a0111..)，111..表示后面所有的1
 * 将 n和n-1 进行按位与运算，高位 a 不变，在这之后的所有位都会变为 0，这样我们就将最低位的那个 1 移除了。
 * 
 * 由于2的幂次方数二进制只有一个1，所以满足n > 0 && n&(n-1) == 0, 就是2的幂次方数。
 * 时间复杂度：O(1)            空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 计算二进制表示中1的个数
 */
int countOfOne(int n)
{
    int sum = 0;
    int cmp = 1 << 31;
    while(n)
    {
        if(n & cmp)
            ++sum;
        n <<= 1;
    }
    return sum;
}

/**
 * @brief 判断n是否是2的幂次方
 */
bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;
    return countOfOne(n) == 1;
}

/* 
bool isPowerOfTwo(int n) 
{
    if(n <= 0)
        return false;
    else if(n == 1)
        return true;
    else
    {
        while(n > 1)
        {
            if(n % 2 == 1)
                return false;
            n /= 2;
        }
        return true;
    }
} */

int main()
{
    cout << isPowerOfTwo(10) << endl;
    return 0;
}