/********************************************************************************************
 * @author reddragon
 * @date 2021/2/6
 * @brief medium 完全平方数
 * 注意: 数字可以重复使用
 * 
 * 1. 枚举
 * 递归枚举所有的可能, 找到最大值, 想都不要想, 要写出来都非常麻烦了
 * 由于可以重复使用数字, 所以for循环要尝试每个合法的数字
 * numSquares(n) = min{   numSquares(n - k) + 1(每一个合法的k)   }
 * 时间复杂度：O(2的n次方)		空间复杂度：O(n)
 * 
 * 2. dp
 * 从枚举中, 可以看到每一个numSquares有关, 所以可以保存numSquares前面的值, 这样就不用像递归
 * 那样重复计算相同的值了
 * 时间复杂度: O(N)				空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int numSquares(int n)
{
	int len = static_cast<int>(sqrt(n) + 1);
	vector<int> square_num(len + 1);
	for(int i = 0; i <= len; ++i)
	{
		square_num[i] = i*i;
	}

	vector<int> dp(n + 1, INT_MAX); // numSquares[i]
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		// 枚举
		for(int j = 1; j < len; ++j)
		{
			if(i < square_num[j])
				break;
			// 遍历每一种可能
			dp[i] = min(dp[i], dp.at(i - square_num[j]) + 1);
		}
	}
	return dp[n];
}

int main()
{
	cout << numSquares(3) << endl;
	return 0;
}