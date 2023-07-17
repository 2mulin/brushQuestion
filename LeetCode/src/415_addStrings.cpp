/**
 * @date 2023/7/16
 * @author 2mu
 * @brief easy 字符串相加
 * 
 * 1. 模拟
 * 模拟按位加法即可; 从前往后计算; 多用一个字符表示进位;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
    std::string ans;
    int carry = 0; // 进位
    auto iter1 = num1.rbegin(), iter2 = num2.rbegin();
    while(iter1 != num1.rend() || iter2 != num2.rend())
    {
        int num = 0;
        if(iter1 != num1.rend())
        {
            num = *iter1 - '0';
            ++iter1;
        }
        if(iter2 != num2.rend())
        {
            num = num + *iter2 -'0';
            ++iter2;
        }
        num += carry;
        if(num >= 10)
            carry = 1;
        else
            carry = 0;
        ans.push_back(char('0' + num % 10));
    }
    // 不要忘记这一步, 要考虑全面...
    if(carry)
        ans.push_back('1');
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    std::cout << addStrings("11", "123") << std::endl;
    std::cout << addStrings("0", "0") << std::endl;
    std::cout << addStrings("456", "77") << std::endl;
    return 0;
}
