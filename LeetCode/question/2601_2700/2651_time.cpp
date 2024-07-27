/**
 * @date 2023/9/8
 * @author 2mu
 * @brief easy 计算列车到站时间
 *
 * 1. 数学
 * 应该是Leetcode最简单的题目了; 实际上就是24小时制, 相加对于24取余即可;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int findDelayedArrivalTime(int arrivalTime, int delayedTime)
{
    return (arrivalTime + delayedTime) % 24;
}

int main()
{
    std::cout << findDelayedArrivalTime(15, 5) << std::endl;
    std::cout << findDelayedArrivalTime(13, 11) << std::endl;
    return 0;
}
