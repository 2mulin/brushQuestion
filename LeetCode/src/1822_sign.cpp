/**
 * @date 2022/10/27
 * @author 2mu
 * @brief easy 数组元素乘积的符号
 * 
 * 一. bool,计数
 * 判断整个数组所有元素乘积的正负号。暴力法肯定是全部乘一遍。但是这里肯定不需要，只需要统计
 * 正负号的个数就OK了。
 * 
 * 如果提前碰到0，直接返回0。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int arraySign(vector<int> &nums)
{
    int count = 0;          // 负数个数
    for(auto num : nums)
    {
        if(num < 0)
            ++count;
        else if(num > 0)
            continue;
        else
            return 0;
    }
    if(count % 2)
        return -1;
    return 1;
}

int main()
{
    vector<int> nums{-1,-2,-3,-4,3,2,1};
    std::cout << arraySign(nums) << std::endl;
    return 0;
}
