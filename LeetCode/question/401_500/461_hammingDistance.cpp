/********************************************************************************************
 * @author reddragon
 * @date 2021/3/14
 * @brief 汉明距离 easy
 * 1. 暴力
 * 直接求数字的二进制表示, 然后比较有多少个位不相同, 最后输出
 * 时间复杂度: O(N)         空间复杂度: O(N)
 * 
 * 2. 异或
 * 题目要求两个数二进制位上的不同, 先使用异或操作, 两数所有不同的位都变成1了
 * 接下来只要求出这一个数的1 有几个就好了
 * 时间复杂度: O(N)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 异或, 移位计数
int hammingDistance(int x, int y)
{
    int tmp = x ^ y;
    int ans = 0;
    while (tmp)
    {
        if (tmp & 1)
            ++ans;
        tmp >>= 1;
    }
    return ans;
}
/* 暴力法
inline string retBinary(int x)
{
    if (x == 0)
        return "0";
    string ret;
    while (x != 0)
    {
        ret.push_back(x % 2 + '0');
        x /= 2;
    }
    return ret;
}

int hammingDistance(int x, int y)
{
    string a = retBinary(x);
    string b = retBinary(y);
    while (a.size() != b.size())
    {
        if (a.size() < b.size())
            a.push_back('0');
        else
            b.push_back('0');
    }
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            ++ans;
    }
    return ans;
} */
int main()
{
    cout << hammingDistance(1, 4) << endl;
    return 0;
}
