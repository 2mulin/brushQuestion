/**
 * @date 2022/10/16
 * @author 2mu
 * @brief medium 可能的二分法
 * 
 * 一. 暴力
 * 实际上和n关系不大，只要可以保证dislikes中所有二元组的两个元素分别在不同的组。
 * 假设现在有a，b两组。枚举：每次尝试一个二元组(i, j)时，有两种可能：
 *   1. i放入a组，j放入b组
 *   2. i放入b组，j放入a组
 * 
 * 暴力解法可以枚举所有的可能性，然后a，b两组加入时，判断一下是否可以满足条件。
 * a，b两组可以用哈希表表示。判断耗时O(1)
 * 
 * 时间复杂度：O(2的n次方) n表示二元组个数
 * 空间复杂度：O(N)
 * 
 * 二. 染色法
 * 
 * 染色法原理：假设第一组中的人是红色，第二组中的人为蓝色。我们依次遍历每一个人，如果当前的人没有被分组，就将其分到第一组（即染为红色），那么这个人不喜欢的人必须分到第二组中（染为蓝色）。
 * 然后任何新被分到第二组中的人，其不喜欢的人必须被分到第一组，依此类推。如果在染色的过程中存在冲突，就表示这个任务是不可能完成的，否则说明染色的过程有效（即存在合法的分组方案）。
 * 
 * 也就是将当前元素颜色确定，就可以确定它讨厌的所有元素的颜色，那么它讨厌的元素的讨厌元素 颜色也被确定。。 依次类推，dfs。
 * 
 * 时间复杂度：O(m + n)
 * 空间复杂度: O(m + n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* 枚举
bool _partition(const vector<vector<int>>& dislikes, int idx, std::unordered_set<int> group1, std::unordered_set<int> group2)
{
    if(idx == dislikes.size())
        return true;
    int i = dislikes[idx][0], j = dislikes[idx][1];
    bool res1 = false, res2 = false;
    if(group1.find(j) == group1.end() && group2.find(i) == group2.end())
    {
        std::unordered_set<int> copy1(group1), copy2(group2);
        copy1.insert(i);
        copy2.insert(j);
        res1 = _partition(dislikes, idx + 1, std::move(copy1), std::move(copy2));
    }
    if(group1.find(i) == group1.end() && group2.find(j) == group2.end())
    {
        std::unordered_set<int> copy1(group1), copy2(group2);
        copy1.insert(j);
        copy2.insert(i);
        res2 = _partition(dislikes, idx + 1, std::move(copy1), std::move(copy2));
    }
    return res1 || res2;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    return _partition(dislikes, 0, std::unordered_set<int>(), std::unordered_set<int>());
}
*/

bool dfs(int cur, int newColor, vector<int>& color, const vector<vector<int>>& hate)
{
    color[cur] = newColor;
    for(auto& nextnode : hate[cur])
    {
        // cur讨厌的所有节点都不能是相同颜色, 否则返回false
        if(color[nextnode] && color[nextnode] == color[cur])
            return false;
            
        // cur讨厌的所有节点还没染色, 给它染成其它颜色dfs试试
        if(!color[nextnode] && !dfs(nextnode, 3 ^ newColor, color, hate))
            return false;
    }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    std::vector<int> color(n + 1, 0);   // 标记数组，color[i]表示 i 被染成了什么颜色
    vector<vector<int>> hate(n + 1);    // 标记数组，hate[i]就表示 i 讨厌的所有元素
    for(auto& tup : dislikes)
    {
        hate[tup[0]].push_back(tup[1]);
        hate[tup[1]].push_back(tup[0]);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(color[i] == 0 && !dfs(i, 1, color, hate))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> dislikes{{1,2}, {1,3}, {2,3}};
    std::cout << possibleBipartition(3, dislikes) << std::endl;
    return 0;
}
