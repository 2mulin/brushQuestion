/**
 * @date 2022/7/24
 * @author 2mu
 * @brief easy 公交站之间的距离
 *
 * 1. 最短距离
 * 咋一看，还以为是求图中两点的最短路径，但是认真一看不是的，有一些区别。但是直接用最短路径应该也可以。
 * 
 * 首先：题目说了，是环形公交线，也就是说公交站从头到尾围成一个环。并且公交站为无向图中一个顶点。那么这个顶点出度一定为2，
 * 入度也为2。说白了就只有a，b之间只有两条路线可选。没必要用最短路径求。
 * 
 * 那么a，b两个公交站之间的最短距离不是从a --> b，就是反方向 b --> a。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
{
    if(start > destination)
        std::swap(start, destination);
    int sum = 0;
    for(const int& num : distance)
        sum += num;

    int result = 0;
    for(size_t i = start; i < destination; ++i)
    {
        result += distance[i];
    }
    result = std::min(sum - result, result);
    return result;
}

int main()
{
    std::vector<int> distance{7,10,1,12,11,14,5,0};
    std::cout << distanceBetweenBusStops(distance, 7, 2) << std::endl;
    return 0;
}
