/****************************************************
 * @author reddragon
 * @date 2020/7/29
 * @brief hard 编辑距离
 * 首先应该想出递归的解法，然后在递归中分析子问题，
 * 得到动态规划的解法，写出状态转移方程。
 ***************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 动态规划，自底向上
// dp[i][j]表示从word[0-i]到word[0-j]最多需要多少次编辑
int minDistance(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    if (len1 == 0 || len2 == 0)
        return max(len1, len2);
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    // 初始化第一行
    for (size_t i = 0; i < len2 + 1; i++)
        dp[0][i] = i;
    // 初始化第一列
    for (size_t i = 0; i < len1 + 1; i++)
        dp[i][0] = i;

    // dp
    for (int i = 1; i < len1 + 1; i++)
    {
        for (int j = 1; j < len2 + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    return dp[len1][len2];
}

// 递归解法。自顶向下，每次去除末尾一个字符
int minDistanceCopy(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    // 如果一方提前为0，说明只要进行插入或者删除操作就好了
    if (len1 == 0 || len2 == 0)
        return max(len1, len2);
    // 相同，直接抵消
    if (word1.back() == word2.back())
    {
        word1.pop_back();
        word2.pop_back();
        return minDistanceCopy(word1, word2);
    }
    // 插入
    int a1 = minDistanceCopy(word1, word2.substr(0, len2 - 1));
    // 删除
    int a2 = minDistanceCopy(word1.substr(0, len1 - 1), word2);
    // 替换
    word1.pop_back();
    word2.pop_back();
    int a3 = minDistanceCopy(word1, word2);
    return 1 + min(a1, min(a2, a3));
}

int main()
{
    cout << minDistance("horse", "ros") << endl;
    cout << minDistanceCopy("horse", "ros") << endl;
    return 0;
}