// problem24876.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目：Cow Line （双端队列）  链接：https://ac.nowcoder.com/acm/problem/24876

#include <iostream>
#include <deque>
using std::deque;
using std::cin;
using std::cout;

int main()
{
    int s;                          //命令个数
    int count = 1;                  //进场奶牛个数
    cin >> s;
    deque<int> q;
    for (int i = 1; i <= s; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A')
        {
            char dir;
            cin >> dir;
            if (dir == 'L')
                q.push_front(count);
            else
                q.push_back(count);
            count++;
        }
        else
        {
            char dir;
            cin >> dir;
			int num;
			cin >> num;
			while (num--)
			{
                if (dir == 'L')
                    q.pop_front();
                else
                    q.pop_back();
			}
        }
    }
    while (!q.empty())
    {
        cout << q.front() << std::endl;
        q.pop_front();
    }
    return 0;
}