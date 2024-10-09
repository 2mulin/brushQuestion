/********************************************************
 * @date 2020/6/14
 * @author reddragon
 * @description: 就是一种方法：暴力。
 * 做一个映射，然后模拟一下，每一个数字来的时候，按情况处理。
 * 我用的循环，没有使用递归。
 *******************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> m(10);
    m[1] = "";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tux";
    m[9] = "wxyz";
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    for (int i = 0; i < m[digits[0] - '0'].length(); i++)
    {
        string temp(1, m[digits[0] - '0'][i]);
        ans.push_back(temp);
    }

    //
    for (int i = 1; i < digits.length(); i++)
    {
        // 原来的ans长度翻倍
        vector<string> temp(ans.size() * m[digits[i] - '0'].length());
        // 先将原有的复制
        int ind = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            for (int k = 0; k < m[digits[i] - '0'].length(); k++)
            {
                temp[ind] = ans[j];
                temp[ind++] += m[digits[i] - '0'][k];
            }
        }
        ans = temp;
    }
    return ans;
}

int main()
{
    string test = "23";
    vector<string> ans = letterCombinations(test);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}
