/****************************************************************
 * @date 2020/7/5
 * @author reddragon
 * @description: hard 最长括号匹配
 * 暴力解法：
 * 遍历每一种可能，每一种可能都去判断一下是否满足 O(n3)
 * 
 * 动态规划：
 * dp数组，dp[i]表示到第i位有效的最长的()串的长度
 * 第一个结论：'(‘对应的dp数组的位置一定是0，无法配对
 * 状态转移方程：dp[i] = 2 + dp[i - 1] + dp[i -dp[i-1] - 2]
 * 记得判断边界，状态转移时也要判断
 * 时间复杂度：O(n),空间复杂度：O(n)
 * 
 * 栈
 * 时间复杂度：O(n),空间复杂度：O(n)
 * 
 ***************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
    int len = 0, maxLen = 0;
    stack<int> sta;
    sta.push(-1);
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            sta.push(i);
        else
        {
            sta.pop();
            if (sta.empty())
            {
                maxLen = len > maxLen ? len : maxLen;
                // i成为新的起点
                sta.push(i);
            }
            else
            {
                len = i - sta.top();                  //长度只能这样算，不然不对
                maxLen = len > maxLen ? len : maxLen; //必不可少
            }
        }
    }
    return maxLen;
}

/***************************************************************************
int longestValidParentheses(string s)
{
    int len = s.length();
    vector<int> dp(len, 0);
    for (int i = 1; i < len; i++)
    {
        if (s[i] == '(') //第一个结论
            dp[i] = 0;
        else
        {
            if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = 2 + dp[i - 1];
                // 前面可能有刚好能连起来的括号串
                if (i - dp[i - 1] - 2 >= 0)
                    dp[i] += dp[i - dp[i - 1] - 2];
            }
        }
    }
    int max = 0;
    for (int i = 0; i < len; i++)
        if (dp[i] > max)
            max = dp[i];
    return max;
}
***************************************************************************/

/**************************************************************
 * 暴力法  O(n)
bool isLegal(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
            s.push(str[i]);
        else if (s.top() == '(' && str[i] == ')')
            s.pop();
        else
            s.push(str[i]);
    }
    return s.empty();
}
int longestValidParentheses(string s)
{
    int len = s.length();
    if (len <= 0)
        return 0;
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if ((len - i) % 2)
            continue; //单数肯定不匹配
        bool isAns = false;
        for (int j = 0; j <= i; j++)
        {
            isAns = isLegal(s.substr(j, len - i));
            if (isAns)
                break;
        }
        if (isAns)
        {
            ans = len - i;
            break;
        }
    }
    return ans;
}
*********************************************************/
int main()
{
    cout << longestValidParentheses("())(())");
    return 0;
}