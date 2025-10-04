/**
 * @date 2025/10/4
 * @author 2mu
 * @brief medium 盛最多水的容器
 *
 * 1. 枚举
 * 枚举所有可能的水池情况，也就是所有可能出现的组合，然后计算哪种组合面积最大。
 * 
 * 提交后发现超时。
 *
 * 时间复杂度：O(n*n)
 * 空间复杂度: O(1)
 * 
 * 2. 双指针
 * 1个指针指向左边，1个指针指向右边。
 * 当前容器面积 = min(左边高度, 右边高度) * 距离
 * 
 * 显然指针移动, 距离就会减小; 那么面积取决于min(左边高度, 右边高度);
 * 就取决于左边高度, 右边高度的最小值; 所以移动时只要移动 左边高度, 右边高度
 * 中的最小值即可;
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(2n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxArea(vector<int> &height)
{
    int sz = height.size();
    int i = 0, j = sz - 1;
    int maxValue = 0;
    while(i < j)
    {
        if (height[i] < height[j])
        {
            maxValue = std::max(maxValue, height[i] * (j - i));
            ++i;
        }
        else
        {
            maxValue = std::max(maxValue, height[j] * (j - i));
            --j;
        }
        
    }
    return maxValue;
}


// int maxArea(vector<int> &height)
// {
//     int maxValue = 0;
//     for(int i = 0; i < height.size() - 1; ++i)
//     {
//         for(int j = 1; j < height.size(); ++j)
//         {
//             int area = std::min(height[i], height[j]) * (j - i);
//             maxValue = std::max(area, maxValue);
//         }
//     }
//     return maxValue;
// }


int main()
{
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(nums) << std::endl;
    return 0;
}
