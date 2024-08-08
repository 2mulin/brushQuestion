/**
 * @date 2024/8/8
 * @author 2mu
 * @brief easy 找出与数组相加的整数I
 *
 * 1. 排序
 * 先将两个数组排序, 然后比较数组的第一个元素的差值是多少, 假设为x;
 * 然后变量一遍这两个数组, 如果最终两数组中每个位置对应的值的差值都是x, 那就说明满足条件, 输出x即可, 否则就是不满足;
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 * 
 * 2. 遍历
 * 实际上遍历就行, 因为一定有答案... 所以只需要找到两个数组的最大值或者最小值, 做一个差值, 就是答案...
 * 这里不改了, 以后刷到再改吧..
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int addedInteger(vector<int> &nums1, vector<int> &nums2)
{
    int result = 0;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    result = nums2.front() - nums1.front();
    for (int i = 1; i < nums1.size(); ++i)
    {
        if (nums2[i] - nums1[i] != result)
            return 0;
    }
    return result;
}

int main(int argc, char **argv)
{
    return 0;
}

