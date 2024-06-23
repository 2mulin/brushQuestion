/**
 * @date 2024/6/23
 * @author 2mu
 * @brief easy 检测大写字母
 *
 * 1. 遍历
 * 按照规则模拟, 只需要遍历一遍就可以得出答案;
 * 使用一个整数记录大写字母出现次数;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;
    for(int i = 1; i < word.size(); ++i)
    {
        if(word[i] > 'A' && word[i] < 'Z')
            ++count;
    }
    char ch = word.front();
    if(ch > 'A' && ch < 'Z')
    {
        if(count == 0 || count == word.size() - 1)
            return true;
    }
    else
    {
        if(count == 0)
            return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << detectCapitalUse("USA") << std::endl;
    std::cout << detectCapitalUse("leetcode") << std::endl;
    std::cout << detectCapitalUse("Google") << std::endl;
    return 0;
}

