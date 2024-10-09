/**
 * @date 2023/1/25
 * @author 2mu
 * @brief easy 计算k置位下标对应元素
 *
 * 1. 枚举
 * 查看数组元素个数, 然后就知道所有下标了; 此时判断下标是否满足条件即可;
 * 实际下标是固定的, 只需要计算一次即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    if(k == 0)
        return nums.front();

    int sum = 0;
    for(int i = 1; i < nums.size(); ++i)
    {
        int bit = 0;
        int tmp = i;
        while(tmp)
        {
            if(tmp & 1)
                ++bit;
            tmp >>= 1;
        }
        if(bit == k)
            sum += nums[i];
    }
    return sum;
}

int main()
{
    std::vector<int> nums{-5, 10, 1, 5, 2};
    std::cout << sumIndicesWithKSetBits(nums, 1) << std::endl;
    return 0;
}