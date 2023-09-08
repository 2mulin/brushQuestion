/**
 * @date 2023/9/8
 * @author 2mu
 * @brief easy 从两个数字数组里生成最小数字
 *
 * 1. 模拟
 * 数组长度最多也就是10, 两种情况:
 * 如果两个数组中有两个相同的数字, 则选择相同的数字, 因为是相同数字可以组合为个位数
 * 如果两个数组中不是相同数字, 则选择两个最小的数字;
 * 
 * 时间, 空间复杂度就算O(1)吧, 因为都是定长的, 数组最多10个元素
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int minNumber(vector<int> &nums1, vector<int> &nums2)
{
    int min1 = 10, min2 = 10;
    int arr[10] = {0};
    for(auto num : nums1)
    {
        ++arr[num];
        min1 = min(num, min1);
    }
    for(auto num : nums2)
    {
        ++arr[num];
        min2 = min(num, min2);
    }

    for(int i = 0; i < 10; ++i)
    {
        if(arr[i] == 2)
            return i;
    }

    if(min1 < min2)
        return min1 * 10 + min2;
    else
        return min2 * 10 + min1;
}

int main()
{
    return 0;
}
