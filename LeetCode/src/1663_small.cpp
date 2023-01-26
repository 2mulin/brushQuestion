/**
 * @date 2022/1/26
 * @author 2mu
 * @brief medium 具有给定数值的最小字符串
 * 
 * 一、暴力枚举
 * 直接枚举+回溯，枚举每一种情况，一旦和大于指定k，说明当前字符串不合法，如果合法，则和已经
 * 确认合法的字符串比较字典序。取最小的。
 * 
 * 肯定超时，26的n次方
 * 
 * 二、数学+贪心
 * 
 * 这是一道贪心，但是先要看出数学公式，最终转化。得到每个字符的取值范围，否则没有办法做。
 * 看官方题解，确实牛逼，很难想到数学公式确定取值范围。
 *
 * 时间复杂度：O(m)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string getSmallestString(int n, int k)
{
    string ans;
    for(int i = 1; i <= n; ++i)
    {
        int lower = max(1, k - (n - i) * 26);
        k -= lower;
        ans.push_back('a' + lower -1);
    }
    return ans;
}

int main()
{

    return 0;
}
