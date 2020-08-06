/**********************************************
 * @author reddragon
 * @date 2020/7/28
 * @brief midden 简化路径
 * 主要是利用栈的思想，就是运算符重载的思想，
 * 来一个处理一个
 **********************************************/
#include <iostream>
#include <string>
using namespace std;

string simplifyPath(string path)
{
    string ans;
    path.push_back('/');
    int len = 0; // 记录两个/之间的距离
    for (int i = 0; i < path.size(); i++)
    {
        if (ans.empty())
            ans.push_back(path[i]);
        else if (path[i] != '/')
        {
            ans.push_back(path[i]);
            len++;
        }
        else
        {
            if (len == 2 && ans.back() == '.' && ans[ans.length() - 2])
            {
                // delete ".."
                while (!ans.empty() && ans.back() != '/')
                    ans.pop_back();
                if (ans.length() != 1)
                    ans.pop_back(); //delete '/'
                while (!ans.empty() && ans.back() != '/')
                    ans.pop_back();
                len = 0;
            }
            else if (len == 1 && ans.back() == '.')
            {
                // delete "."
                ans.pop_back();
                len = 0;
            }
            else if (len == 0 && ans.back() == '/')
                continue; // ignore "//"
            else
            {
                len = 0;
                ans.push_back(path[i]);
            }
        }
    }
    if (ans.length() >= 2 && ans.back() == '/')
        ans.pop_back();
    return ans;
}

int main()
{
    cout << simplifyPath("/../");
    return 0;
}