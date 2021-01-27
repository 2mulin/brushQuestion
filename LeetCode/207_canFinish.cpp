/********************************************************************************************
 * @author reddragon
 * @date 2021/1/27
 * @brief medium 课程表
 * 
 * 1。拓扑排序
 * 数据结构的选取很重要，这里选用一个邻接矩阵和一个数组，邻接矩阵记录有向边，
 * 数组记录每个结点的入度，然后进行广搜
 * 先将入度为0的结点压入队中，将入度为0的结点pop出队列时，把相关的边的
 * 入度-1，再将减成0的结点入度。反复进行，直到队列为空退出。
 * 时间复杂度：O(n)			空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// 广度优先搜索
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
	if(prerequisites.empty())
		return true;

	vector<vector<int>> maritx(numCourses, vector<int>(numCourses, 0)); // 邻接矩阵 0表示无边，1表示有
	unordered_map<int, int> ma;	// 表示每个结点的入度
	for(int i = 0; i < numCourses; ++i)
		ma.insert(std::pair<int, int>(i, 0)); // 入度初始化为0
	for(auto item : prerequisites)
	{
		maritx[item[1]][item[0]] = 1;
		ma[item[0]]++;
	}
	
	queue<int> qu;
	for(auto it = ma.begin(); it != ma.end(); ++it)
	{
		if(it->second == 0)
			qu.push(it->first);
	}

	vector<int> arr;// 记录拓扑排序的顺序
	while(!qu.empty())
	{
		int Courses = qu.front();
		arr.push_back(Courses);
		qu.pop();
		// 这里是时间消耗的地方
		for(int i = 0; i < numCourses; ++i)
		{
			if(maritx[Courses][i])
			{
				maritx[Courses][i] = 0;
				ma[i]--;
				if(ma[i] == 0)
					qu.push(i);
			}
		}
	}
	if(arr.size() == numCourses)
		return true;
	return false;
}

int main()
{
	vector<vector<int>> prerequisites{{1, 0}, {2, 1}};
	cout << canFinish(3, prerequisites) << endl;
	return 0;
}