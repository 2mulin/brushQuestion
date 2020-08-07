/**************************************************************
 * @date 2020/6/15
 * @author reddragon
 * @description: easy题
 *************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    if (strs.empty())
        return ans;
    int i = 0;
    while (i < strs[0].length())
    {
        char ch = strs[0][i];
        bool falg = true;
        for (size_t j = 1; j < strs.size(); j++)
        {
            if (strs[j].length() <= i || ch != strs[j][i])
            {
                falg = false;
                break;
            }
        }
        if (falg)
            ans += ch;
        else
            break;
        i++;
    }
    return ans;
}

int main()
{
    return 0;
}