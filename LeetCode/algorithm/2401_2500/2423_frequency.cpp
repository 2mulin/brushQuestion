/**
 * @date 2023/4/29
 * @author 2mu
 * @brief easy 删除字符使频率相同 
 *
 * 1. 哈希表
 * 删除字符串中任意一个字符后, 剩余字符出现频率相等; 虽然简单, 但是条件非常复杂, 有太多的情况可以满足题目条件;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. 枚举
 * 
 * 思路最简单,最清晰的方法; 枚举: 按顺序删除字符串中一个字符, 然后看能不能剩余的字符, 出现频率是否全部相同;
 * 
 * 时间复杂度: O(n*n)       由于字符串长度 < 100, 最大是 O(100 * n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isValid(std::string word)
{
    int arrCharFrequency[26] = {0};
    for(char ch : word)
    {
        ++arrCharFrequency[ch - 'a'];
    }
    int frequency = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(arrCharFrequency[i] == 0)
            continue;
        if(frequency == 0)
        {
            frequency = arrCharFrequency[i];
        }
        else if(frequency != arrCharFrequency[i])
        {
            return false;
        }
    }
    return true;
}

bool equalFrequency(string word)
{
    for(int i = 0; i < word.size(); ++i)
    {
        std::string str = word.substr(0, i) + word.substr(i+1);
        if(isValid(str))
            return true;
    }
    return false;
}

/*
bool equalFrequency(string word)
{
    // 统计字母出现频率
    int arrCharFrequency[26] = {0};
    for(char ch : word)
    {
        ++arrCharFrequency[ch - 'a'];
    }
    // 统计 频率 的出现频率
    std::unordered_map<int, int> ma;
    for(int i = 0; i < 26; ++i)
    {
        int key = arrCharFrequency[i];
        if(key == 0)
            continue;
        ++ma[key];
    }
    if(word.length() >= 1 && ma.size() == 1)
    {
        // 这种情况也满足, 每个字符都只出现过一次; 随意删除一个即可
        if(ma.begin()->first == 1)
            return true;
        if(ma.begin()->first != 1 && ma.begin()->second == 1)
            return true;
    }

    // 最后判断
    if(ma.size() != 2)
        return false;
    auto iter = ma.begin();
    std::pair<int, int> value1 = *iter++;
    std::pair<int, int> value2 = *iter;
    if(value1.first == 1 && value1.second == 1)
        return true;
    if(value2.first == 1 && value2.second == 1)
        return true;
    
    if(value1.first - value2.first == 1 && value1.second == 1)
        return true;
    if(value2.first - value1.first == 1 && value2.second == 1)
        return true;
    
    return false;
}*/

int main()
{
    std::cout << equalFrequency("abcc") << std::endl;
    std::cout << equalFrequency("bacc") << std::endl;
    std::cout << equalFrequency("abc") << std::endl;
    std::cout << equalFrequency("abbcc") << std::endl;
    std::cout << equalFrequency("zz") << std::endl;
    return 0;
}