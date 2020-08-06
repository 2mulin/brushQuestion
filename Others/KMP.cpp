#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// next数组是一种递进的关系，即next[i]是由next[i-1]决定的
int *BuildNext(const string p)
{
    int len = p.length(); // i为p的索引
    int *next = new int[len];
    int t = next[0] = -1, i = 0; // next[0] = -1
    while (i < len - 1)
    {
        if (-1 == t || p[i] == p[t]) // t等于-1说明到头了，没有出现与next[++i]重复的字符，next[++i]设置为0就好了
        {
            next[++i] = ++t; //原版
            // 下面是改进版
            //++i;
            //++t;
            //next[i] = (p[i] != p[t] ? t : next[t]);
            /*
            * 文本串： 0 0 0 1 0 0 0 0 1
            * 模式串： 0 0 0 0 1
            * 原版的next数组：  -1  0  1  2 3
            * 改进后的next数组：-1 -1 -1 -1 3
            */
        }
        else
            t = next[t];
    }
    return next;
}

int match(const string t, const string p)
{
    int *next = BuildNext(p); //构造next数组
    int i = 0, j = 0;
    int tLen = t.length(), pLen = p.length();
    while (i < tLen && j < pLen)
    {
        if (-1 == j || t[i] == p[j]) // j等于-1说明是模式串从头开始比较
        {
            i++;
            j++;
        }
        else // p右移（p回退,也可能不动，需要看next[j]的值），t不回退
            j = next[j];
    }
    delete[] next;
    return i - j;
}

int main()
{
    string s1 = "000100001", s2 = "00001";
    int ans = match(s1, s2);
    cout << ans << endl;
    int *arr = BuildNext("ababaaa");
    for (int i = 0; i < 7; i++)
        cout << arr[i] << '\t';
    return 0;
}