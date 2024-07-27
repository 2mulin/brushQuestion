/**
 * @author ling
 * @date 2022/3/31
 * @brief  easy 自除数
 *
 * 1.模拟
 * 按照规则整除就是了，首先计算出来这个数使用几个数字组成。
 * 时间复杂度：O(nlogn)         空间复杂度：O(1)
 */
#include <iostream>
#include <vector>

using std::vector;

bool isDividingNumber(int num)
{
    int tmp = num;
    while (tmp)
    {
        int n = tmp % 10; // 个位数
        if (!n || num % n)
            return false;
        tmp /= 10;
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
    std::vector<int> arr;
    for (int i = left; i <= right; ++i)
    {
        if (isDividingNumber(i))
            arr.push_back(i);
    }
    return arr;
}

int main(int argc, char **argv)
{
    return 0;
}
