/**
 * @date 2022/10/11
 * @author 2mu
 * @brief easy 最多执行一次字符串交换是两个字符串相等
 *
 * 一. for循环
 * 过于简单，直接for循环比较两个字符串一次，如果只有两个字符不相等，并且是两个字符相同。
 * 那就满足条件，否则就不满足。
 * 
 * 最多一次交换，也就是说两字符串完全相等，也是满足条件的。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(2)
 */

#include <iostream>
#include <string>

bool areAlmostEqual(std::string s1, std::string s2)
{
    std::string diff1, diff2;
    int count = 0;
    for(size_t i = 0; i < s1.length(); ++i)
    {
        if(s1[i] != s2[i])
        {
            ++count;
            diff1.push_back(s1[i]);
            diff2.push_back(s2[i]);
        }
    }
    if(count == 2 && diff1[0] == diff2[1] && diff1[1] == diff2[0])
        return true;
    else if(count == 0)
        return true;
    return false;
}

int main()
{
    std::cout << areAlmostEqual("aa", "bb") << std::endl;
    std::cout << areAlmostEqual("abcd", "abcd") << std::endl;
    std::cout << areAlmostEqual("acbd", "adbc") << std::endl;
    return 0;
}
