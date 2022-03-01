/**
 * @author ling
 * @date 2021/3/1
 * @brief medium Z字形变化
 *
 * 1. 模拟
 * 简洁明了，模拟就完事了。
 * 时间复杂度：O(N)       空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <string>

std::string convert(std::string s, int numRows)
{
    std::vector<std::string> strVct(numRows, "");
    bool isVertical = true;
    int count = 0;
    for(auto ch : s)
    {
        if(isVertical)
            strVct[count++].push_back(ch);
        else
            strVct[--count].push_back(ch);

        if(count == numRows)
        {
            isVertical = false;
            --count;
        }
        if(count == 0)
        {
            isVertical = true;
            ++count;
        }
    }    
    std::string ans;
    for(auto str : strVct)
        ans += str;
    return ans;
}

int main()
{
    std::cout << convert("ab", 1) << std::endl;
    return 0;
}