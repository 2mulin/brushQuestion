/**
 * @author ling
 * @date 2021/4/10
 * @brief easy 唯一摩尔斯密码词
 *
 * 1. 模拟
 * 按照摩斯密码对应匹配上就行了。最后加入set中，去重就可以得到个数了。
 * 时间复杂度: O(N)         空间复杂度: O(N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;

std::vector<std::string> morse = {
    ".-","-...","-.-.","-..",".","..-.","--.",  // a-g
    "....","..",".---","-.-",".-..","--","-.",  // h-n
    "---",".--.","--.-",                        // o,p,q
    ".-.","...","-",                            // r,s,t
    "..-","...-",".--"                          // u,v,w
    ,"-..-","-.--","--.."                       // x,y,z
};

std::string getMorseCode(std::string word)
{
    std::string morseCode;
    for(char ch : word)
    {
        morseCode += morse[ch - 'a'];
    }
    return morseCode;
}

int uniqueMorseRepresentations(vector<string> &words)
{
    std::set<std::string> setMorseCode;
    for(auto word : words)
    {
        std::string morseCode = getMorseCode(word);
        setMorseCode.insert(morseCode);
    }
    return setMorseCode.size();
}

int main()
{
    return 0;
}
