/*************************************************
 * @date 2020/6/25
 * @author reddragon
 * @description: medium 两数相除
 * 考的是移位，要仔细。我的这个版本不是最快的。
 ************************************************/
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;
    bool flag = false; //不同号
    if ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0))
        flag = true;
    long long a = dividend, b = divisor, count = 1, sum; //long long防止越界
    a = abs(a);
    b = abs(b);
    sum = b;
    // 左移，每次扩大两倍，可以加速
    while (sum < a)
    {
        sum <<= 1;
        count <<= 1;
    }
    // 扩大两倍可能多了，再减回去
    while (sum - a >= b)
    {
        sum -= b;
        count--;
    }
    // 当前count一定是正的
    if (flag)
    {
        if (sum == a && count <= INT_MAX)
            return count;
        else if (sum > a && count - 1 <= INT_MAX)
            return count - 1;
        else
            return INT_MAX;
    }
    else
    {
        if (sum == a && 0 - count >= INT_MIN)
            return 0 - count;
        else if (sum > a && 0 - count + 1 >= INT_MIN)
            return 0 - count + 1;
        else
            return INT_MAX;
    }
}

int main()
{
    cout << divide(INT_MIN, -1);
    return 0;
}
