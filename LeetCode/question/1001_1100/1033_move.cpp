/**
 * @date 2023/4/30
 * @author 2mu
 * @brief medium 移动石子到连续 
 *
 * 1. 贪心
 * 保证3个数连续, 分析: 总共三个数, 先排序, 然后依次计算两个数之间的差值; 
 * 差值 - 2 就是 最大移动次数
 * 最小移动次数 只能是 0, 1, 2 三者之一, 因为任意移动, 最多移动两次就可以满足条件;
 * 
 * 题目还保证a,b,c不相等; 省去了一些判断;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> numMovesStones(int a, int b, int c)
{
    if(a > b)
        std::swap(a, b);
    if(a > c)
        std::swap(a, c);
    if(b > c)
        std::swap(b, c);

    int maxMove = 0, minMove = 0;
    int diffAB = b - a, diffBC = c - b;
    maxMove = diffAB + diffBC - 2;

    if(diffAB == 1 && diffBC == 1)
        minMove = 0;
    else if(diffAB == 1 || diffBC == 1)
        minMove = 1;
    else if (diffAB == 2 || diffBC == 2)
        minMove = 1; // 只需要移动1次, 把第三个数字移动到中间就行;
    else
        minMove = 2; // 最多就是2次
    return {minMove, maxMove};
}


int main()
{
    auto vec = numMovesStones(1, 2, 5);
    for(auto num : vec)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    vec = numMovesStones(4, 3, 2);
    for(auto num : vec)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    
    vec = numMovesStones(3, 5, 1);
    for(auto num : vec)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    return 0;
}