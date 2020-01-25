// problem13883.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 一星简单水题   题目链接：https://ac.nowcoder.com/acm/problem/13883

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, opCount;
        cin >> n >> opCount;
        int** arr = new int* [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n] {0};
        }
        while (opCount--)
        {
            int op, k, v;
            cin >> op >> k >> v;
            if (op == 1)
            {
                for (int i = 0; i < n; i++)
                    arr[k-1][i] = v;
            }
            if (op == 2)
            {
                for (int i = 0; i < n; i++)
                    arr[i][k-1] = v;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << arr[i][n-1] << std::endl;
        }
        delete[] arr;
    }
    return 0;
}
