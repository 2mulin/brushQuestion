/**
 * @date 2025/1/1
 * @author 2mu
 * @brief easy 将日期转换为二进制表示
 *
 * 1. 模拟
 * 按照条件进行转换即可，非常简单。
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

string convertDateToBinary(string date)
{
    std::string result = "";

    int num = 0;
    for (char ch : date)
    {
        if (ch >= '0' && ch <= '9')
        {
            num *= 10;
            num += (ch - '0');
        }
        else
        {
            std::string tmp;
            // 除2取余法
            while(num)
            {
                int remainder = num % 2;
                tmp.push_back(char('0' + remainder));
                num = num / 2;
            }
            std::reverse(tmp.begin(), tmp.end());

            result += tmp;
            result.push_back('-');
        }
    }

    std::string tmp;
    while (num)
    {
        int remainder = num % 2;
        tmp.push_back(char('0' + remainder));
        num = num / 2;
    }
    std::reverse(tmp.begin(), tmp.end());
    result += tmp;
    
    return result;
}

int main()
{
    return 0;
}
