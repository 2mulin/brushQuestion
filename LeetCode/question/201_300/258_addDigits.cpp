/**
 * @author ling
 * @date 2021/3/3
 * @brief easy 各位相加
 *
 * 1. 模拟
 * 按照规则取出每一位数，然后相加至一位数就可以了。
 * 时间复杂度：O(N)       空间复杂度：O(1)
 * 
 * 2. 数学
 */

#include <iostream>

int addDigits(int num)
{
    if(num < 10)
        return num;
    int ans = 0;
    while(num)
    {
        ans += num % 10;
        num /= 10;
    }
    return addDigits(ans);
}

int main()
{
    std::cout << addDigits(38) << std::endl;
    return 0;
}