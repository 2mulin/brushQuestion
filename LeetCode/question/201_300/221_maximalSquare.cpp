/********************************************************************************************
 * @author reddragon
 * @date 2021/2/2
 * @brief medium 最大正方形
 * 
 * 1.暴力法
 * 一个矩形由两个顶点确定，首先确定左上角的顶点，然后确定右下角的顶点，由此得到一个正方形
 * 时间消耗主要在确定左上角顶点上，确定左上角顶点后，右下角顶点只能是走斜的。
 * 时间复杂度：O(m*n*min(m,n)*min(m,n)) = o(n^4)		空间复杂度：O(n)
 * 
 * 2. 动态规划
 * 建立一个dp二维数组，dp(i, j)表示以(i, j)为右下角顶点的正方形最大边长
 * 得到状态转移方程：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
 * 
 * 时间复杂度：O(m*n)		空间复杂度：O(m,n)
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col, 0));
	// 第一行和第一列初始化
	int maxEage = 0;
	for (int i = 0; i < col; ++i)
	{
		if (matrix[0][i] == '1')
		{
			dp[0][i] = 1;
			maxEage = 1;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		if (matrix[i][0] == '1')
		{
			dp[i][0] = 1;
			maxEage = 1;
		}
	}
	// dp
	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][j] == '1')
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				maxEage = max(dp[i][j], maxEage);
			}
			else
				dp[i][j] = 0;
		}
	}
	return maxEage * maxEage;
}

// 判断正方形是都满足条件（都是1）
// int Area(const vector<vector<char>>& matrix, int leftX, int leftY, int rightX, int rightY)
// {
// 	if(leftX > rightX || leftY > rightY)
// 		return -1;
// 	int area = 0;
// 	for(int i = leftX; i <= rightX; ++i)
// 	{
// 		for(int j = leftY; j <= rightY; ++j)
// 		{
// 			if(matrix[i][j] == '0')
// 				return 0;
// 			++area;
// 		}
// 	}
// 	return area;
// }

// int maximalSquare(vector<vector<char>> &matrix)
// {
// 	int row = matrix.size();
// 	if (row == 0)
// 		return 0;
// 	int col = matrix[0].size();
// 	// 两点确定一个正方形
// 	int k = 0;// 正方形边长
// 	for (int i = 0; i < row; ++i)
// 	{
// 		for (int j = 0; j < col; ++j)
// 		{
// 			// 确定一个顶点作为正方形的左上角matrix[i][j]
// 			while (i + k < row && j + k < col)
// 			{
// 				if(Area(matrix, i, j, i+k, j+k) > 0)
// 					k++;
// 				else
// 					break;
// 			}
// 		}
// 	}
// 	return k*k;
// }

int main()
{
	vector<vector<char>> matrix;
	matrix.push_back({'1', '0', '1', '0', '0'});
	matrix.push_back({'1', '0', '1', '1', '1'});
	matrix.push_back({'1', '1', '1', '1', '1'});
	matrix.push_back({'1', '0', '0', '1', '0'});
	cout << maximalSquare(matrix) << endl;
	return 0;
}