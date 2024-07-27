/**
 * @date 2023/12/30
 * @author 2mu
 * @brief easy 一周的第几天
 *
 * 1. 模拟
 * 选定一个基准点, 比如1970年1月1日是星期几; 后面每隔7天就是一个轮换;
 * 就可以计算出当前是星期几;
 * 
 * 思路和官方文档一直, 但是却写不出来, 我还是不擅长写这种特殊情况非常多的代码; 很容易把自己绕进去;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<int> month_day{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

string dayOfTheWeek(int day, int month, int year)
{
    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    /* 以1970年12月31日为起点, 这天是星期4, 每一年份的天数贡献, 4年一润 */
    int days = 365 * (year - 1971) + (year - 1969) / 4;
    /* 输入年份中，输入月份之前的月份的天数贡献 */
    for (int i = 0; i < month - 1; ++i) {
        days += monthDays[i];
    }
    if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
        days += 1;
    }
    /* 输入月份中的天数贡献 */
    days += day;
    // 加3之后, 就会从星期一开始计算, 而不是星期四;
    return week[(days + 3) % 7];
}

int main()
{

    return 0;
}