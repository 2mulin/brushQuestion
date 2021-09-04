/**
 * @author: ling
 * @date: 2021/9/4
 * @brief: easy 斐波那契数斐波
 * 1. 动态规划
 * 不用多说
 * 2. 矩阵快速幂
 */

#include <iostream>
using namespace std;

int fib(int n)
{
	int a = 0, b = 1;
	int mod = 1e9+7;
	while(n--)
	{
		a = a + b;
		b = a - b;
		a %= mod;
		b %= mod;
	}
	return a;
}

int main()
{
	for(int i = 0; i < 10; ++i)
	{
		std::cout << fib(i) << endl;
	}
	return 0;
}
