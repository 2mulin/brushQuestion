/**
 * @author ling
 * @date 2021/10/7
 * @brief easy 字符串中的单词个数
 * 
 * 1.统计单词个数
 * 遍历一次，统计单词个数。
 * 时间复杂度: O(N)      空间复杂度: O(N)
 */

#include <iostream>
#include <string>
using namespace std;

int countSegments(string s) 
{
    int count = 0;
    string word = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
            word += s[i];
        else
        {
            if (!word.empty())
                ++count;
            word = "";
        }
    }
    if (!word.empty())
        ++count;
    return count;
}

int main()
{
    return 0;
}