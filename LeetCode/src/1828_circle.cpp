/**
 * @date 2022/1/24
 * @author 2mu
 * @brief medium 统计一个圆中点的数量
 * 
 * 一、模拟
 * 
 * 给一个点的数组，再给一个圆的数组，判断点是否在圆内。
 * 简单数学题：点到圆心的距离是否小于半径，如果小于，则说明在圆内。
 * 
 * 这是普遍思路，但是一定需要注意，在计算机中避免使用浮点数，所以避免开平方，
 * 直接这样比较平方
 *
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
{
    std::vector<int> pointsNums;
    for(auto circle : queries)
    {
        pointsNums.push_back(0);
        int x = circle[0], y = circle[1], radius = circle[2];
        for(auto point : points)
        {
            int pointX = point[0], pointY = point[1];
            if(pow(pointX - x, 2) + pow(pointY - y, 2) <= pow(radius, 2))
            {
                ++pointsNums.back();
            }
        }
    }
    return pointsNums;
}

int main()
{

    return 0;
}
