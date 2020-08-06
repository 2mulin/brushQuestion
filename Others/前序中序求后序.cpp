/************************************************
2020/3/4
已知二叉树的前序遍历和中序遍历   求后序遍历
*************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

string getTree(const string &p, const string &s)
{
    // 递归基
    if (p.length() <= 1)
    {
        return p;
    }

    string ans;
    int len = s.find(p[0]); // 通过根的位置，得到左子树的长度
    // 递归处理
    ans += getTree(p.substr(1, len), s.substr(0, len));
    ans += getTree(p.substr(len + 1, p.length() - len - 1), s.substr(len + 1, s.length() - len - 1));
    ans.push_back(p[0]);
    return ans;
}

int main()
{
    string p, s;
    while (cin >> p >> s)
    {
        cout << getTree(p, s) << std::endl;
    }
    return 0;
}