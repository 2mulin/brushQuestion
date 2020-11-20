/********************************************************************************************
 * @author reddragon
 * @date 2020/11/20
 * @brief 哈利珀特
 * 
 * 1. floyd求最短路径
 * 显而易见这题需要求出任意两点之间的最短路径，迪杰斯特拉只能一点到其他人任意点的最短路径
 * 剩下就是遍历一下
 * 时间复杂度：O(N的三次方)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int v,e;// v个点，11条边
    while(cin >> v >> e)
    {
        // 初始化
        vector<vector<int> > Matrix(v + 1, vector<int>(v + 1, 100000));// 邻接矩阵
        for(int i = 1; i <= v; ++i)
            Matrix[i][i] = 0;
        for(int i = 0; i < e; ++i)
        {
            int x,y,pow;
            cin >> x >> y >> pow;
            Matrix[x][y] = Matrix[y][x] = pow;
        }
        // Floyd
        for(int k = 1; k <= v; ++k)
        {
            for(int i = 1; i <= v; ++i)
            {
                for(int j = 1; j <= v; ++j)
                {
                    Matrix[i][j] = Matrix[j][i] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
                }
            }
        }
        // 找每一只动物变化的最大权值中的最小值
        vector<int> maxs(v + 1, 0);
        for(int i = 1; i <= v; ++i)
        {
            for(int j = 1; j <= v; ++j)
            {
                if(Matrix[i][j] != 100000)
                    maxs[i] = max(maxs[i], Matrix[i][j]);
                else
                {// 带着个动物不行
                    maxs[i] = 0;
                    break;
                }
            }
        }
        int ans = 0;
        int minPow = INT_MAX;
        for(int i = 1; i <= v; ++i)
            if(maxs[i] != 0 && minPow > maxs[i])
            {
                ans = i;
                minPow = maxs[i];
            }
        if(ans != 0)
            cout << ans << ' ' << minPow << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}