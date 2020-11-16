/********************************************************************************************
 * @author reddragon
 * @date 2020/11/16
 * @brief hard POJ 2192 Zipper
 * 
 * 1. 递归
 *   首先分析题意：如果A串和B串能够合成C串。那么C串的 尾字母 一定是A串或者B串的  尾字母。
 * 得到这一点非常重要，接下来就可以直接写成递归了。要注意可能a和b的最后一个字母同时和c的最后一个字母
 * 相同的情况，需要特别处理处理。
 * 其它的就是一些简单的剪枝
 * 时间复杂度：O(m+n)   当然函数调用也有开销，这里不好计算
 * 空间复杂度：O((m+n)的平方)   显然非常浪费空间
 * 
 * 2. 动态规划
 *   如上所述，首先分析题意，如果A、B串能合成C串，那么必定A或者B串的首字母和C串的 首字母 相同。
 * 状态是，dp[i][j]表示“a串的前i个字母”和“b串的前j个字母”是否能够组成“C串的前i+j个字母”
 * 状态转移方程：
 *         dp[i][j]=  {dp[i - 1][j]为真，并且a串的第i个字母和c串的第i+j字符相等}或者
 *                    {dp[i][j - 1]为真，并且b串的第i个字符和c串的第i+j字符相等}则dp[i][j]为真
 * 时间复杂度：O(m*n)           空间复杂度：O(m*n)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool judge(string a, string b, string c)
{
    int lenA = a.length(), lenB = b.length();
    vector<vector<bool> > dp(lenA + 1, vector<bool>(lenB + 1, false));
    dp[0][0] = true;
    // 初始化第一列
    int i = 1;
    while(i <= lenA && a[i - 1] == c[i - 1])
        dp[i++][0] = true;
    // 初始化第一行
    i = 1;
    while(i <= lenA && b[i - 1] == c[i - 1])
        dp[0][i++] = true;
    // dp
    for(int i = 1; i <= lenA; ++i)
    {
        for(int j = 1; j <= lenB; ++j)
        {
            if(dp[i][j - 1] && b[j - 1] == c[i + j - 1])
                dp[i][j] = true;
            else if(dp[i - 1][j] && a[i - 1] == c[i + j - 1])
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }
    return dp[lenA][lenB];
}
/* 
bool judge(string a, string b, string c)
{
    if(a.empty() && b.empty() && c.empty())
        return true;
    
    if(!a.empty() && !b.empty() && !c.empty())
    {
        // a和b的最后一个字母都是c的最后一个字母
        if(a.back() == b.back() && a.back() == c.back())
        {
            char ch = a.back();
            a.pop_back();
            c.pop_back();
            if(judge(a, b, c))
                return true;

            a.push_back(ch);
            b.pop_back();
            if(judge(a, b, c))
                return true;
            else
                return false;
        }
        else if(a.back() == c.back())
        {
            a.pop_back();
            c.pop_back();
            return judge(a, b, c);
        }
        else if(b.back() == c.back())
        {
            b.pop_back();
            c.pop_back();
            return judge(a, b, c);
        }
        else
            return false;
    }
    else
    {
        if(a.empty())
        {
            if(b == c)
                return true;
            else
                return false;
        }
        else if(b.empty())
        {
            if(a == c)
                return true;
            else
                return false;
        }
        else
            return false;
    }
} */

int main()
{
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        string a,b,c;
        cin >> a >> b >> c;
        bool ans = judge(a,b,c);
        cout << "Data set " << i << ": ";
        if(ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}