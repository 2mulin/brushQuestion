/**
 * @date 2023/9/10
 * @author 2mu
 * @brief medium 课程表
 * 
 * 1. 拓扑排序(2021/1/27的实现)
 * 有广度优先搜索的思路在里面
 * 
 * 这里选用一个邻接矩阵和一个数组，邻接矩阵记录有向边，数组记录每个结点的入度，然后进行广搜
 * 先将入度为0的结点压入队中，将入度为0的结点pop出队列时，把相关的边的入度-1，再将减成0的结点入队。
 * 途中记录删除入度为0节点的顺序(即拓扑顺序); 反复进行, 直到队列为空退出;
 * 
 * 最后拓扑顺序节点数量, 等于课程数, 表示无环; 否则有环; 
 * 
 * 时间复杂度: O(v + e)
 * 空间复杂度: O(v + e)
 * 
 * 2. DFS
 * 使用邻接矩阵进行存储, 邻接矩阵实现起来比较方便, 并且最重要的是 判断两点之间是否存在边 是O(1); 
 * 先初始化邻接矩阵, 并且额外创建一个visit集合, 表示某个课程已经DFS过;
 * 再创建一个 path集合, 记录当前路径上顶点, 以便用于判断当前是否有环;
 * 创建一个stack, 记录当前路径上的顶点, 实现非递归DFS;
 * 
 * DFS实现: 遍历所有课程(顶点), 选择一个出来:
 *  a. 判断当前顶点是否已经在visit数组中, 如果在, 则它后续路径已经DFS过, 且没有环, 可以跳过;
 *  b. 当前顶点不在visit数组中, 选择该顶点开始DFS:
 *      b.1 该顶点加入到stack中, 加入到path中;
 *      b.2 只要stack不为空, 循环进行如下步骤:
 *          步骤1: 从栈顶取出当前顶点
 *          步骤2: 遍历当前顶点的 下一个顶点 选择 **不在visit集合中**的顶点 加入到stack中, 记录到path中; 回到步骤1重新开始
 *          步骤3: 如果该顶点指向的所有其它顶点都已经在visit中, 即该顶点的所有下一个顶点都已经访问过; 
 *                 则将当前顶点加入到visit中, 当前顶点从stack, path中删除; 回到步骤1
 *  c. 最终stack为空, 并且没有提前返回false, 表示所有顶点都DFS过, 无环;
 * 
 * 时间复杂度: O(v + e)  实际上就是对图进行DFS的时间复杂度, 因为代码实际上就是DFS
 * 空间复杂度: O(v + e)  有向图, v表示顶点数, e表示边数
 */

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_set>


using namespace std;


bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // 邻接表
    std::vector<std::unordered_set<int>> adjList(numCourses, std::unordered_set<int>());
    for(int i = 0; i < prerequisites.size(); ++i)
    {
        int x = prerequisites[i][0], y = prerequisites[i][1];
        adjList[x].insert(y);
    }
    std::unordered_set<int> visitSet;
    // 开始DFS
    std::stack<int> stPath;
    for(int i = 0; i < numCourses; ++i)
    {
        if(visitSet.find(i) != visitSet.end())
            continue;
        std::unordered_set<int> path;
        stPath.push(i);
        path.insert(i);

        while(!stPath.empty())
        {
            int currentV = stPath.top();
            int nextV = -1;
            
            // 用邻接矩阵, 这个for循环最多每个循环2000次, 用邻接表的话, 有几条边, 循环几次; 效率极大提高; 184ms -> 16ms
            for(auto iter = adjList[currentV].begin(); iter != adjList[currentV].end(); ++iter)
            {
                if(visitSet.find(*iter) == visitSet.end())
                {
                    nextV = *iter;
                    break;
                }
            }

            if(nextV != -1)
            {
                if(path.find(nextV) != path.end())
                    return false;
                stPath.push(nextV);
                path.insert(nextV);
                currentV = nextV;
                continue;
            }
            // 没找到next V; 则currentV的DFS无环;
            visitSet.insert(currentV);

            // 回退到currentV的上一个顶点
            path.erase(currentV);
            stPath.pop();
        }
    }    
    return true;
}

// 旧版本实现: 拓扑排序, 邻接矩阵可优化
/*
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
*/

int main()
{
	vector<vector<int>> prerequisites{{1, 0}, {2, 1}};
	cout << canFinish(3, prerequisites) << endl;
	return 0;
}