/**
 * @date 2025/7/4
 * @author 2mu 
 * @brief hard 找出第 K 个字符 II
 *
 * 1. 利用数学
 * 利用数学思路，定位最终k位的字母是从哪个位置得来的，然后计算总共经历几次变化。
 * 
 * 数学公式：k = 2的t次方 + 'a'
 * t表示经历几次变化，计算出t的值，就可以得到k。
 * 
 * 还是似懂非懂，没弄懂到底是怎么计算的...
 * 
 * 时间复杂度：O(logN)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char kthCharacter(long long k, vector<int>& operations)
{
    int ans = 0;
    while(k != 1)
    {
        int t = __lg(k);
        if ( ((long long)1 << t) == k)
        {
            t--;
        }
        k = k - ((long long)1 << t);
        if (operations[t])
        {
            ans++;
        }
    }
    return 'a' + (ans % 26);
}


int main()
{
    std::vector<int> operations{0,0,0};
    std::cout << kthCharacter(5, operations) << std::endl;
    return 0;
}
