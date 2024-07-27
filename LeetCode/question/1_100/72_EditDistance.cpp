/********************************************************************************************
 * @author reddragon
 * @date 2021/4/13
 * @brief hard 编辑距离
 * 
 * 1，枚举
 * 也就是每次都把三种方法试一遍, 插入,删除,替换都尝试一遍。
 * 时间复杂度: O()          空间复杂度: O(1)
 * 
 * 2. dp
 * 在枚举中可以发现出现了大量的重复计算。
 * 定义dp[i][j]表示 a[0~i] 到 b[0~j] 的最短距离
 * 根据这些就可以写出状态转移方程了。
 * 如果字符串a[i] == b[j]
 *          dp[i][j] = dp[i - 1][j - 1]
 *  否则
 *          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i][j]);
 * 可能最开始会觉得这里面应该有 6 种状态，a中插入，a中删除，b中插入，b中删除，a替换，b替换
 * 仔细去分析就可以得出 a插入 和 b删除， a删除 和 b插入， a替换 和 b替换
 * 两两一组是重复的， 所以最后只有3组。
 * 时间复杂度： O(mn)         空间复杂度：O(mn)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// 动态规划
int minDistance(string word1, string word2)
{
    auto len1 = word1.size(), len2 = word2.size();
    // 初始化(一个是第一行和第一列初始化为长度, 其它位置初始化为0)
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    for(int i = 0; i < len1 + 1; ++i)
        dp[i][0] = i;// 第一列初始化
    for(int j = 0; j < len2 + 1; ++j)
        dp[0][j] = j;// 第一行初始化
        
    // dp
    for(int i = 1; i < len1 + 1; ++i)
    {
        for(int j = 1; j < len2 + 1; ++j)
        {
            if(word1[i- 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                // 插入删除, dp[i - 1][j - 1]表示替换
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i - 1][j - 1]);
        }
    }
    return dp[len1][len2];
}

/* // 递归解法
int minDistance(string word1, string word2)
{
    size_t len1 = word1.length(), len2 = word2.length();
    if(len1 == 0 || len2 == 0)
        return max(len1, len2);
    
    if(word1.back() == word2.back())
    {
        return minDistance(word1.substr(0, len1 - 1), word2.substr(0, len2 - 1));
    }

    // 删除替换全部尝试一遍(删除和替换操作本质上是一样的)
    return 1 + min(minDistance(word1, word2.substr(0, len2 - 1)), 
                    min( minDistance(word1.substr(0, len1 - 1), word2),
                    minDistance(word1.substr(0, len1 - 1), word2.substr(0, len2 - 1)))
                );
} */

int main()
{
    cout << minDistance("abs", "ab") << endl;
    return 0;
}