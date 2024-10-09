/***********************************************************
 * @date 2020/6/10
 * @author reddragon
 * @description: easy题，数字转化为字符串，然后判断是否是回文
 ***********************************************************/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    string s = to_string(x);
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome(121);
    return 0;
}