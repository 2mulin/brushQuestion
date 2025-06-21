/**
 * @date 2025/6/20
 * @author 2mu
 * @brief medium K次修改后的最大曼哈顿距离
 *
 * 1. 完全没思路
 * 
 * 但还是可以简单分析下，首先题目要求的曼哈顿距离就是直线距离，越远越好。
 * 然后就是4个方向，最多可以修改k次。
 * 
 * N和S是相反方向，E和W是相反方向。距离差要大，就是两个方向，看题目示例，也可以当前方向直接修改为反方向。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxDistance(string s, int k)
{
    int result = 0;
    int countN = 0, countS = 0, countE = 0, countW = 0;
    for(auto ch : s)
    {
        if (ch == 'N') 
            ++countN;
        else if (ch == 'S')
            ++countS;
        else if (ch == 'E')
            ++countE;
        else
            ++countW;
        // 由于题目是求解移动过程中的最大曼哈顿距离，所以需要在遍历过程中计算
        int item1 = min({countS, countN, k});
        int item2 = min({countE, countW, k - item1});
        result = max(result, abs(countS - countN) + item1 * 2 + abs(countE - countW) + item2 * 2);
    }
    return result;
}

int main()
{
    std::cout << maxDistance("NWSE", 1) << std::endl;
    return 0;
}
