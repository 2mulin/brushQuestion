/**
 * @date 2023/5/1
 * @author 2mu
 * @brief medium 通知所有员工需要的时间
 *
 * 1. dfs
 * 按照规则搜索从顶层head 通知到 最底层员工, 这条路径所有花费的总时间 
 * 然后找出所有路径花费总时间最大值, 就是答案;
 * 
 * 很像是多叉树的dfs;
 * 
 * 时间复杂度: O(n*n)   // 每次递归都需要重新便利整个数组;
 * 空间复杂度: O(n)
 * 
 * 1. 优化
 * 两条思路:
 *  a. 避免每次递归 遍历整个数组, 将整个tree构建出来, 每次往下搜索时只访问 孩子节点;
 *  b. 每个节点的dfs查询结果都记录下来, 再次访问到时, 直接返回结果即可;
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

std::unordered_map<int, int> gIdxToResult;

int dfs(int headID, const std::unordered_map<int, std::vector<int>>& tree, const vector<int>& informTime)
{
    auto iter = tree.find(headID);
    if(iter == tree.end())
        return 0;   // 直接返回, 因为该节点没有下属, 不需要继续往下通知;

    int maxTime = 0;
    std::vector<int> vctChild = iter->second;
    for(int i = 0; i < vctChild.size(); ++i)
    {
        int idx = vctChild[i];// 该节点 在 manager 数组中的索引
        int tmpTime = informTime[idx];
        auto iter = gIdxToResult.find(idx);
        if(iter != gIdxToResult.end())
            tmpTime += iter->second;
        else
            tmpTime += dfs(idx, tree, informTime);
        maxTime = std::max(tmpTime, maxTime);
    }
    gIdxToResult[headID] = maxTime;
    return maxTime;
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    std::unordered_map<int, std::vector<int>> tree;
    for(size_t i = 0; i < manager.size(); ++i)
    {
        tree[manager[i]].push_back(i); // 把i节点记录到parent的child数组中
    }
    int totalTime = informTime[headID] + dfs(headID, tree, informTime);
    return totalTime;
}

int main()
{
    std::vector<int> manager{1,2,3,4,5,6,-1};
    std::vector<int> informTime{0,6,5,4,3,2,1};
    std::cout << numOfMinutes(7, 6, manager, informTime) << std::endl;
    return 0;
}