/********************************************************************
创建时间：2020/3/9
拓扑排序：（使用条件：无环图）
1.找到图中入度为0的顶点入队列。
2.将队列首元素弹出，输出，将这个元素和他的边删除
3.重复1和2步骤直到队列为空
********************************************************************/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int vCount, eCount;
    cin >> vCount >> eCount; // n为顶点数，m为边数
    // 邻接矩阵
    bool **arr = new bool *[vCount + 1];
    for (int i = 1; i <= vCount; i++)
    {
        arr[i] = new bool[vCount + 1]{0};
    }
    // 记录结点的入度
    int *indegree = new int[vCount + 1]{0};
    for (int i = 1; i <= eCount; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = true;
        indegree[y]++;
    }

    // 入度为0的顶点入队列
    queue<int> q;
    // 扫描列，入度为0的进队列
    for (int i = 1; i <= vCount; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        cout << v;
        q.pop();
        for (int i = 1; i <= vCount; i++)
        {
            //如果入度剪成了0，可以入队
            if (arr[v][i] && (--indegree[i] == 0))
            {
                q.push(i);
            }
        }
    }
    return 0;
}