/**
 * @date 2025/7/21
 * @author 2mu
 * @brief easy 删除字符使字符串变好
 *
 * 1. 遍历一遍
 * 遍历一遍字符串，并且遍历的同时统计当前连续的字符，以及连续的次数。
 * 当连续3次之后就特殊处理，不再记录添加当前字符到字符串末尾。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string makeFancyString(string s)
{
    std::string result;
    int cnt = 0;
    char ch = ' ';
    for(char item : s)
    {
        if (item == ch)
        {
            cnt++;
            if(cnt < 3)
            {
                result.push_back(item);
            }
        }
        else
        {
            ch = item;
            cnt = 1;
            result.push_back(item);
        }
    }
    return result;
}


int main()
{
    std::string s = "leeetcode";
    std::cout << makeFancyString(s) << std::endl;
    return 0;
}
