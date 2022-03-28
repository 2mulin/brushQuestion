/**
 * @author ling
 * @date 2021/3/28
 * @brief easy 交替位二进制数
 *
 * 1. 位运算
 * 把每个相邻位都做一次异或运算，如果所有异或运算结果都是true，那就是满足条件。否则不满足。
 * 时间复杂度：O(logN)          空间复杂度: O(1)
 * 
 * 2. 官方题解才叫位运算，我的方法1应该叫做小孩子玩泥巴
 * [https://leetcode-cn.com/problems/binary-number-with-alternating-bits/solution/jiao-ti-wei-er-jin-zhi-shu-by-leetcode-s-bmxd/]
 * 时间复杂度：O(1)             空间复杂度: O(1)
 */

#include <iostream>

bool hasAlternatingBits(int n)
{
    bool ans = true;
    int flag = n & 1;
    n >>= 1;
    while (n)
    {
        int tmp = n & 1;
        if (tmp ^ flag)
        {
            flag = tmp;
            n >>= 1;
        }
        else
        {
            ans = false;
            break;
        }
    }
    return ans;
}

bool hasAlternatingBits(int n)
{
    long a = n ^ (n >> 1);
    // 为什么是long，因为还要判断最高位。
    return (a & (a + 1)) == 0;
}

int main()
{
    std::cout << hasAlternatingBits(11) << std::endl;
    return 0;
}
