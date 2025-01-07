/**
 * @date 2025/1/8
 * @author 2mu
 * @brief medium 按键变更的次数
 *
 * 1. 遍历
 * 所有不区分大小写，然后比较遍历整个字符串，
 * 若是当前字符和上一个字符不同，说明有了一次变化。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>


using namespace std;


int countKeyChanges(string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });

    int result = 0;
    for(int i = 1; i < s.length(); ++i)
    {
        if(s[i] != s[i-1])
            ++result;
    }
    return result;
}


int main()
{
    std::cout << countKeyChanges("abcCCd") << std::endl;
    std::cout << countKeyChanges("bBBb") << std::endl;
    return 0;
}
