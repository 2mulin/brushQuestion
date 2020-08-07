/********************************************************************
 * @author reddragon
 * @date 2020/5/29
 * @brief
 * 利用数学公式转换，x的平方根等于x的1/2次方，
 * 就等于e的lnx次方的1/2次方，就等于e的1/2*lnx次方
********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return 0;
    }
    int ans = exp(0.5 * log(x));
    return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
}

int main()
{
    return 0;
}