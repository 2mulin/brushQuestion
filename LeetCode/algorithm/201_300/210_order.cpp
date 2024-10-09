/**
 * @date 2023/9/10
 * @author 2mu
 * @brief medium 课程表II
 *
 * 1. 拓扑排序
 * 
 * 题目很明显就是拓扑排序, 注意这里是出度为0, 表示是先修课程; 具体实现:
 * 
 * a. 首先初始化有向图, 使用邻接表表示;
 * b. 开始循环, 从 邻接表中 选择一个出度为0的顶点currentV;
 *      1. 如果 邻接表 中没有出度为0的顶点, 表示有环; 直接返回
 *      2. 将 currentV 从邻接表中删除, 且记录到 ans 数组中; 同时将 邻接表 中所有与该点相关的边删除;
 *      3. 循环以上步骤, 直到邻接表为空, 或者找不到出度为0的顶点;
 * 
 * 时间复杂度: O(v + e)
 * 空间复杂度: O(v + e)
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// 这份代码应该还有优化空间, 那两个for循环, 暂时这样吧...
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    std::vector<int> ans;
    // 邻接表
    std::map<int, std::unordered_set<int>> adjList;
    for(int i = 0; i < numCourses; ++i)
    {
        adjList.insert({i, {}});
    }
    for(int i = 0; i < prerequisites.size(); ++i)
    {
        int x = prerequisites[i][0], y = prerequisites[i][1];
        adjList[x].insert(y);
    }

    while(!adjList.empty())
    {
        int currV = -1;
        // 这个遍历想办法优化
        for(auto iter = adjList.begin(); iter != adjList.end(); ++iter)
        {
            if(iter->second.empty())
            {
                currV = iter->first;
                break;
            }
        }

        if(currV == -1)
            return {};
        ans.push_back(currV);
        
        // 删除顶点 以及 相关的边;
        adjList.erase(currV);
        for(auto iter = adjList.begin(); iter != adjList.end(); ++iter)
        {
            iter->second.erase(currV);
        }
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> prerequisites = { {1, 0}};
    std::vector<int> ans = findOrder(2, prerequisites);
    for(int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << std::endl;
        
    return 0;
}
