// problem16464.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目：神奇的幻方 题目链接：https://ac.nowcoder.com/acm/problem/16464

#include <iostream>
using std::cin;
using std::cout;

const int N = 40;

int main()
{
    int n;
    cin >> n;
    int arr[N][N]{ 0 };
    int x = 1, y = n / 2 + 1;
    for (int i = 1; i <= n * n; i++)
    {
        arr[x][y] = i;
        if (x == 1 && y != n)
        {
            x = n;
            y += 1;
        }
        else if (x != 1 && y == n)
        {
            x -= 1;
            y = 1;
        }
        else if (x == 1 && y == n)
        {
            x += 1;
        }
        else if (x != 1 && y != n && !arr[x - 1][y + 1])
        {
            x -= 1;
            y += 1;
        }
        else
        {
            x += 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << arr[i][n] << std::endl;
    }
    return 0;
}

