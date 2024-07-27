/**
 * @date 2023/1/20
 * @author 2mu
 * @brief easy 按分隔符拆分字符串
 *
 * 1. 模拟
 * 直接模拟, 遍历一遍即可, 遍历每个字符串判断字符是否是分隔符, 是的话就按照规则分割;
 * 
 * 时间复杂度: O(n * m)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitWordsBySeparator(vector<string> &words, char separator)
{
    std::vector<std::string> result;
    for(std::string word : words)
    {
        std::string tmp;
        for(auto ch : word)
        {
            if(ch == separator)
            {
                if(!tmp.empty())
                {
                    result.push_back(tmp);
                    tmp.clear();
                }
            }
            else
            {
                tmp.push_back(ch);
            }
        }
        if(!tmp.empty())
            result.push_back(tmp);
    }
    return result;
}

int main()
{
    std::vector<std::string> words{"one.two.three","four.five","six"};
    std::vector<std::string> result = splitWordsBySeparator(words, '.');
    for(auto word : result)
    {
        std::cout << word << std::endl;
    }
    return 0;
}