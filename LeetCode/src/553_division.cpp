/**
 * @author ling
 * @date 2021/2/27
 * @brief medium 最优除法
 *
 * 1. 栈 遍历
 * 时间复杂度: O(N的N次方)      空间复杂度: O(N)
 *
 * 2. 遍历
 * 数学，仔细想想，必须是除法，计算结果要最大，什么情况呢？
 * 就是让分子尽可能大，分母尽可能小。分子大就只能是 nums[0], 要不然就是nums[0]除以小数，达到翻倍的效果。
 * 但是条件限制元素大小都是 >1的整数。
 * 
 * 分母就是个子问题了。去掉nums[0]之后，算下的元素怎么除最大？
 * 一样的思路。
 * 时间复杂度：O(N)       空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>

std::string optimalDivision(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return std::to_string(nums[0]);
    if (nums.size() == 2)
        return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);

    std::string ans = std::to_string(nums[0]);
    ans = ans + "/(" + std::to_string(nums[1]);
    for (int i = 2; i < nums.size(); ++i)
        ans = ans + "/" + std::to_string(nums[i]);
    ans += ")";
    return ans;
}

int main()
{

    return 0;
}