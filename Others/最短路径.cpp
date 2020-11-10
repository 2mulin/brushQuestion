/********************************************************************************************
 * @author reddragon
 * @date 2020/11/10
 * @brief 最短路径
 * 
 * 1. 最短路径
 * 最短路径有两种，Dijkstra和Floyd，但是Dijkstra不能处理 负边 情况。
 * 所以这里采用Floyd算法。
 * 时间复杂度：O(N*N*N)        空间复杂度：O(N*N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

const int MAX = 10005;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        // 邻接矩阵
        vector<vector<int> > Matrix(n + 1, vector<int>(n + 1, MAX));
        for(int i = 0; i < m; ++i)
        {
            int x,y,val;
            cin >> x >> y >> val;
            Matrix[x][y] = val;
        }
        // 对角线全部初始化为0
        for(int i = 1; i <= n; ++i)
            Matrix[i][i] = 0;
        // Floyd算法实现
        for(int k = 1; k <= n; ++k)
        {
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    Matrix[i][j] = std::min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
                }
            }
        }

        // 输出1到其他所有顶点的最短距离
        for(int i = 2; i <= n; ++i)
            cout << Matrix[1][i] << std::endl;
    }
    return 0;
}