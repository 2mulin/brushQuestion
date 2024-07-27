/**
 * @date 2023/10/14
 * @author 2mu
 * @brief easy 指出现过一次的数字 
 *
 * 1. 异或
 * 数字a==b, 则a ^ b = 0; 利用这条性质, 非常容易就可以找出只出现过一次的数字;
 * 异或运算有3个性质:
 *  a. 任何数字x与0做异或运算, 结果都是x
 *  b. 同一个数字x, 与自身做异或运算, 结果是0
 *  c. 异或运算满足结合律, 交换律;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = nums.front();
    for(size_t i = 1; i < nums.size(); ++i)
    {
        ans ^= nums[i];
    }
    return ans;
}

int main()
{
    std::vector<int> vct{1, 1, 3, 3, 2};
    std::cout << singleNumber(vct) << std::endl;
    return 0;
}
