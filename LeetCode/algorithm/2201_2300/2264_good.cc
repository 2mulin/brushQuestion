/**
 * @date 2025/1/8
 * @author 2mu
 * @brief easy 字符串中最大的3位相同数字
 *
 * 1. 遍历
 * 找到最大值，同时注意000也是满足条件，以及优质数字不存在的情况。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


string largestGoodInteger(string num)
{
    int max_great_num = -1;
    for(int i = 1; i < num.length() - 1; ++i)
    {
        if (num[i] == num[i - 1] && num[i] == num[i + 1])
        {
            int great_num = (num[i] - '0') * 100 + (num[i] - '0') * 10 + (num[i] - '0');
            max_great_num = std::max(max_great_num, great_num);
        }
    }
    if (max_great_num == -1)
        return "";
    else if(max_great_num == 0)
        return "000";
    return std::to_string(max_great_num);
}

int main()
{
    std::cout << largestGoodInteger("6777133339") << std::endl;
    std::cout << largestGoodInteger("2300019") << std::endl;
    return 0;
}
