// problem14703.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

bool isPrime(long long num)
{
    if (num % 6 != 1 && num % 6 != 5)
        return false;
    long long limit = sqrt(num);
    for (long long i = 5; i <= limit; i+=6)                //注意不能加过头,自己一个比自己大的数取余肯定是0
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long t, x;
    cin >> t;
    x = t;
    int num = t % 10;
    t = (t - num) / 10;
    while (t > 9)
    {
        num = t % 10;
        x = x * 10 + num;
        t = (t - num) / 10;
    }
    x = x * 10 + t;
    if (isPrime(x))
        cout << "prime";
    else
        cout << "noprime";
    return 0;
}