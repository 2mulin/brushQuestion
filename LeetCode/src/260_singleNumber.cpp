/**
 * @date 2023/10/16
 * @author 2mu
 * @brief medium 出现过一次的数字 
 *
 * 1. 哈希表
 * 使用哈希表记录数组中的元素出现过几次; 最终遍历哈希表找到只出现过一次的数字;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. 位运算
 * 官方解法, 非常巧妙, 妙不可言;
 * 首先异或运算的几个性质就不说了, 忘了, 可以看136题去;
 * nums中有两个数字没有重复, 假设其分别为x,y; 其它数字都重复两次; 所以将nums所有数字异或, 得到的结果是: xor_sum = x ^ y;
 * xor_sum一定不等于0, 因为那样就表示x==y, 违反题意;
 * 
 * 找到xor_sum最低位为1的那一位, 假设为lsb位, 然后再把nums分为a组, b组;
 * a组所有数字的lsb位都是1, b组所有数字的lsb位都是0; 
 * 
 * x, y一定是在不同的组, 所以最后分别对a组,b组再做一次异或, 就可以得到答案;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> singleNumber(vector<int> &nums)
{
    int xorsum = 0;
    for(auto num : nums)
    {
        xorsum ^= num;
    }
    long long lsb = 1;
    while((xorsum & lsb) == false)
    {
        lsb <<= 1;
    }
    int x = 0, y = 0;
    for(auto num : nums)
    {
        if(lsb & num)
        {
            x ^= num;
        }
        else
        {
            y ^= num;
        }
    }
    return std::vector<int>{x, y};
}

int main()
{
    std::vector<int> vct{1, 3, 3, 2, 2, 4};
    std::vector<int> ans = singleNumber(vct);
    for(auto num : ans)
        std::cout << num << '\t';
    std::cout << std::endl;
    return 0;
}
