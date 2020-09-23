/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/23
 * @brief easy 验证回文串
 * 1. 暴力
 * 先把字符串转化为可以判断的字符串。然后一个for循环解决
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 
bool isPalindrome(string s)
{
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            str.push_back(s[i]);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            str.push_back(s[i] + 32);
        else if (s[i] >= '0' && s[i] <= '9')
            str.push_back(s[i]);
        else
            continue;
    }

    bool ans = true;
    int len = str.length();
    if (len == 0)
        return true;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    cout << isPalindrome("aaabaaa") << endl;
    return 0;
}