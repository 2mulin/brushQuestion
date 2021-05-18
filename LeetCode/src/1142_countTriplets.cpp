/*
 * @author ling
 * @date 2021/5/18
 * @brief medium 相等的异或三元组
 * 
 * 首先定义数组arr的异或前缀和S(S[i] 表示 arr[0]^arr[1]^arr[2]....arr[i-1])
 * 由于异或运算的交换律和结合律以及一个数异或自身等于0
 * S[i] ^ S[j] = arr[i]^arr[i+1]^....^arr[j-1]
 * 所以题目要求可以被抽象为a = S[i] ^ S[j],   b = S[j] ^ S[k + 1]
 * a == b 即是 S[i] ^ S[j] == S[j] ^ S[k + 1]
 *          即 S[i] == S[k + 1]
 * 
 * 1. 三重循环
 * 首先计算出异或前缀和, 然后枚举i,j,k的位置。最后确定S[i], S[k + 1]是否相等。
 * 时间复杂度： O(N^3)        空间复杂度：O(N)
 * 
 * 2. 二重循环
 * 时间复杂度： O(N^2)        空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

// 三重循环
int countTriplets(vector<int> &arr) 
{
    int sz = arr.size();
    // 异或前缀和
    vector<int> S(sz + 1, 0);
    for(int i = 1; i < sz + 1; ++i)
        S[i] = arr[i] ^ S[i - 1];
    int ans = 0;
    // 暴力枚举
    for(int i = 0 ; i < sz; ++i)
    {
        for(int j = i + 1; j < sz; ++j)
        {
            for(int k = j; k < sz; ++k)
            {
                if(S[i] == S[k + 1])
                    ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}