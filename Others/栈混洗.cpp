/******************************************************
 * @author reddragon
 * @date 2020/7/15
 * @description:
 * 给一个入栈顺序，求所有正确的出栈顺序，并输出
 * 这就是一个栈混洗
 * 
 * 只要记得栈混洗只允许两种操作
 * 1. 元素入中转栈
 * 2. 不入栈，中转栈栈顶元素出站
 * 
 * 知道上面两个规则后，就是一个dfs了
*******************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<string> ans;
string str;

// 栈混洗
void foo(string s, stack<char> temp, int index)
{
    if (index == str.length())
    {
        while (!temp.empty())
        {
            s.push_back(temp.top());
            temp.pop();
        }
        ans.push_back(s);
        return;
    }
    //栈混洗只允许两种操作
    //1. 元素入中转栈
    temp.push(str[index]);
    foo(s, temp, index + 1);
    temp.pop();
    //2. 不入栈，中转栈元素直接出站
    if (temp.empty())
        return;
    s += temp.top();
    temp.pop();
    foo(s, temp, index);
    return;
}

int main()
{
    cin >> str;
    string s;
    stack<char> temp;
    foo(s, temp, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}