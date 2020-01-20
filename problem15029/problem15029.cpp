// problem15029.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目链接：https://ac.nowcoder.com/acm/problem/15029

#include <iostream>
#include <stack>
using std::stack;
using std::cin;
using std::cout;

stack<char> s;

void s_Push(char ch)
{
    if (s.empty()||s.top()!=ch)
        s.push(ch);
    else
    {
        switch (ch)
        {
        case 'O':
                s.pop();
            break;
        case 'o':
                s.pop();
                s_Push('O');
            break;
        default:break;
        }
    }
}

int main()
{
    char ch;
    while (cin.get(ch))
    {
        if (ch == '\n' || ch == '\0'||ch==' ')
        {
            int size = s.size();
            if (size == 0)
                cout << std::endl;
            else
            {
                char* ans = new char[size];
                for (int i = size - 1; i >= 0; i--)
                {
                    ans[i] = s.top();
                    s.pop();
                }
                for (int i = 0; i < size; i++)
                    cout << ans[i];
                cout << std::endl;
                delete ans;
            }
        }
        else
        {
            s_Push(ch);
        }
    }
    return 0;
}
