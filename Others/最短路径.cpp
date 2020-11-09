/********************************************************************************************
 * @author reddragon
 * @date 2020/11/9
 * @brief 最短路径
 * 
 * 未完成，明天继续
 * 
 * 1. 最短路径
 * 
 * 时间复杂度：O(NlogN)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::queue;


int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<vector<int> > Matrix(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 0; i < m; ++i)
        {
            int x,y,val;
            cin >> x >> y >> val;
            Matrix[x][y] = val;
        }
        vector<int> dist(n + 1);// 存放1号点到其他顶点的距离
        vector<bool> isVisit(n + 1, false);
        dist[1] = 0;
        isVisit[1] = true;
        // vector<int> path; 
        queue<int> qu;
        qu.push(1);
        while(!qu.empty())
        {
            int src = qu.front();
            isVisit[src] = true;
            qu.pop();
            // 检查所有row顶点的临界顶点
            for(int dst = 1; dst <= n; ++dst)
            {
                if(Matrix[src][dst] != INT_MAX && !isVisit[dst])
                {
                    qu.push(dst);
                    // 
                    dist[dst] = std::min(dist[src] + Matrix[src][dst], dist[dst]);
                }
            }
        }

        // 输出1到其他所有顶点的最短距离
        for(int i = 2; i <= n; ++i)
            cout << dist[i] << std::endl;
    }
    return 0;
}