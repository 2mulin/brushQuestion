/***********************************************************
 * @date 2020/6/7
 * @author redragon
 * @description: 动态规划 midden
 * dp二维数组表示i到j的字串是不是回文
 * 状态转移方程：dp[i][j] = dp[i+1][j-1] + 2;
 * dp[i+1] == dp[j-1] 决定了 i到j是不是回文。
 * 因为如果[i,j]是回文，[i+1,j-1]必然也是回文
 * 
 * midden，动态规划不是最优解，时间：O(n2),空间：O(n2)
 * 还有一个中心扩展算法。时间：O(n2),空间：O(1)
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    size_t len = s.length();
    if (len <= 1)
        return s;
    /**
     * @param len 数组长度
     * @param vector<bool>(len,0) 数组元素初始值
     */
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int ansX = 0, ansY = 0;
    // 一个字母肯定是回文
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    // 两个相同字母也是回文
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 2;
            ansX = i;
            ansY = i + 1;
        }
    }
    // 0行开始，倒数第二行结束。第二列开始，直到最后一列.
    for (int i = 2; i < len; i++)
    { // i表示列，j表示行
        // 走斜的
        for (int j = 0, k = i; j < len - i; j++, k++)
        {
            if (dp[j + 1][k - 1] > 0 && s[j] == s[k])
            {
                dp[j][k] = dp[j + 1][k - 1] + 2;
                if (dp[j][k] > dp[ansX][ansY])
                {
                    ansX = j;
                    ansY = k;
                }
            }
        }
    }
    return s.substr(ansX, dp[ansX][ansY]);
}

int main()
{
    cout << longestPalindrome("babad");
    return 0;
}