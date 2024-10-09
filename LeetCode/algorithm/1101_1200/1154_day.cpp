/**
 * @date 2023/12/31
 * @author 2mu
 * @brief easy 一年中的第几天
 *
 * 1. 普通计算
 * 计算过去了几个月, 然后将过去的每个月的天数加起来, 就是一年中的第几天;
 * 每个月的天数都是固定的, 除了闰年的2月多一天, 所以需要判断闰年
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<int> month_day{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int dayOfYear(string date)
{
    int day = 0;

    int month = stoi(date.substr(5, 2));
    if (month > 2)
    {
        int year = stoi(date.substr(0, 4));
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            day += 1;
    }
    day += stoi(date.substr(8, 2));
    for (int i = 0; i < month - 1; ++i)
    {
        day += month_day[i];
    }
    return day;
}

int main()
{
    std::cout << dayOfYear("2019-02-10") << std::endl;
    return 0;
}