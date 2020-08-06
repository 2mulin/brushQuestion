// problem16589.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目：机器翻译 链接：https://ac.nowcoder.com/acm/problem/16589
// 运用了双端队列，可以在头插入，删除，也可以在尾部插入，删除

#include <iostream>
#include <deque>
using std::deque;
using std::cin;
using std::cout;

int main()
{
    int m, n;
    cin >> m >> n;
    deque<int> q;                           //存放存入内存的单词,最多存入m个
    int ans = 0;                            //记录查询次数
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        if (q.empty())
        {
            q.push_back(num);
            ans++;
        }
        else
        {
            bool isExist = false;
            int max = q.size();
            for (int i = 0; i < max; i++)
            {
                int x = q.front();
                if (x == num)               //无需查找，内存中有
                    isExist = true;
                q.pop_front();
                q.push_back(x);
            }
            if (!isExist)                   //如果内存中没有，加入内存
            {
                ans++;
                if (q.size() >= m)          //超过最大存储
                    q.pop_front();
                q.push_back(num);
            }
        }
    }
    cout << ans << std::endl;
    return 0;
}
