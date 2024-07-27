/**
 * @date 2022/1/15
 * @author 2mu
 * @brief easy 极大极小游戏
 * 
 * 一、模拟
 * 按照题目要求实现，就可以了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 二、原地修改
 * nums数组不需要重复赋值，可以直接原地修改，因为每次只会访问到一半的数组一半的空间，且不会访问已访问过的数据。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

int minMaxGame(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;
    while(nums.size() != 1)
    {
        size_t n = nums.size();
        std::vector<int> newNums(n/2, 0);
        for(int i = 0; i < n/2; ++i)
        {
            if(i % 2 == 0)
                newNums[i] = min(nums[i*2], nums[i*2 + 1]);
            else
                newNums[i] = max(nums[i*2], nums[i*2 + 1]);
        }
        nums = newNums;
    }
    return nums.front();
}

int main()
{
    std::vector<int> nums{1,3,5,2,4,8,2,2};
    std::cout << minMaxGame(nums) << std::endl;
    return 0;
}
