/**
 * @date 2022/8/21
 * @author 2mu
 * @brief easy 检查单词是否为句中其他单词的前缀
 *
 * 一. 暴力
 * 先使用句子的空格分隔，将所有的单词求出来。然后让每一个单词去找前缀单词。
 * 
 * 但这不是最好的方法，使用双指针可以节省空间。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> splitWord(std::string words)
{
    std::vector<std::string> vctWords;
    std::string word;
    for(char s : words)
    {
        if(s == ' ')
        {
            vctWords.push_back(word);
            word.clear();
        }
        else
            word.push_back(s);
    }
    if(!word.empty())
        vctWords.push_back(word);
    return vctWords;
}

int isPrefixOfWord(string sentence, string searchWord)
{
    std::vector<std::string> vctWords = splitWord(sentence);
    for(size_t i = 0; i < vctWords.size(); ++i)
    {
        size_t pos = vctWords[i].find(searchWord);
        if(pos == 0)
            return i + 1;
    }
    return -1;
}

int main()
{
    std::string sentence = "I love eating burger";
    std::cout << isPrefixOfWord(sentence, "burg") << std::endl;
    return 0;
}
