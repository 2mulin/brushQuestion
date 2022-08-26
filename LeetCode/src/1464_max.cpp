/**
 * @date 2022/8/26
 * @author 2mu
 * @brief easy 数组中两元素的最大乘积
 *
 * 一. 暴力
 * 直接遍历所有可能，计算出乘积最大值。
 * 
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 * 
 * 二. 排序
 * 排序之后，在计算最大乘积，那最大乘积一定是最后两个元素相乘。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 * 
 * 三. 一次遍历
 * 遍历一遍数组，直接将最大值，和次大值记录下来。然后相乘得到结果。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums)
{
    int num1 = 0, num2 = 0;
    for(auto num : nums)
    {
        if(num1 < num)
        {
            num2 = num1;
            num1 = num;
        }
        else if(num2 < num)
            num2 = num;
    }
    return (num1 - 1) * (num2 - 1);
}

int main()
{
    std::vector<int> arr{1,2,3,4,5};
    std::cout << maxProduct(arr) << std::endl;
    return 0;
}
