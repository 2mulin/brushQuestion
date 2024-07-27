/******************************************************
 * @author reddragon
 * @date 2020/8/25
 * @brief hard 交错字符串
 * 动态规划，还可以使用滚动数组优化一下空间
 * 时间O(mn)   空间O(mn)
******************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if (len1 + len2 != len3)
        return false;

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            int p = i + j - 1;
            // row
            if (i > 0)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[p]) || dp[i][j];
            // col
            if (j > 0)
                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[p]) || dp[i][j];
        }
    }
    return dp[len1][len2];
}

int main()
{
    cout << isInterleave("aabcc","dbbca","aadbbcbcac") << endl;
    return 0;
}