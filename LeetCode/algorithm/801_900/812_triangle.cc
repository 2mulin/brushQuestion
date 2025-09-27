/**
 * @date 2025/9/27
 * @author 2mu
 * @brief easy
 *
 * 1. 暴力枚举
 * 枚举出所有可能的三角形，然后使用海伦公式计算出来所有三角形的面积。取最大的一组输出
 * 
 * 排列组合，可能性总共有n*(n-1)*(n-2)种，时间复杂度就是这个值。
 *
 * 时间复杂度：O(n的3次方)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;


// 鞋带公式，求多边形面积的，也可以求三角形。
double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}


double largestTriangleArea(vector<vector<int>> &points)
{
    double result = 0.0;
    // 枚举遍历，计算出每一种三角形的面积
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            for (int k = j + 1; k < points.size(); k++)
            {
                result = max(result, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
            }
        }
    }
    return result;
}


int main()
{
    std::vector<std::vector<int>> nums{{0,0},{0,1},{1,0},{0,2},{2,0}};
    std::cout << largestTriangleArea(nums) << std::endl;
    return 0;
}
