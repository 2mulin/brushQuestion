/**
 * @date 2025/6/22
 * @author 2mu
 * @brief easy 将字符串拆分为若干长度为K的组
 *
 * 1. 模拟
 * 按照提议模拟执行就行，时间复杂度也不高。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<string> divideString(string s, int k, char fill)
{
    std::vector<std::string> result;
    std::string temp;
    for(int i = 0; i < s.length(); ++i)
    {
        temp.push_back(s[i]);
        if (temp.length() == k)
        {
            result.push_back(temp);
            temp.clear();
        }
    }
    if (temp.length() > 0)
    {
        while (temp.length() < k)
        {
            temp.push_back(fill);
        }
        result.push_back(temp);
    }
    return result;
}


int main()
{
    auto result = divideString("abcdefghi1", 3, 'x');
    for(auto elem : result)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
