/**
 * @date 2022/6/30
 * @author 2mu
 * @brief easy 质数排列
 *
 * 1. 排列组合
 * 要求质数全部放在质数索引上。（隐藏题意：剩下就是合数和合数索引了，所以合数必须全部放在合数索引上）
 * 利用排列组合公式,首先确定n范围内有多少质数。假设有x个,那么x个的位置是确定的,其它n-x数的位置随便选。
 *
 * 所以满足条件的质数排列种类数是 n(n-1)(n-2)...(n-x+1), 由于 1 <= n <= 100,所以100以内质数写死。直接加速。合数排列种类数同理
 * 
 * 合法排列总数就是 质数排列数 * 合数排列数 
 * 
 * 时间复杂度: O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 100以内的质数
std::vector<int> PrimeNums = {
    2,3,5,7,11,13,17,19,23,
    29,31,37,41,43,47,53,59,
    61,67,71,73,79,83,89,97
};


int numPrimeArrangements(int n)
{
    int count = 0;  // 小于n的质数个数
    for(int i = 0; i < PrimeNums.size(); ++i)
    {
        if(PrimeNums[i] <= n)
            ++count;
        else
            break;
    }

    long long num = 1; 
    // 质数 合法排列种类数
    for(int i = count; i > 1; --i)
    {
        num *= i;
        num = num % int(1e9 + 7);
    }

    // 合数 合法排列种类数
    for(int i = n - count; i > 1; --i)
    {
        num *= i;
        num = num % int(1e9 + 7);
    }

    int result = num % int(1e9 + 7);
    return result;
}

int main()
{
    std::cout << numPrimeArrangements(5) << std::endl;
    std::cout << numPrimeArrangements(100) << std::endl;
    return 0;
}
