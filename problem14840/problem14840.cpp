// problem14840.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目链接：https://ac.nowcoder.com/acm/problem/14840

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    long long n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << ans;
    return 0;
}
