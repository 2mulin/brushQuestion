/**
 * @date 2022/11/13
 * @author 2mu
 * @brief medium 自定义字符串排序
 * 
 * 一. 计数排序
 * 先统计order中出现了哪些字母，并且让记录其相对顺序。
 * 然后统计s中的字母出现次数。然后按照order中的顺序重新排列s
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string customSortString(string order, string s)
{
    std::vector<int> count(26, 0);
    for(auto &ch : s)
    {
        ++count[ch - 'a'];
    }

    std::string ans;
    for(auto &ch : order)
    {
        int num = count[ch - 'a'];
        if(num == 0)
            continue;
        ans += std::string(num, ch);
        count[ch - 'a'] = 0;
    }

    for(int i = 0; i < 26; ++i)
    {
        if(count[i] != 0)
            ans += std::string(count[i], 'a' + i);
    }
    return ans;
}

int main()
{
    std::cout << customSortString("cba", "abcd") << std::endl;
    return 0;
}
