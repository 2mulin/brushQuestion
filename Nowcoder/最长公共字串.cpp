/********************************************************************************************
 * @author reddragon
 * @date 2020/11/13
 * @brief medium 最长公共字串
 * 
 * 1.暴力
 * 先选出对应字符串的两个起点，然后看一下从这两个起点出发，相同的最多有多长，记录下来。
 * 时间复杂度：O(N*M*K)         空间复杂度：O(1)
 * 
 * 2. 动态规划
 * 利用一个二维数组，记录下来每个相等的位置。每一条斜对角线就是记录字串相等。
 * 时间复杂度：O(N*M)           空间复杂度：O(N*M)
 * 
 * 3.肯定有更好的方法，暂时想不到
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/* 暴力
 string LCS(string str1, string str2)
{
    // write code here
    if (str1.empty() || str2.empty())
        return "-1";
    // 暴力
    int len1 = str1.length();
    int len2 = str2.length();
    string ans;
    for (int i = 0; i < len1; ++i)
    { // str1起点
        for (int j = 0; j < len2; ++j)
        { // str2起点
            string temp;
            int pos1 = i, pos2 = j;
            while (pos1 < len1 && pos2 < len2 && str1[pos1] == str2[pos2])
            {
                temp.push_back(str1[pos1]);
                ++pos1;
                ++pos2;
            }
            if (temp.size() > ans.size())
                ans = temp;
        }
    }
    if (ans.empty())
        return "-1";
    return ans;
} */

string LCS(string str1, string str2)
{
    // write code here
    if (str1.empty() || str2.empty())
        return "-1";
    // 初始化
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    // 找到最大值
    int maxLen = 0, row = 0;
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if(maxLen < dp[i][j])
            {
                maxLen = dp[i][j];
                row = i - maxLen;
            }
        }
    }

    string ans;
    for (int i = row; i < maxLen + row; ++i)
    {
        ans.push_back(str1[i]);
    }
    if(ans.empty())
        return "-1";
    return ans;
}

int main()
{
    string s1 = "ABSBBS";
    string s2 = "11BBS6";
    cout << LCS(s1,s2) << endl;
    return 0;
}