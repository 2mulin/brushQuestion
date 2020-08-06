/*******************************************************
 * @author reddragon
 * @date 2020/7/15
 * @description:
 * 快速幂：时间复杂度：O(logN) 空间复杂度：O(1)
 * 注意细节，比如n==INT_MIN的话，-n会越界
 ******************************************************/
#include <iostream>
using namespace std;

double __pow(double x, long long n)
{
    double ans;
    if (n == 1)
        return x;
    else
    {
        if (n % 2)
            ans = __pow(x, n - 1) * x;
        else
        {
            ans = __pow(x, n / 2);
            ans *= ans;
        }
    }
    return ans;
}

double myPow(double x, int n)
{
    if (n == 0 || x == 1)
        return 1;
    // 防止n==INT_MIN,则-n会越界
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    if (N == 1)
        return x;
    // 快速幂
    return __pow(x, N);
}

int main()
{
    cout << myPow(2.5564, 56) << endl;
    return 0;
}