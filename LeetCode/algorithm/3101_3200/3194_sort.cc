/**
 * @date 2024/10/16
 * @author 2mu
 * @brief easy 最小元素和最大元素的最小平均值
 *
 * 1. 排序 + 模拟
 * 
 * 先将nums数组排序，然后按照题目要求进行模拟，最小元素就是数组开头元素，最大元素就是数组最后一个元素。
 * 每次分别取出开头元素，末尾元素进行计算。
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <float.h>


using namespace std;

double minimumAverage(vector<int> &nums)
{
    double result = DBL_MAX;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size / 2; ++i)
    {
        result = min(result, (nums[i] + nums[size - 1 - i]) / (double)2);
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{7,8,3,4,15,13,4,1};
    std::cout << minimumAverage(nums) << std::endl;
    return 0;
}
