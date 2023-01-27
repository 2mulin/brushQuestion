/**
 * @date 2022/1/27
 * @author 2mu
 * @brief easy 兼具大小写字母的最好字符串
 *
 * 一、哈希表
 * 使用哈希表，记录26个字母是否出现过，大小写分别记录。最后反序遍历一遍哈希表，
 * 就可以确定同时出现过的大小写字母。
 * 
 * 优化空间：哈希表比较浪费空间，可以使用位运算，2个32位整数足以表示。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string greatestLetter(string s)
{
    string ans = "";
    std::vector<bool> hashLower(26, false);
    std::vector<bool> hashUpper(26, false);
    for(auto ch : s)
    {
        if(ch >= 'a' && ch <= 'z')
            hashLower[ch - 'a'] = true;
        if(ch >= 'A' && ch <= 'Z')
            hashUpper[ch - 'A'] = true;
    }
    for(int i = 25; i >= 0; --i)
    {
        if(hashLower[i] && hashUpper[i])
        {
            ans.push_back(char('A' + i));
            break;
        }
    }
    return ans;
}

int main()
{
    std::cout << greatestLetter("lEeTcOdE") << std::endl;
    std::cout << greatestLetter("arRAzFif") << std::endl;
    std::cout << greatestLetter("AbCdEfGhIjK") << std::endl;
    return 0;
}
