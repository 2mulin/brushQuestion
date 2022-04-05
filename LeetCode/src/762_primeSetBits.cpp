/**
 * @author ling
 * @date 2021/4/5
 * @brief easy 二进制表示中,1的个数是质数
 *
 * 1. 模拟
 * 二进制表示表示一个数，最多也就是64位数。所以1的个数不会超过64。先打表计算出2~64之间的所有质数。
 * 然后将每个输入的数转化为二进制，计算其1的个数是不是质数。
 * 时间复杂度：O(18 * 64 * N)          空间复杂度: O(1)
 *
 * 2. 数学
 * 
 */

#include <iostream>
#include <vector>

using std::vector;

std::vector<int> PrimeTable = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

bool isValid(int num)
{
    int count = 0;
    while (num)
    {
        if (num & 1)
            ++count;
        num >>= 1;
    }
    for (int i = 0; i < PrimeTable.size(); ++i)
    {
        if (count == PrimeTable[i])
            return true;
    }
    return false;
}

int countPrimeSetBits(int left, int right)
{
    int count = 0;
    for (int i = left; i <= right; ++i)
    {
        if (isValid(i))
            ++count;
    }
    return count;
}

int main()
{
    std::cout << countPrimeSetBits(6, 10) << std::endl;
    return 0;
}
