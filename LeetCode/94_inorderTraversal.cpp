/*******************************************************************************
 * @author reddragon
 * @date 2020/8/14
 * @brief medium 二叉树的中序遍历
 * 做过很多次了，希望下一次能更快写出来
 * 1. 递归版本：不用说
 * 2. 迭代版本：还是那个思路，一直沿着左侧链走就是了，左节点入stack，
 * 最后没有左子树的时候，判断一下有没有右子树，有就转到右子树执行上一个操作
 * 3. 线索化：构造成一颗线索二叉树。会改变原本的结构
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p || !s.empty())
    {
        // 沿左侧链下降
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        // 延左侧链回去
        p = s.top();
        s.pop();
        ans.push_back(p->val); // 当前结点的val
        p = p->right;// 转向右子树，空也没关系
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);
    for(auto i : ans)
        cout << i << endl;
    return 0;
}