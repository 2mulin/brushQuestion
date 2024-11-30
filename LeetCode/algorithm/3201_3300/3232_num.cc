/**
 * @date 2024/11/30
 * @author 2mu
 * @brief easy 判断是否可以赢得数字游戏
 *
 * 1. 模拟
 * 无非就是两种情况，一种是Alice选择所有个位数字，一种就是Alice选择所有两位数。
 * 然后试试看Alice能不能赢。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>


using namespace std;


bool canAliceWin(vector<int> &nums)
{
    int sum1 = 0, sum2 = 0;
    for(auto num : nums)
    {
        if(num < 10)
            sum1 += num;
        else
            sum2 += num;
    }
    if (sum1 != sum2)
        return true;
    return false;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{1,2,3,4,10};
    std::cout << canAliceWin(nums) << std::endl;
    return 0;
}
