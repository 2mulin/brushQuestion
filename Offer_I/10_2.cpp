/**
 * @date 2022/8/7
 * @author 2mu
 * @brief easy 青蛙跳台阶
 *
 * 1. dp
 * 经典dp，递推找到规律就可以了。不多bb。
 * 
 * 可以发现规律，设置一个dp数组，假设dp[i]即跳上第i阶台阶的方法数。
 * 
 * 那么dp[i] = dp[i-1] + dp[i-2];
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 2. 优化空间
 * 
 * 显然，只需要维护前面dp[i-1]和dp[i-2]两个状态即可，不需要维护dp数组。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>

using namespace std;

int numWays(int n)
{
    long long a = 1, b = 0;
    for(int i = 1; i <= n; ++i)
    {
        a = a + b;
        b = a - b;
        a = a % 1000000007;
        b = b % 1000000007;
    }
    return a;
}

int main()
{
    std::cout << numWays(1) << std::endl;
    std::cout << numWays(2) << std::endl;
    return 0;
}
