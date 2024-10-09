/********************************************************************************************
 * @author reddragon
 * @date 2021/2/5
 * @brief medium 在二维矩证中搜索
 * 
 * 1.暴力法
 * 遍历所有元素
 * 时间复杂度：O(N*M)		空间复杂度：O(1)
 * 
 * 2.二分搜索法
 * 在搜索每一行的时候使用二分, 这是最简单额思路,但是行不通, 会超时
 * 
 * 至于从对角线二分查找还没有看懂
 * 时间复杂度: O(NlogN) 	空间复杂度: O(1)
 * 
 * 3. 遍历一遍
 * 最巧妙的方法:
 * 首先，我们初始化一个指向矩阵左下角元素指针。然后，直到找到目标并返回 true
 * （或者指针指向矩阵维度之外为止)我们执行以下操作：如果当前指向的值大于目标值，则可以 “向上” 移动一行。 
 * 否则，如果当前指向的值小于目标值，则可以移动一列。不难理解为什么这样做永远不会删减正确的答案；因为行是从左到右排序的，
 * 所以我们知道当前值右侧的每个值都较大。因此，如果当前值已经大于目标值，我们知道它右边的每个值会比较大。
 * 也可以对列进行非常类似的论证，因此这种搜索方式将始终在矩阵中找到目标（如果存在）。
 * 
 * 总结一点: 就是每个点的左上方的数都比他小,右下方的数都比他大
 * 时间复杂度: O(m + n)		空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{
	if(matrix.empty())
		return false;
	int row = matrix.size() - 1;
	int col = 0;
	while(row >= 0 && col < matrix[row].size())
	{
		if(target > matrix[row][col])
			++col;
		else if(target < matrix[row][col])
			--row;
		else
			return true;
	}
	return false;
}

// bool searchMatrix(vector<vector<int>> matrix, int target)
// {
// 	for(int i = 0; i < matrix.size(); ++i)
// 	{
// 		for(int j = 0; j < matrix[i].size(); ++j)
// 		{
// 			if(matrix[i][j] == target)
// 				return true;
// 		}
// 	}
// 	return false;
// }

int main()
{
    struct timeval tm1, tm2;
    if(gettimeofday(&tm1, nullptr) == -1)
    {
        perror("gettimeofday");
    }
	vector<vector<int>> arr{
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}
	};
	cout << searchMatrix(arr, 1) << endl;
    if(gettimeofday(&tm2, nullptr) == -1)
    {
        perror("gettimeofday");
    }
	cout << "消耗时间: " << tm2.tv_usec - tm1.tv_usec << "微妙" <<  endl;
	return 0;
}