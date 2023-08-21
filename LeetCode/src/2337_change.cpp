/**
 * @date 2023/8/21
 * @author 2mu
 * @brief medium 移动片段得到字符串
 *
 * 1. 双指针
 * 首先两个字符串的L和R字符的相对位置必然相同, 否则按规则移动start中的字符不可能得到target;
 * 按照规则: start字符串的 L只能向左移, 并且左边必须是 _ ; R只能向右移动, 并且右边必须是 _ ; 并且start和target元素数量相等
 * 
 * 这就可以推导出: start字符串的 L 位置 >= target字符串的 L 位置, start字符串的 R 位置 <= target字符串的 R 位置, 
 * 且start和target的LR相对位置, 个数相同; 就可以满足条件, 否则不满足
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>

using namespace std;

bool canChange(string start, string target)
{
    int len  = start.length();
    int i = 0, j = 0;
    while(i < len || j < len)
    {
        if(start[i] == target[j])
        {
            if(start[i] == 'L' && i < j)
                return false;
            if(start[i] == 'R' && i > j)
                return false;
            ++i;
            ++j;
        }
        else
        {
            if(start[i] == '_')
                ++i;
            else if(target[j] == '_')
                ++j;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    std::cout << canChange("_L__R__R_", "L______RR") << std::endl;
    std::cout << canChange("_R", "R_") << std::endl;
    std::cout << canChange("R_L_", "__LR") << std::endl;
    std::cout << canChange("_L__R__R_L", "L______RR_") << std::endl;
    return 0;
}
