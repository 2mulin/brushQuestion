/**
 * @date 2024/6/29
 * @author 2mu
 * @brief easy 移除字符串中的尾随零
 *
 * 1. 模拟
 * 从后往前遍历，将开头碰到的0全部删除。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>


using namespace std;

string removeTrailingZeros(string num)
{
    while(num.length())
    {
        if(num.back() == '0' )
            num.pop_back();
        else
            break;
    }
    return num;
}

int main(int argc, char **argv)
{
    std::cout << removeTrailingZeros("51230100") << std::endl;
    std::cout << removeTrailingZeros("123") << std::endl;
    std::cout << removeTrailingZeros("123000") << std::endl;
    return 0;
}

