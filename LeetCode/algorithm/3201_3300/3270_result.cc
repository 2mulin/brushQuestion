/**
 * @date 2025/1/11
 * @author 2mu
 * @brief easy 求出数学答案
 *
 * 1. 模拟
 * 直接模拟的，没什么多说的。但实际上查看题解还是有一些规律的。
 * 从后往前枚举更加容易，而且不需要加前导0，因为一旦出现当前位置没有数字，
 * 说明前面都是0，可以退出枚举。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


std::string intToStr(int num)
{
    std::string str1 = std::to_string(num);
    while (str1.length() < 4)
    {
        str1.insert(str1.begin(), '0');
    }
    return str1;
}


int generateKey(int num1, int num2, int num3)
{
    std::string str1 = intToStr(num1);
    std::string str2 = intToStr(num2);
    std::string str3 = intToStr(num3);

    int num = 0;
    for(int i = 0; i < 4; ++i)
    {
        int bit = std::min(str1[i] - '0', str2[i] - '0');
        bit = std::min(bit, str3[i] - '0');
        num = num * 10 + bit;
    }
    return num;
}


int main()
{
    std::cout << generateKey(1, 10, 1000) << std::endl;
    return 0;
}
