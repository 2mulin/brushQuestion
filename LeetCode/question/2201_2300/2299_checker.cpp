/**
 * @date 2022/1/19
 * @author 2mu
 * @brief easy 强密码检测器II
 * 
 * 一、模拟
 * 很简单，按要求模拟就可以了。
 * 最后遍历一遍，检查每个字符即可。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

static std::unordered_set<char> g_setSpChar {
    '!', '@', '#',
    '$', '%', '^',
    '&', '*', '(',
    ')', '-', '+'
};

bool strongPasswordCheckerII(std::string password)
{
    if(password.length() < 8)
        return false;
    bool isContainUpperCh = false, isContainLowerCh = false;
    bool isContainDigit = false, isContainSpCh = false;
    for(int i = 0; i < password.length(); ++i) 
    {
        char ch = password[i];
        if( ch >= '0' && ch <= '9')
        {
            isContainDigit = true;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            isContainLowerCh = true;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            isContainUpperCh = true;
        }
        else if(g_setSpChar.find(ch) != g_setSpChar.end())
        {
            isContainSpCh = true;
        }

        if(i != password.length() - 1)
        {
            if(ch == password[i + 1])
                return false;
        }
    }
    if(isContainDigit && isContainLowerCh && isContainUpperCh && isContainSpCh)
        return true;
    return false;
}

int main()
{
    std::string str = "+Aa1a1a1";
    std::cout << strongPasswordCheckerII(str) << std::endl;
    return 0;
}
