/**
 * @date 2022/10/2
 * @author 2mu 在LR字符串中交换相邻字符
 * @brief
 *
 * 一. 暴力枚举
 * 题目说了，只要是XL就可以换成LX，RX就可以换成XR。最简单的方式：
 * 1. 遍历整个字符串，得出所有可以交换位置的地方。可交换位置为0，退出，返回false。
 * 2. 选择任意一个交换。重新得到一个字符串。
 * 3. 记录当前字符串，并且比较是否是end。不是的继续1，2步骤。
 *
 * 时间复杂度：太高了，且容易死循环
 * 空间复杂度：也很高，需要保存每一个状态
 * 
 * 二. 双指针
 * 要认真分析问题，首先第一点：
 * 1. 不管是XL变化成LX，还是RX变化成XR，都是不会改变字母种类和个数的。
 * 所以，begin可以转化成end的第一个条件就是begin和end，字母个数种类相等。
 * 2. 字母L和R的相对顺序相等，字母L在end的下标 <= 字母L在begin中的下标。字母R在end中的下标 >= 字母L在begin中的下标。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>

using namespace std;

bool canTransform(string start, string end)
{
    int pos1 = 0, pos2 = 0;
    int len =  end.length();

    int xCount1 = 0, xCount2 = 0;
    while(pos1 < len && pos2 < len)
    {
        if(start[pos1] == 'X')
        {
            ++xCount1;
            ++pos1;
            continue;
        }
        if(end[pos2] == 'X')
        {
            ++xCount2;
            ++pos2;
            continue;
        }

        if(start[pos1] == end[pos2])
        {
            if(start[pos1] == 'L' && pos1 < pos2)
                return false;
            if(start[pos1] == 'R' && pos1 > pos2)
                return false;
            ++pos1;
            ++pos2;
        }
        else
            return false;
    }
    while(pos1 < len)
    {
        if(start[pos1] == 'X')
        {
            ++pos1;
            ++xCount1;
        }
        else
            return false;
    }
    while(pos2 < len)
    {
        if(end[pos2] == 'X')
        {
            ++pos2;
            ++xCount2;
        }
        else
            return false;
    }
    if(xCount1 != xCount2)
        return false;
    return true;
}

int main()
{
    std::string begin = "RXXLRXRXL", end = "XRLXXRRLX";
    std::cout << canTransform(begin, end) << std::endl;
    return 0;
}
