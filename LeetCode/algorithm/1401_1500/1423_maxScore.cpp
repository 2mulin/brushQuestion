/********************************************************************************************
 * @author reddragon
 * @date 2021/2/6
 * @brief medium 可获得的最大值
 * 1. 枚举
 * 枚举所有的可能, 找到最大值
 * 时间复杂度：O(2的k次方)		空间复杂度：O(N)
 * 
 * 2. 滑动窗口
 * 逆向思维: 我们可以同通过求剩余手牌最小值, 再使用总和减去最小值, 得到最大值
 * 显而易见, 最小值就是长度为(n - k)的窗口, 窗口内和最小的子数组
 * 时间复杂度: O(N)				空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>				// 求和算法accmulate
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
	int len = cardPoints.size();
	int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);// 累加求和
	int windowVal = 0; // 窗口内数字之和
	for (int i = 0; i < len - k; ++i)
		windowVal += cardPoints[i];
	int ans = windowVal;
	int width = len - k; // 窗口宽度
	for (int i = width; i < len; ++i)
	{
		windowVal -= cardPoints[i - width];
		windowVal += cardPoints[i];
		ans = min(windowVal, ans);
	}
	return sum - ans;
}

// 枚举所有可能
// int maxSum(vector<int>::iterator itor1, vector<int>::iterator itor2, int k)
// {
// 	if (k == 0)
// 		return 0;
// 	return max(maxSum(itor1 + 1, itor2, k - 1) + *itor1,
// 			   maxSum(itor1, itor2 - 1, k - 1) + *itor2);
// }

// int maxScore(vector<int> &cardPoints, int k)
// {
// 	auto itor1 = cardPoints.begin();
// 	auto itor2 = cardPoints.end() - 1;
// 	return maxSum(itor1, itor2, k);
// }

int main()
{
	vector<int> arr{1, 2, 3, 4, 5, 6, 1};
	cout << maxScore(arr, 3) << endl;
	return 0;
}