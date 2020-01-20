// problem20660.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//真正的记忆化搜索，提高运行速度：https://ac.nowcoder.com/acm/problem/20660

#include <iostream>
using std::cin;
using std::cout;

long long arr[1001];

long long function(long long n)
{
    if (arr[n] != 0)
        return arr[n];
    else
        arr[n] = (2 * function(n - 1) + 3 * function(n - 2) + n) % 1000000007;
    return arr[n];
}

int main()
{
    arr[1] = 1;
    arr[2] = 2;
    while (1)
    {
        long long n;
        cin >> n;
        if (n == 0)
            break;
        cout << function(n) << std::endl;
    }
    return 0;
}
