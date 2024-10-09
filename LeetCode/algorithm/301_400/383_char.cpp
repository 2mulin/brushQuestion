/**
 * @date 2023/1/7
 * @author 2mu
 * @brief easy 赎金信
 *
 * 1. 字符统计
 * 
 * 字符串只由小写字母组成, 所以这里直接使用数组分别统计 两个字符串中各个字母出现的次数;
 * 然后比较字母数量即可;
 * 
 * 时间复杂度: O(m + n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    std::vector<int> bucket(26, 0);
    for(char ch : ransomNote)
    {
        --bucket[ch - 'a'];
    }
    for(char ch : magazine)
    {
        ++bucket[ch - 'a'];
    }
    for(int count : bucket)
    {
        if(count < 0)
            return false;
    }
    return true;
}

int main()
{
    std::cout << canConstruct("aa", "aab") << std::endl;
    std::cout << canConstruct("aa", "a") << std::endl;
    std::cout << canConstruct("aa", "abccd") << std::endl;
    return 0;
}