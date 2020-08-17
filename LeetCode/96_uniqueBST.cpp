/********************************************************************
 * @author reddragon
 * @date 2020/7/15
 * @brief medium
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 1.其实就是一个卡特兰数
 * 
 * 2.也可以用动态规划做，就是枚举root，再将左子树的数目乘上右子树的数目
 * 显然这里，左右子树只和它的节点个数有关，和大小无关。因为从root分成两半
 * 一定是连续的。所以可以dp。
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
        // 选取root，可以是1到i
        for (int j = 1; j <= i; j++)
        {
            // 左子树有j-1个结点，右子树有i-j个结点
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