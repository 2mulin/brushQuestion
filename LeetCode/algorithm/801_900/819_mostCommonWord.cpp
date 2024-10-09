/**
 * @author ling
 * @date 2021/4/17
 * @brief easy 最常见的单词
 *
 * 1. 哈希表 + 计数
 * 使用一个map记录str出现的次数, 最后找出出现次数最多, 而且不在banned中出现的str.
 * 时间复杂度: O(N)         空间复杂度: O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

std::string mostCommonWord(std::string paragraph, std::vector<std::string> &banned)
{
    std::map<std::string , int> maWord2Count;
    std::string word;
    for(char ch : paragraph)
    {
        if(ch == ' ' || ch == ',' || ch == '.'
            || ch == '!' || ch == '?' || ch == ';'
            || ch == '\'')
        {
            if(word.empty())
                continue;
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            maWord2Count[word] += 1;
            word.clear();
        }
        else
            word.push_back(ch);
    }
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    std::set<std::string> setBanned(banned.begin(), banned.end());
    int count = 0;
    for(auto iter = maWord2Count.begin(); iter != maWord2Count.end(); ++iter)
    {
        if(iter->second > count && setBanned.find(iter->first) == setBanned.end())
        {
            word = iter->first;
            count = iter->second;
        }
    }
    return word;
}

int main()
{
    std::string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::vector<std::string> arr{"hit"};
    std::cout << mostCommonWord(str, arr) << std::endl;
    return 0;
}