// problem13591.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 一个关于贪心的二星题目 链接：https://ac.nowcoder.com/acm/problem/13591

#include <iostream>
#include <algorithm>
using std::endl;
using std::cin;
using std::cout;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int* arr = new int[n] {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        std::sort(arr, arr + n);
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int sub = arr[i] > arr[i + 1] ? arr[i] - arr[i + 1] : arr[i + 1] - arr[i];
            if (sub < m)
            {
                ans++;
                i++;
            }
        }
        cout << ans << endl;
        delete[] arr;
    }

    return 0;
}