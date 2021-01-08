/********************************************************************************************
 * @author reddragon
 * @date 2020/12/19
 * @brief 拯救007升级版
 * 
 * 1. 拯救007
 * 007在湖中央,湖中央半径为15,整个湖是一个正方形,宽100米,007如何逃生
 * 找最短的逃生路径
 * 
 * 还没有测试过，因为题目连接失效了
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int _x, int _y)
        :x(_x), y(_y){}
};
// 两点间的距离公式
int DistanceXY(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// 迪杰斯特拉算法求最短路径
vector<int> DFS(const vector<Point>& arr, int pos, int D, vector<bool>& isVisit)
{
    vector<int> path;
    // 递归基, 直接跳上岸了
    if(50 - fabs(arr[pos].x) <= D || 50 - fabs(arr[pos].y) <= D)
    {
        path.push_back(pos);
        return path;
    }

    vector<int> tmp;
    for(size_t i = 0; i < arr.size(); ++i)
    {
        if(isVisit[i])
            continue;
        if(DistanceXY(arr[pos], arr[i]) <= D)
        {
            isVisit[i] = true;
            vector<int> ret = DFS(arr, i, D, isVisit);
            if(ret.empty())
                continue;// 返回值为空，表示没有上岸
            if(tmp.empty() || ret.size() < tmp.size())
                tmp = ret;
            isVisit[i] = false;
        }
    }
    if(tmp.empty())
        return path;

    path.push_back(pos);
    for(auto i : tmp)
        path.push_back(i);
    return path;
}

int main()
{
    int N = 0,D = 0;// N是鳄鱼数量，D是詹姆斯最远跳的距离
    vector<Point> arr;
    while(cin >> N >> D)
    {
        for(int i = 0; i < N; ++i)
        {
            int a,b;
            cin >> a >> b;
            arr.push_back(Point(a,b));
        }
        vector<bool> isVisit(N, false);
        vector<int> ans;
        for(int i = 0; i < N; ++i)
        {// 所有可能的起点都试一下
            if(DistanceXY(arr[i], Point(0,0)) <= 15)
            {
                isVisit[i] = true;
                vector<int> tmp = DFS(arr, i, D, isVisit);
                if(ans.empty() || ans.size() > tmp.size())
                    ans = tmp;
                isVisit[i] = false;
            }
        }
        cout << ans.size() + 1 << endl;
        for(auto i : ans)
            cout << arr[i].x << ' ' << arr[i].y << endl;
        arr.clear();
    }
    return 0;
}