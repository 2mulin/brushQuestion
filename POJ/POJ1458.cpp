/********************************************************************************************
 * @author reddragon
 * @date 2020/11/15
 * @brief medium 最长公共子序列
 * 
 * 1. 动态规划
 * 就是递归改的动态规划，如果是当前字符相等，两个字符去掉，递归比较下一部分
 * 不然就是两种情况，去掉a的第一个字符，然后递归剩下的string。或者去掉b的第一个字符
 * 然后递归剩下的string。
 * 
 * 很难想到，特别是细节部分。细节全部在if else那一部分。
 * 如果当前两个字符相等，当前值加上上一个对角的值
 * 否则，就是左边或者上一个两个中的最大值
 * 时间复杂度：O(N*N)           空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        int len1 = s1.length(), len2 = s2. length();
        // 多一行一列省的初始化。初始化第一行和第一列还挺麻烦
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

        int ans = 0;
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
               if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i -1][j - 1] + 1;            // 如果相等，斜对角+1
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);// 不相等
                // 更新答案
                ans = max(dp[i][j], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}