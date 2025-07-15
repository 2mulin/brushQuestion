/**
 * @date 2025/7/15
 * @author 2mu
 * @brief easy 有效单词
 *
 * 1. 一次遍历
 * 按照条件检查即可，没啥说的。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isValid(string word)
{
    if (word.length() < 3)
        return false;
    bool hasVowel = false;
    bool hasConsonant = false;
    for (char ch : word)
    {
        if (ch >= '0' && ch <= '9')
        {
            continue;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            switch (ch)
            {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                hasVowel = true;
                break;
            default:
                hasConsonant = true;
                break;
            }
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            switch (ch)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                hasVowel = true;
                break;
            default:
                hasConsonant = true;
                break;
            }
        }
        else
        {
            return false;
        }
    }
    if (hasVowel && hasConsonant)
        return true;
    return false;
}

int main()
{
    std::string word = "234Adas";
    std::cout << isValid(word) << std::endl;
    return 0;
}
