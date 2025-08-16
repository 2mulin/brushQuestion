/**
 * @date 2025/8/16
 * @author 2mu
 * @brief easy 6和9组成的最大数字
 *
 * 1. 贪心
 * 只能反转一次，反转后的数字变大，那肯定就是反转最位于左边的6。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>


int maximum69Number(int num)
{
    std::string s = std::to_string(num);
    for(int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '6')
        {
            s[i] = '9';
            break;
        }
    }
    return std::stoi(s);
}


int main()
{
    std::cout << maximum69Number(9669) << std::endl;
    return 0;
}
