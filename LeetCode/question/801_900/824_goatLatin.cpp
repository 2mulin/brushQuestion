/**
 * @author ling
 * @date 2021/4/21
 * @brief easy 山羊拉丁文
 *
 * 1. 模拟
 * 按照山羊拉丁文规则进行转化就可以了。分两步，1.找到一句话中的所有单词。
 * 2.将所有的单词按照规则转化为山羊拉丁文
 * 时间开销就是一句话的字符数量之乘积。
 * 时间复杂度: O(N*N)         空间复杂度: O(N)
 */

#include <iostream>
#include <string>
#include <unordered_set>

std::string wordToGoatLatin(std::string word)
{
    if(word.empty())
        return "";
    std::unordered_set<char> ch_set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    if(ch_set.find(word.front()) != ch_set.end())
        return word + "ma";
    else
        return word.substr(1) + word.front() + "ma";
}

std::string toGoatLatin(std::string sentence)
{
    if(sentence.empty())
        return "";
    
    std::string ans, word;
    int idx = 1;
    for(auto ch : sentence)
    {
        if(ch == ' ')
        {
            ans += wordToGoatLatin(word);
            ans += std::string(idx++, 'a');
            ans.push_back(' ');
            word.clear();
        }
        else
            word.push_back(ch);
    }
    ans += wordToGoatLatin(word);
    ans += std::string(idx, 'a');
    return ans;
}

int main()
{
    std::cout << toGoatLatin("I speak Goat Latin") << std::endl;
    return 0;
}