#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
迭代版最简洁最短的中序遍历。
看不懂就跟着做一遍
*/
vector<int> travIn(TreeNode *pRoot)
{
    vector<int> vec;
    //OrderTraverse
    stack<TreeNode *> s;
    TreeNode *p = pRoot;
    // 注意p可以是NULL值，没事的，不影响遍历
    while (true)
    {
        // 到达左侧链最下面
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        // 左转
        else if (!s.empty())
        {
            p = s.top();
            s.pop();
            vec.push_back(p->val);
            p = p->right;
        }
        // 退出循环
        else
            break;
    }
    return vec;
}

int main()
{
    return 0;
}