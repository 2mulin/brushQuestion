/********************************************************************************************
 * @author reddragon
 * @date 2020/12/4
 * @brief 列出联通子集
 * 
 * 1. 列出联通子集
 * 直接是二维矩阵建完树之后，先DFS输出，在BFS输出。
 * 结点输出时从小的开始。
 * DFS都写错了，好好反思.不要只看到测试用例,需要理解每个算法真正的思想.
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 深搜
vector<vector<int>> DFS(const vector<vector<int>> &Matrix)
{
    vector<vector<int>> ans;
    int N = Matrix.size();
    vector<bool> isVisit(N, false);
    vector<int> tmp;
    for(int i = 0; i < N; ++i)
    {// 尝试每一个顶点,作为起点
        if(isVisit[i])
            continue;
        stack<int> st;
        st.push(i);
        tmp.push_back(i);
        isVisit[i] = true;
        while(!st.empty())
        {
            int pos = st.top();
            // 每次找与栈顶相邻的最小的结点入栈,没有就弹出栈顶元素
            int j = 0;
            while(j < N)
            {
                if(!isVisit[j] && Matrix[pos][j])
                {
                    tmp.push_back(j);
                    st.push(j);
                    isVisit[j] = true;
                    break;
                }
                ++j;
            }
            if(j >= N)
                st.pop();
        }
        if(!tmp.empty())
            ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}
// 广搜
vector<vector<int>> BFS(const vector<vector<int>> &Matrix)
{
    vector<vector<int>> ans;
    int N = Matrix.size();
    vector<bool> isVisit(N, false);
    for(int i = 0; i < N; ++i)
    {// 尝试每一个顶点,作为起点
        vector<int> tmp;
        if(isVisit[i])
            continue;
        queue<int> qu;
        qu.push(i);
        isVisit[i] = true;
        while(!qu.empty())
        {
            int pos = qu.front();
            qu.pop();
            tmp.push_back(pos);
            // 相邻的结点入栈
            for(int j = 0; j < N; ++j)
            {
                if(!isVisit[j] && Matrix[pos][j])
                {
                    qu.push(j);
                    isVisit[j] = true;
                }
            }
        }
        if(!tmp.empty())
            ans.push_back(tmp);
    }
    return ans;
}

int main()
{
    int N = 0,E = 0;// N是顶点数，E是边数
    while(cin >> N >> E)
    {
        vector<vector<int> > Matrix(N, vector<int>(N, 0));
        for(int i = 0; i < N; ++i)
            Matrix[i][i] = 1;
        for(int i = 0; i < E; ++i)
        {
            int x,y;
            cin >> x >> y;
            Matrix[x][y] = Matrix[y][x] = 1;
        }
        vector<vector<int> > d = DFS(Matrix);
        for(auto s : d)
        {
            cout << "{ ";
            for(auto i : s)
                cout << i << ' ';
            cout << '}' << endl;
        }
        vector<vector<int> > b = BFS(Matrix);
        for(auto s : b)
        {
            cout << "{ ";
            for(auto i : s)
                cout << i << ' ';
            cout << '}' << endl;
        }
    }
    return 0;
}