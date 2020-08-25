/*******************************************************************************
 * @author reddragon
 * @date 2020/8/24
 * @brief esay 重复字符串
 * 注意方法一，真的很细节。
********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// 方法一: 如果s重复，那么两个ss找到的s位置肯定不s.length之前就找到一个
bool repeatedSubstringPattern(string s)
{
    // 不要从0开始
    return (s + s).find(s, 1) < s.length();
}

// 方法二: 枚举所有子串
bool repeatedSubstringPattern(string s)
{
    if (s.empty())
        return false;
    int len = 1; //子串长度
    int p1 = 0, p2 = 1;
    while (p2 < s.length() && len <= s.length())
    {
        if (s[p1] != s[p2])
        {
            p1 = 0;
            p2 = ++len;
        }
        else
        {
            p1++;
            p2++;
        }
    }
    if (len > s.length() / 2 || s.length() % len != 0)
        return false;
    return true;
}

int main()
{
    string s = "ababab";
    cout << repeatedSubstringPattern(s) << endl;
    return 0;
}