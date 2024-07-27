/**
 * @date 2023/11/7
 * @author 2mu
 * @brief easy 统计范围内的元音字符串数
 * 
 * 1. 简单模拟
 * 按照要求模拟即可, 没什么难的;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

std::unordered_set<char> vowels = {
    'a', 'e', 'i', 'o', 'u'
};

int vowelStrings(vector<string> &words, int left, int right)
{
    int count = 0;
    for(int i = left; i <= right; ++i)
    {
        char ch1 = words[i].front(), ch2 = words[i].back();
        if(vowels.find(ch1) != vowels.end() && vowels.find(ch2) != vowels.end())
            ++count;
    }
    return count;
}

int main()
{
    std::vector<std::string> words{"are","amy","u"};
    std::cout << vowelStrings(words, 0, 2) << std::endl;
    return 0;
}
