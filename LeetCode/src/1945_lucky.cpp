/**
 * @date 2022/12/15
 * @author 2mu
 * @brief easy 字符串转化之后的各位数字之和
 * 
 * 一. 模拟
 * 按部就班，完成转化，计算数字之和N次。就可以了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int digitSum(int num)
{
    int sum = 0;
    while(num)
    {
        int i  = num % 10;
        sum += i;
        num /= 10;
    }
    return sum;
}

int getLucky(std::string s, int k)
{
    int sum = 0;
    for(char ch : s)
    {
        int val = ch - 'a' + 1;
        sum += digitSum(val);
    }
    for(int i = 0; i < k - 1; ++i)
    {
        sum = digitSum(sum);
    }
    return sum;
}

int main()
{
    std::cout << getLucky("iiii", 1) << std::endl;
    std::cout << getLucky("leetcode", 2) << std::endl;
    return 0;
}
