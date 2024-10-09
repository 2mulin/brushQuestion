/**
 * @date 2022/6/13
 * @author 2mu
 * @brief easy 高度检查器
 *
 * 1. 排序+遍历
 * 题目意思就是比较未排序数组和已排序数组中，有多少元素不同。最简单的思路就是按照要求排序一次，然后遍历两个排序和未排序数组，比较一次。
 * 就可以了。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 
 * 2. 计数排序
 * 注意看题目，数组中的数字大小是有限制的。1 <= arr[i] <= 100, 所以可以使用计数排序。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 排序+遍历
int heightChecker(vector<int>& heights)
{
    int result = 0;
    std::vector<int> arr = heights;
    std::sort(arr.begin(), arr.end());

    for(size_t i = 0; i < arr.size(); ++i)
    {
        if(arr[i] != heights[i])
            ++result;
    }
    return result;
}
*/

int heightChecker(vector<int>& heights)
{
    std::vector<short> arr(101, 0);
    for(auto height : heights)
    {
        ++arr[height];
    } 

    // 前缀和
    for(size_t i = 1; i < arr.size(); ++i)
    {
        arr[i] += arr[i-1];
    }

    int result = 0;
    for(size_t i = 0; i < heights.size(); ++i)
    {
        int height = heights[i];
        if(i < arr[height] && i >= arr[height - 1])
            continue;
        else
            ++result;
    }
    return result;
}


int main()
{
    return 0;
}
