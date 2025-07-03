/**
 * @date 2025/7/1
 * @author 2mu 
 * @brief easy 找到初始输入字符串I
 *
 * 1. 模拟
 * 至多犯错误一次，也就是最多只会导致1种类型的字母多打。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <string>

using namespace std;

int possibleStringCount(string word)
{
    int count = 1;
    for (int i = 1; i < word.length(); ++i)
    {
        if (word[i] == word[i - 1])
        {
            int charCount = 2;
            char ch = word[i];
            while(word[i+1] == ch)
            {
                ++i;
                ++charCount;
            }
            count = count + charCount - 1;
        }
    }
    return count;
}

int main()
{
    std::string word = "abbcccc";
    std::cout << possibleStringCount(word) << std::endl;
    return 0;
}
