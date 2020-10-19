/********************************************************************************************
 * @author reddragon
 * @date 2020/10/19
 * @brief easy 比较含有退格的字符串
 * 
 * 1.重新构造两个没有退格的字符串
 * 时间复杂度：O(N)          空间复杂度：O(N)     N为两个字符串的长度之和
 * 
 * 2.从后往前遍历
 * 只需要以此遍历，并不需要额外空间
 * 时间复杂度：O(N)          空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 未完成
bool backspaceCompare(string S, string T)
{
    int i = S.size() - 1;
    int j = T.size() - 1;
    int Scount = 0;
    int Tcount = 0;
    while(i >= 0 && j >= 0)
    {
        while(S[i] == '#')
        {
            Scount++;
            i--;
        }
        i -= Scount;
        Scount = 0;
        while(T[j] == '#')
        {
            Tcount++;
            j--;
        }
        i -= Tcount;
        Tcount = 0;
        if(i < 0 || j < 0)
            return false;
        if(S[i] != T[j])
            return false;
        i--;
        j--;
    }
    return true;
}

/* bool backspaceCompare(string S, string T)
{
    string a, b;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != '#')
            a.push_back(S[i]);
        else
        {
            if (!a.empty())
                a.pop_back();
        }
    }
    for (int i = 0; i < T.length(); i++)
    {
        if (T[i] != '#')
            b.push_back(T[i]);
        else
        {
            if (!b.empty())
                b.pop_back();
        }
    }
    return a == b;
} */

int main()
{
    cout << backspaceCompare("1#w#", "1#w#") << endl;
    return 0;
}