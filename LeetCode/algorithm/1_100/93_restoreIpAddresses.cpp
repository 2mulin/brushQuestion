/*******************************************************************************
 * @author reddragon
 * @date 2020/8/9
 * @brief medium IP地址
 * 就是一个回溯，要考虑全面并且把代码写的简洁清楚,可能有点难
 * 
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;
// 记录没有插入'.'之前的string长度
int len = 0;

/**********************************************
 * @param s IP字符串
 * @param pos 当前处理的string位置
 * @param sum 最后一个点到当前位置的数字有多大
**********************************************/
void backTrace(string s, int pos, int sum)
{
    if(sum > 255)
        return ;
    if (pos == len + 3)
    {
        if(s[pos - 1] != '.')
            ans.push_back(s);
        return;
    }
    else
    {
        if (s.length() == len + 3)
        {
            if (s[pos - 1] == '0' && s[pos - 2] == '.')
                return; // 0 不能在数字开头
            sum *= 10;
            sum += s[pos] - '0';
            backTrace(s, pos + 1, sum);
            return;
        }
        // 是0，直接在后面打点，所以0出现数字开头，只可能在最后一个数（最后八位）
        if (s[pos] == '0')
        {
            string temp = s;
            temp.insert(pos + 1, 1,'.');
            backTrace(temp, pos + 2, 0);
            return;
        }
        // 回溯
        int num = 0;
        num = s[pos++] - '0';
        while (pos < s.length() && num <= 255)
        {
            string temp = s;
            temp.insert(pos, 1,'.');
            backTrace(temp, pos + 1, 0);
            num *= 10;
            num += (s[pos] - '0');
            pos++;
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    len = s.length();
    if(len >= 4)
        backTrace(s, 0, 0);
    return ans;
}

int main()
{
    string s = "0690";
    vector<string> arr = restoreIpAddresses(s);
    for(auto i : arr)
        cout << i << endl;
    return 0;
}