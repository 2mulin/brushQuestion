/********************************************************************************************
 * @author reddragon
 * @date 2020/12/4
 * @brief 拯救007
 * 
 * 1. 拯救007
 * 007在湖中央,湖中央半径为15,整个湖是一个正方形,宽100米,007如何逃生
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
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

bool DFS(const vector<Point>& arr, Point p, int D, vector<bool> isVisit)
{
    if(50 - fabs(p.x) <= D || 50 - fabs(p.y) <= D)
        return true;
    for(size_t i = 0; i < arr.size(); ++i)
    {
        if(isVisit[i])
            continue;
        isVisit[i] = true;
        if(p.x == 0 && p.y == 0)
            if(DistanceXY(p, arr[i]) <= D + 15 && DFS(arr, arr[i], D, isVisit))
                return true;// 出发点是一个圆盘,半径为15.所以跳跃距离+15
        if(DistanceXY(p, arr[i]) <= D && DFS(arr, arr[i], D, isVisit))
            return true;
        isVisit[i] = false;
    }
    return false;
}

int main()
{
    int N = 0,D = 0;// N是鳄鱼数量，D是詹姆斯最远跳的距离
    vector<Point> arr;
    vector<bool> isVisit;
    while(cin >> N >> D)
    {
        for(int i = 0; i < N; ++i)
        {
            int a,b;
            cin >> a >> b;
            arr.push_back(Point(a,b));
            isVisit.push_back(false);
        }
        if(N <= 0)
        {
            cout << "No" << endl;
            continue;
        }
        if(DFS(arr,Point(0,0),D,isVisit))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        arr.clear();
        isVisit.clear();
    }
    return 0;
}