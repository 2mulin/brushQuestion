/********************************************************************************************
 * @author reddragon
 * @date 2021/1/24
 * @brief medium 岛屿数量
 * 
 * 1，深度优先搜索
 * 利用一个标记数组，记录下来所有已经访问过的点，保证每个点都只访问一次。
 * 下面是官方题解：
 * 为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 1，则以其为起始节点开始进行深度优先搜索。
 * 在深度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。
 * 时间复杂度：O(mn)			空间复杂度：O(mn)
 * 递归占用空间O(mn)
 * 
 * 2.广度优先搜索
 * 和深度优先搜索差不多
 * 
 * 3.并查集
 * 为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 1，则将其与相邻四个方向上的 1 在并查集中进行合并。
 * 最终岛屿的数量就是并查集中连通分量的数目。
 * 时间复杂度：O(mn)			空间复杂度：O(mn)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int row;
int col;

void DFS(vector<vector<char>> &grid, int i, int j)
{
	if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0')
		return;
	else
	{
		grid[i][j] = '0';
		DFS(grid, i + 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i - 1, j);
		DFS(grid, i, j - 1);
	}
}
int numIslands(vector<vector<char>> &grid)
{
	row = grid.size();
	if(row == 0)
		return 0;
	col = grid[0].size();
	int ret = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == '1')
			{
				++ret;
				DFS(grid, i, j);
			}
		}
	}
	return ret;
}

int main()
{
	vector<vector<char>> arr{
		{'1', '1', '1', '1', '0'}, 
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	};
	cout << numIslands(arr) << endl;
	return 0;
}
