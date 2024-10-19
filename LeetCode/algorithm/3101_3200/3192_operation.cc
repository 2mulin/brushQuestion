/**
 * @date 2024/10/19
 * @author 2mu
 * @brief medium 使二进制数组全部等于1的最少操作次数II
 *
 * 1. 枚举
 * 从左往右开始枚举, 用i表示下标;
 * 如果 nums[i] 是1, 那么表示不需要从这里反转;
 * 如果 nums[i] 是0, 那么一定需要从这里反转1次;
 * 
 * 如果只是模拟的话, 每反转一次就是把i后面的所有翻转改变一下, 那么两层循环时间复杂度是(n*n)
 * 怎么避免两层循环呢?
 * 
 * 也就是需要判断反转后, 当前nums[i]是否需要反转... 通过当前nums[i] 和累计的operator次数即可判断;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int minOperations(vector<int> &nums)
{
    int operation = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if ((operation % 2) && nums[i])
            ++operation;
        else if (!(operation % 2) && !nums[i])
            ++operation;
    }
    return operation;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{0,1,1,0,1};
    std::cout << minOperations(nums) << std::endl;
    return 0;
}
