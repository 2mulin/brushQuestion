/**
 * @date 2022/2/15
 * @author 2mu
 * @brief hard 好数组
 *
 * 一、数论
 * 利用到了裴蜀定理。具体不多BB，我就直接抄了。利用其推论：
 * 题目等价于求nums中的全部数字的最大公约数是否等于1，若等于 1 则原数组为「好数组」，否则不是。
 * 
 * 求多个数的最大公约数的方法，任意两个数的最小公约数再去和其它数 求最小公约数，全部求一遍，得到的就是
 * 最小公约数。
 * 
 * 还可以回忆下求最小公约数的实现，也就是gcd，一般就是辗转相除法。记住除数不能为0
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGoodArray(std::vector<int>& nums)
{
    int divisor = nums[0];
    for(size_t i = 1; i < nums.size(); ++i)
    {
        divisor = __gcd(divisor, nums[i]);
        if(divisor == 1)
            break;
    }
    return divisor == 1;
}

int main()
{
    std::vector<int> nums{12, 5, 7, 23};
    std::cout << isGoodArray(nums) << std::endl;
    return 0;
}
