/**
 * @author ling
 * @date 2021/2/25
 * @brief medium 复数乘法
 * 
 * 1. 模拟
 * 完全模拟复数乘法运算就可以了。主要就是解析字符串为数字耗时。
 * 时间复杂度: O(N)      空间复杂度: O(N)
 * 
 * 2. 正则表达式
 * 官方题解使用正则表达式解析数字出来。
 */

#include <iostream>
#include <string>
#include <map>

struct Complex
{
    int realNum;
    int virtualNum;

public:
    Complex(int num1, int num2)
        :realNum(num1), virtualNum(num2)
    {}

    Complex(std::string num)
        :realNum(0), virtualNum(0)
    {
        auto iter = num.begin();
        bool isMinus = false;
        while (iter != num.end())
        {
            if(*iter == '-')
            {
                isMinus = true;
                ++iter;
                continue;
            }
            if(*iter == '+')
            {
                realNum /= 10;
                break;
            }
            realNum += (*iter - '0');
            realNum *= 10;
            ++iter;
        }
        if(isMinus)
        {
            isMinus = false;
            realNum *= -1;
        }
        ++iter;
        while(iter != num.end())
        {
            if(*iter == '-')
            {
                isMinus = true;
                ++iter;
                continue;
            }
            if(*iter == 'i')
            {
                virtualNum /= 10;
                break;
            }
            virtualNum += (*iter - '0');
            virtualNum *= 10;
            ++iter;
        }
        if(isMinus)
            virtualNum *= -1;
    }

    std::string toString()
    {
        return std::to_string(realNum) + "+" + std::to_string(virtualNum) + "i";
    }

    Complex operator*(const Complex& other)
    {
        int ac = realNum * other.realNum;
        int bd = virtualNum * other.virtualNum;
        int ad = realNum * other.virtualNum;
        int bc = virtualNum * other.realNum;
        return Complex(ac - bd,  bc + ad);
    }
};

std::string complexNumberMultiply(std::string num1, std::string num2) 
{
    Complex complexNum1 = Complex(num1);
    Complex complexNum2 = Complex(num2);
    Complex ans = complexNum1 * complexNum2;
    return ans.toString();
}

int main()
{
    std::cout << complexNumberMultiply("78+-76i","-86+72i") << std::endl;
    return 0;
}