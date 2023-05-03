/**
 * @date 2023/5/3
 * @author 2mu
 * @brief medium 有效字符串
 *
 * 1. 枚举
 * 按照要求检查字符串是否有效, 字符串长度最大是 20000, 每次每次转换会增加3个字符, 20000 / 3 = 6667
 * 也就是说最多转换 6667 次; 超过6667次, 就不满足长度限制了; 每次有 当前 str.len + 1 种插入位置; 累乘 1,4,7,11.....
 *
 * 复杂度有点高, 所以枚举不适合;
 *
 * 时间复杂度: O()
 * 空间复杂度: O(n)
 *
 * 2. stack
 * 利用栈入栈,出栈的规则, 只要当前栈顶是 abc 三个字符连起来, 就abc出栈, 否则就入栈;
 * 如果最后栈为空, 表示满足条件, 否则不满足;
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isValid(string s)
{
    std::string tmpStr;
    for (auto ch : s)
    {
        tmpStr.push_back(ch);
        int tmpStrLen = tmpStr.length();
        if (tmpStrLen >= 3 && tmpStr[tmpStrLen - 1] == 'c' && tmpStr[tmpStrLen - 2] == 'b' && tmpStr[tmpStrLen - 3] == 'a')
        {
            tmpStr.pop_back();
            tmpStr.pop_back();
            tmpStr.pop_back();
        }
    }
    if(tmpStr.empty())
        return true;
    return false;
}

int main()
{
    std::cout << isValid("aabcbc") << std::endl;
    std::cout << isValid("abcabcababcc") << std::endl;
    std::cout << isValid("abccba") << std::endl;
    std::cout << std::endl;
    return 0;
}