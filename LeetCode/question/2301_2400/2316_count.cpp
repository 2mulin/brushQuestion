/**
 * @date 2023/10/22
 * @author 2mu
 * @brief medium 统计无向图中无法相互到达点对数
 *
 * 和最短路径无关, 想复杂了, 只是需要知道任意两点是否连通?
 * 
 * 1. bfs
 * 遍历, 创建一个邻接表; 然后用函数参数edges初始化一下邻接表;
 * 然后从任意一个点x出发, 开始BFS, 遍历到它能到达的点y; 然后将(x,y)记录到邻接表中;
 * 
 * 需要将n个点都当作起点, 然后执行一次BFS; 所以复杂度是: O(n*n)
 *
 * 时间复杂度: O(n*n) 会超时
 * 空间复杂度: O(n*n)
 * 
 * 2. 并查集
 * 
 * 想了半天, 发现实际上是传递性; 也就是A-B联通, B-C联通, 则必然有A-B-C联通;
 * 可以将A,B,C看成是一个集合, 则新的节点到来, 只要和A,B,C任意一个联通, 就可以加入该集合;
 * 
 * 最终答案就是看有 几个集合, 集合内元素只能相互连通, 集合外的元素都不通; 所以每个点x, 不能到达的点就是
 * 那些跟它不在同一个集合的点;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int findRank(std::vector<int>& unionFind, int x)
{
    if(unionFind[x] == -1 || unionFind[x] == x)
    {
        unionFind[x] = x;
        return x;
    }
    else
    {
        unionFind[x] = findRank(unionFind, unionFind[x]);
        return unionFind[x];
    }
}

long long countPairs(int n, vector<vector<int>> &edges)
{
    std::vector<int> unionFind(n, -1);
    for(auto edge : edges)
    {
        int x = edge[0], y = edge[1];

        int x_rank = findRank(unionFind, x), y_rand = findRank(unionFind, y);
        // 如果两个集合相互合并, 只需要将其中一个集合的rank(祖先) 指向另一个节点即可;
        unionFind[y_rand] = x_rank;
    }

    std::unordered_map<int, int> maSetCnt;// 统计每个集合的元素大小; 以rank为key, 集合大小为value
    for(int i = 0; i < n; ++i)
    {
        // 再做一次路径压缩, 更新所有节点的rank, 确保后面正确统计各集合大小;
        int rank = findRank(unionFind, i);

        maSetCnt[rank]++;
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int rank = unionFind[i];
        int size = maSetCnt[rank];
        // 对于第i点来说, 它有n-size个无法到达的点;
        ans = ans + (n - size);
    }
    return ans / 2;
}


/**
 * @brief 会超时....
 * @param n 
 * @param edges 
 * @return 
 */
/*
long long countPairs(int n, vector<vector<int>> &edges)
{
    std::vector<std::vector<int>> vctLink(n, std::vector<int>(n, 0));
    for(size_t i = 0; i < n; ++i)
        vctLink[i][i] = 1;
    for(auto& edge : edges)
    {
        vctLink[edge[0]][edge[1]] = vctLink[edge[1]][edge[0]] = 2;
    }

    for(int startV = 0; startV < n; ++startV)
    {
        std::queue<int> que;
        que.push(startV);
        int this_level_v_cnt = 1;// 当前层数有多少个顶点
        int level = 2;
        std::unordered_set<int> setVisit;// 防止出现环路
        setVisit.insert(startV);
        // 一次BFS
        while(!que.empty())
        {
            int v = que.front();
            setVisit.insert(v);
            que.pop();
            --this_level_v_cnt;
            for(int j = 0; j < n; ++j)
            {
                if(setVisit.find(j) == setVisit.end() && vctLink[v][j])
                {
                    que.push(j);
                    vctLink[startV][j] = level; // 距离=BFS层数, 因为边权重都是1
                }
            }
            // 表示上一层的顶点都已经遍历完, 到下一层顶点了
            if(this_level_v_cnt == 0)
            {
                this_level_v_cnt = que.size();
                ++level;
            }
        }
    }
    int cnt = 0; 
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(vctLink[i][j] == 0)
                ++cnt;
        }
    }
    return cnt;
}
*/

int main()
{
    std::vector<std::vector<int>> vct{
        {1, 2},
        {0, 1},
        {0, 2}
    };
    std::cout << countPairs(3, vct) << std::endl; // 预期0

    vct = {
        {0, 2},
        {0, 5},
        {2, 4},
        {1, 6},
        {5, 4}
    };
    std::cout << countPairs(7, vct) << std::endl; // 预期14
    
    vct = {
        {0, 15},{5, 15}, 
        {1, 14}, 
        {2, 11}, {4, 3},{8, 2},
        {14, 12}
    };
    std::cout << countPairs(16, vct) << std::endl; // 预期110
    return 0;
}
