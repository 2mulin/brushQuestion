/********************************************************************
 * @author reddragon
 * @date 2020/7/15
 * @brief
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 1.其实就是一个卡特兰数
 * 2.也可以用动态规划做，就是先选择root，再将左子树的可能乘上右子树的可能
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // 选取root
        for (int j = 1; j <= i; j++)
        {
            // 左子树的可能乘上右子树的可能
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }
    return dp[n];
}

int main()
{
    cout << numTrees(5) << endl;
    return 0;
}