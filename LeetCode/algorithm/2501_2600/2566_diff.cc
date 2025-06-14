/**
 * @date 2025/6/14
 * @author 2mu
 * @brief easy 替换一个数字后的最大差值
 *
 * 1. 分析（贪心）
 * 总体来看，不管是想使数字变大还是变小，都应该是优先替换第一位，
 * 但如果第一位本来就是9，那么它就不需要替换，那么是替换第1个不为9的元素。
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
            {
                replace_ch = numStr[i];
            }
        }
        if (numStr[i] == replace_ch)
            numStr[i] = '9';
    }
    int maxNum = std::stoi(numStr.c_str());

    numStr = std::to_string(num);
    replace_ch = numStr[0];
    for(int i = 0; i < numStr.length(); ++i)
    {
        if (numStr[i] == replace_ch)
            numStr[i] = '0';
    }
    int minNum = std::stoi(numStr.c_str());
    return maxNum - minNum;
}


int main()
{
    std::cout << minMaxDifference(90) << std::endl;
    std::cout << minMaxDifference(11891) << std::endl;
    return 0;
}
