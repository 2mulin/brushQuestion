/**
 * @author ling
 * @date 2022/3/17
 * @brief easy 词典中最长的单词
 *
 * 1.哈希表
 * 注意审题，题目满足条件的字符串必须是删掉最后一个字符的子字符串也在数组中才行。
 * 时间复杂度：O(N)  空间复杂度：O(N)
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::string longestWord(std::vector<std::string> &words)
{
    if (words.empty())
        return "";
    std::sort(words.begin(), words.end(),
              [](const std::string &str1, const std::string &str2)
              {
                  // 这个排序方法很关键
                  return str1.size() != str2.size() ? str1.size() < str2.size()
                                                    : str1 > str2;
              });

    std::unordered_set<std::string> prefixs;
    prefixs.insert("");
    std::string ans;
    for (const auto &word : words)
    {
        if (prefixs.count(word.substr(0, word.length() - 1)))
        {
            prefixs.insert(word);
            ans = word;
        }
    }
    return ans;
}

int main()
{
    std::vector<std::string> arr{"a", "banana", "app", "appl",
                                 "ap", "apply", "apple"};
    std::cout << longestWord(arr) << std::endl;
    return 0;
}
