/**
 * @date 2022/8/11
 * @author 2mu
 * @brief easy 重新格式化字符串
 *
 * 一. 模拟
 * 首先第一个想到的就是，如果能够满足条件，必然字符串中 数字数量 和 字母数量 的差值的绝对值 小于2
 * 否则无法格式化。
 * 
 * 然后分别将数字，字符抽取出来，组合成满足条件的字符串。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 二. 双指针
 * 还是分别计算出罗马数字，英文字母的数量，一次判断是否可以组成满足条件的字符串。
 * 
 * 然后使用双指针构建满足条件的字符串。最大的优点就是节省空间。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(1) （不计算结果字符串的构建的话）
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string reformat(string s)
{
    std::string numStr, str;
    for(auto ch : s)
    {
        if(ch >= 'a' && ch <= 'z')
            str.push_back(ch);
        else
            numStr.push_back(ch);
    }

    int diff = str.length() - numStr.length(); 
    if(abs(diff) > 1)
        return "";

    std::string result;
    if(str.length() > numStr.length())
    {
        for(size_t i = 0; i < numStr.length(); ++i)
        {
            result.push_back(str[i]);
            result.push_back(numStr[i]);
        }
        result.push_back(str.back());
    }
    else
    {
        for(size_t i = 0; i < str.length(); ++i)
        {
            result.push_back(numStr[i]);
            result.push_back(str[i]);
        }
        if(str.length() < numStr.length())
            result.push_back(numStr.back());
    }
    return result;
}

int main()
{
    string s = "ab123";
    std::cout << reformat(s) << std::endl;
    return 0;
}
