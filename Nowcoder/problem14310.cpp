// problem14310.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    char arr[100] = { 0 };
    char ch;
    int index = 0;
    while (cin.get(ch))
    {
        if (ch == '\n')
            break;
        else
        {
            arr[index++] = ch;
        }
    }
    for (int i = index - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << std::endl;
    return 0;
}