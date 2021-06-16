/**
 * @author ling
 * @date 2021/6/16
 * @brief easy 山脉数组最高的索引
 * 
 * 1.递归
 * 每次两种情况, 一种选数组开头, 一种是选数组结尾的元素. 递归尝试每种情况, 每次都使用返回值最大
 * 的那一个就好了. 这里递归返回值两者之差, 如果是正数, 说明a赢,否则b赢
 * 时间复杂度：O(2*N)             空间复杂度：O(1)
 * 
 * 2.动态规划
 * 定义一个dp二维数组, dp[i][j]表示从piles[i~j]选取元素, 两者之差.
 * 显然, 如果i==j, 那就是一个元素, 那就只能是a选.
 * j > i 没有意义, 只能是0.
 * i > j 时:
 *              dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
 * 时间复杂度: O(N)          空间复杂度: O(N*N)
 * 
 * 3. 数学
 * 实际上先选的立于不败之地, 一定返回true.
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool stoneGame(vector<int> &piles)
{
    int len  = piles.size();
    auto dp = vector<vector<int>>(len, vector<int>(len, 0));
    for(int i = 0; i < len; ++i)
    {
        dp[i][i] = piles[i];
    }
    for(int i = len - 2; i >= 0; --i)
    {
        for(int j = i + 1; j < len; ++j)
        {
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
    }
    return dp[0][len - 1] > 0;
}

/* int recursion(const vector<int> &piles, bool aOrb, int i, int j)
{
    if(i == j)
        return piles[i];
    else
    {
        if(aOrb)
        {
            int ret1 = piles[i] + recursion(piles, false, i + 1, j);
            int ret2 = piles[j] + recursion(piles, false, i, j -1);
            return max(ret1, ret2);
        }
        else
        {
            int ret1 = -piles[i] + recursion(piles, true, i + 1, j);
            int ret2 = -piles[j] + recursion(piles, true, i, j -1);
            return max(ret1, ret2);
        }
    }
}

bool stoneGame(vector<int> &piles)
{
    return recursion(piles, true, 0, piles.size() - 1) > 0;
} */

int main()
{
    vector<int> piles{5, 3, 4, 5};
    cout << stoneGame(piles) << endl;
    return 0;
}