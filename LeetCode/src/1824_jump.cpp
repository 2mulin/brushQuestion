/**
 * @date 2022/1/21
 * @author 2mu
 * @brief medium 最小侧跳次数
 * 
 * 一、动态规划
 * 当青蛙每次移动(包括向前, 或侧跳),都是一次状态的转变。使用 dp[i][j] 表示到达i号跑道的j号点 最小侧跳次数
 * 由题目已知: 青蛙初始位置, dp[1][0] 是0, 青蛙可以侧跳切换跑道, 所以 dp[0][0] = 1, dp[2][0] = 1,
 * 然后当前面和侧面青蛙碰到障碍物时, 只能侧跳, 用INF表示障碍, 先确定:
 * 
 * 当该位置不是障碍物时, d[i][j] = d[i][j - 1], 否则就是INF
 * 
 * 然后确定dp[i][j]最小值, 需要和其它上下位置进行比较, 因为可以侧跳切换位置.也就是:
 *  
 *  minCnf = min(dp[0][j], dp[1][j], dp[2][j])
 *  dp[i][j] = min(dp[i][j], minCnf + 1)
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF 9999999

int minSideJumps(vector<int> &obstacles)
{
    size_t sz = obstacles.size();
    // -1表示是障碍，不可达
    std::vector<std::vector<int>> dp(3, std::vector<int>(sz, 0));
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 1;
    for(size_t i = 1; i < sz; ++i)
    {
        int minCnf = INF;
        for(int j = 0; j < 3; ++j)
        {
            if(j == obstacles[i] - 1)
                dp[j][i] = INF; // 当前位置是障碍
            else
                minCnf = min(minCnf, dp[j][i - 1]);
        }
        for(int j = 0; j < 3; ++j)
        {
            if(j == obstacles[i] - 1)
                continue;
            else
                dp[j][i] = min(dp[j][i - 1], minCnf + 1);
        }
    }
    int ans = min(dp[0][sz - 1], dp[1][sz - 1]);
    ans = min(ans, dp[2][sz - 1]);
    return ans;
}

int main()
{
    std::vector<int> vct{0,1,2,3,0};
    std::cout << minSideJumps(vct) << std::endl;
    return 0;
}
