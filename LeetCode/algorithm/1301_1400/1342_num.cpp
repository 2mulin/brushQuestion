/**
 * @date 2022/8/7
 * @author 2mu
 * @brief easy 把数字变成0需要步骤数
 *
 * 1. dp
 * 显然也是一个DP，题目数字范围是[0, 1000000]。空间不是很大。可以使用数组。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 2. 优化空间
 * 
 * 直接使用递归。从上往下算，就不需要nums[1000001]这么大的数组了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(logN)
 */

#include <iostream>

using namespace std;

int numberOfSteps(int n)
{
    if(n == 0)
        return 0;
    if(n % 2)
        return numberOfSteps(n - 1) + 1;
    return numberOfSteps(n / 2) + 1;
}

/*
int numberOfSteps(int n)
{ 
    int nums[1000001] = {0};
    nums[1] = 1;
    nums[2] = 2;
    for(int i = 3; i <= n; ++i)
    {
        if(i % 2)
            nums[i] = nums[i - 1] + 1;
        else
            nums[i] = nums[i / 2] + 1;
    }
    return nums[n];
}
*/

int main()
{
    std::cout << numberOfSteps(1000000) << std::endl;
    return 0;
}
