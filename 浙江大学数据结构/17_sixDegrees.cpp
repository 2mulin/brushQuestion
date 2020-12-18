/********************************************************************************************
 * @author reddragon
 * @date 2020/12/10
 * @brief 六度空间
 * 
 * 1.广度优先搜索
 * 代码写得比较乱，思路很简单，广度优先搜索，记得带上层数
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    int V,E;
    while(cin >> V >> E)
    {
        vector<vector<int>> Mratix(V + 1,vector<int>(V + 1, 0));
        for(int i = 0; i < V; ++i)
        {
            Mratix[i][i] = 1;
        }
        for(int i = 0; i < E; ++i)
        {
            int row,col;
            cin >> row >> col;
            Mratix[row][col] = Mratix[col][row] = 1; // 题意是一个有向图
        }
        // BFS
        vector<bool> isV(V + 1, false);
        double count = 0;
        for(int i = 1; i <= V; ++i)
        {
            for(auto val : isV)
                val = false;
            isV[i] = true;
            queue<int> vs;vs.push(i);
            int floor = 0;
            count = 1;
            while(!vs.empty() && floor < 6)
            {
                int len = vs.size(); // 同一层的个数
                for(int i = 0; i < len; ++i)
                {
                    int pos = vs.front();
                    vs.pop();
                    for(int j = 0; j <= V; ++j)
                        if(!isV[j] && Mratix[pos][j])
                        {
                            vs.push(j);// 添加临近的点
                            isV[j] = true;
                            ++count;
                        }
                }
                ++floor;
            }
            cout << i << ": " << fixed << setprecision(2) << count/V * 100 << '%' << endl;
        }
    }
    return 0;
}