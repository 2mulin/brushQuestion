/**
 * @date 2022/11/19
 * @author 2mu
 * @brief easy 找到最高海拔
 * 
 * 一. 简单计算
 * 列个方程式，计算出当前高度。然后比较，记录最大高度。
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int maxHeight = 0;
    int height = 0;
    for(int i = 0; i < gain.size(); ++i)
    {
        height = gain[i] + height;
        if(height > maxHeight)
            maxHeight = height;
    }
    return maxHeight;
}

int main()
{
    std::vector<int> gain{-5,1,5,0,-7};
    std::cout << largestAltitude(gain) << std::endl;
    return 0;
}
