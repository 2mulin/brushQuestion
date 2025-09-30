/**
 * @date 2025/9/30
 * @author 2mu
 * @brief medium 数组的三角和
 *
 * 1. 模拟
 * 按照题目要求进行模拟。为了减少空间利用，可以使用当前数组原位替换。
 * 因为每次的新数组一定小于当前数组，可以这么做，空间是够的。
 *
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int triangularSum(vector<int> &nums)
{
    int size = nums.size();
    while(size > 1)
    {
        for(int i = 0; i < size - 1; ++i)
        {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        --size;
    }
    return nums.front();
}

int main()
{
    std::vector<int> nums{1,2,3,4,5};
    std::cout << triangularSum(nums) << std::endl;
    return 0;
}
