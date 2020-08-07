/*********************************************************
 * @date 2020/5/22
 * @author reddragon
 * @description: easy
 * leetcode第38题，外观数列.题
 ********************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

string countAndSay(int n)
{
    string s = "11";
    if (n == 1)
        return "1";
    if (n == 2)
        return s;
    int count = 1; // 有多少个连续相等的数
    n -= 2;
    while (n--)
    {
        string temp;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
            {
                temp += static_cast<char>(count + '0');
                temp += s[i - 1];
                count = 1;
            }
        }
        temp += static_cast<char>(count + '0');
        temp += s[s.length() - 1];
        s = temp;
        count = 1;
    }
    return s;
}

int main()
{
    cout << countAndSay(5);
    return 0;
}