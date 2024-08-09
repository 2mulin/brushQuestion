/**
 * @date 2024/8/9
 * @author 2mu
 * @brief medium 找出与数组相加的整数II
 *
 * 1. 排序 + 枚举
 * 先将两个数组排序, 题目说明了只有nums1比nums2多2两个不满足条件的元素;
 * 实际上 nums1 的前3个元素中就必定有一个满足条件; 只需要枚举这种情况;
 * 也就是 diff1 = nums1[0] - nums2[0], diff2 = nums1[1] - nums2[0], diff3 = nums1[2] - nums2[0]
 * 
 * 这里面diff1, diff2, diff3必然有一个满足条件, 只需要各自遍历一遍确认下来;
 * 注意题目要求计算diff1, diff2, diff3中的最小值...
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
{
    int result = INT_MAX;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    for(int i = 0; i < 3; ++i)
    {
        int diff = nums2[0] - nums1[i], error = 2 - i;
        int idx = i + 1, j = 1;
        while(j < nums2.size())
        {
            if(diff !=  nums2[j] - nums1[idx])
            {
                if(error == 0)
                    break;
                --error;
            }
            else
                ++j;
            ++idx;
        }
        // 注意判断边界条件, 由于nums2短, 所以判断j遍历完即可, nums1不需要遍历完, 因为可能最后两个就是错误的
        if (j == nums2.size() && error <= 2)
        {
            result = std::min(result, diff);
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums1{4, 20, 16, 12, 8};
    std::vector<int> nums2{14, 18, 10};

    std::cout << minimumAddedInteger(nums1, nums2) << std::endl;

    nums1 = {4,6,3,1,4,2,10,9,5};
    nums2 = {5,10,3,2,6,1,9};
    std::cout << minimumAddedInteger(nums1, nums2) << std::endl;
    return 0;
}
