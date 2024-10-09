/**
 * @date 2022/6/21
 * @author 2mu
 * @brief easy IP地址无效化
 *
 * 1. 字符替换
 * 按照规则替换字符就行了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 *
 */

#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address)
{
    string ans;
    for(auto ch : address)
    {
        if(ch == '.')
        {
            ans += "[.]";
        }
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    return 0;
}
