/**
 * @date 2025/6/15
 * @author 2mu
 * @brief medium 替换一个数字后的最大差值
 *
 * 1. 贪心
 * 之前做了该题的简单版本，了解到了解题方法是贪心。
 * 这里看起来还是可以使用相同方法，只是这里可以替换两次，也就是替换前两位数字(非9，非0)。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int minMaxDifference(int num)
{
    std::string numStr = std::to_string(num);
    char replace_ch = ' ';
    for(int i = 0; i < numStr.length(); ++i)
    {
        if (replace_ch == ' ')
        {
            if (numStr[i] == '9')
                continue;
            else
                replace_ch = numStr[i];
        }
        if (numStr[i] == replace_ch)
            numStr[i] = '9';
    }
    int maxNum = std::stoi(numStr.c_str());

    numStr = std::to_string(num);
    if (numStr[0] != '1')
    {
        replace_ch = numStr[0];
        // 第一位数字不是1，不能有前导0，所以将与第一位数相同的数都切换为1
        for(int i = 0; i < numStr.length(); ++i)
        {
            if(numStr[i] == replace_ch)
                numStr[i] = '1';
        }
    }
    else 
    {
        // 第一位数字是1，则后续第1个非0，非1的数字 切换为0即可
        replace_ch = ' ';
        for(int i = 1; i < numStr.length(); ++i)
        {
            if (replace_ch == ' ')
            {
                if(numStr[i] == '0' || numStr[i] == '1')
                    continue;
                replace_ch = numStr[i];
            }
            if (numStr[i] == replace_ch)
                numStr[i] = '0';
        }
    }
    int minNum = std::stoi(numStr.c_str());
    return maxNum - minNum;
}


int main()
{
    // 正确要输出888
    std::cout << minMaxDifference(555) << std::endl;
    // 正确要输出8808
    std::cout << minMaxDifference(1101) << std::endl;
    // 正确要输出8
    std::cout << minMaxDifference(9) << std::endl;
    return 0;
}
