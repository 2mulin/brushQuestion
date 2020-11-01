/********************************************************************************************
 * @author reddragon
 * @date 2020/11/1
 * @brief POJ 简单的整数划分问题
 * 
 * 现在官网好像找不到这个题了，
 * 
 * 1. 递归
 * 好像做过，以前用过穷举的方法。
 * 这次学的递归，就用一下递归的思想，给一个数，划分成几种表达式，和还是这个数
 * 写了一个递归函数，每次选择从大到小选择一个数，后面选的数都要比他小（防止重复，比如5=4+1，5=1+4）
 * 
 * 时间复杂度：O(N)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;

int fun(int n, int max)
{
    if(n == 0)
        return 1;
    int ans = 0;
    // 取最小值的原因是防止重复的划分
    for(int i = std::min(n,max); i > 0; --i)
    {
        ans += fun(n - i, i);
    }
    return ans;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << fun(n, n) << std::endl;
    }
    return 0;
}