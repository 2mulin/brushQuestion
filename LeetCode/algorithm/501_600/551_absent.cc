/**
 * @date 2024/8/18
 * @author 2mu
 * @brief easy 学生出勤记录
 *
 * 1. 模拟
 * 遍历一遍字符串, 然后按照条件进行判定即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool checkRecord(string s)
{
    int absent_count = 0, late_day = 0;
    int max_late_day = 0;// 最大连续迟到天数
    for(const char ch : s)
    {
        switch (ch)
        {
        case 'A':
            ++absent_count;
            late_day = 0;
            break;
        case 'L':
            ++late_day;
            max_late_day = std::max(late_day, max_late_day);
            break;
        case 'P':
            late_day = 0;
        default:
            break;
        }
    }
    if(absent_count >= 2 || max_late_day >= 3)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    std::cout << checkRecord("PPALLP") << std::endl;
    std::cout << checkRecord("PPALLL") << std::endl;
    return 0;
}
