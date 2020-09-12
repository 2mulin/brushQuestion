/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/12
 * @brief medium 二叉树转化为单链表
 * 我个人觉得很难，明天继续这一题
 * 
 * 
 * 1. 先序遍历+重新构造树
 * 由题意可以看出是一个按先序遍历构成的右侧链。所以得出最简单的解法
 * 时间复杂度: O(N)     空间复杂度: O(N)
 * 
 * 2. 
*******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 先序遍历（非递归版）
vector<int> preTrav(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    if (root)
        s.push(root);
    while (!s.empty())
    {
        TreeNode *p = s.top();
        s.pop();
        while (p)
        {
            // root
            ans.push_back(p->val);
            // right
            if (p->right)
                s.push(p->right);
            // left
            p = p->left;
        }
    }
    return ans;
}

void flatten(TreeNode *root)
{
    // 划重点，展开成为一个“单链表”
    // 应该是先序遍历的顺序,只有right
    if (root == nullptr)
        return;
    vector<int> TreeVal = preTrav(root);
    root->val = TreeVal[0];
    for (size_t i = 1; i < TreeVal.size(); i++)
    {
        if (root->left)
            root->left = nullptr;
        root->right = new TreeNode(TreeVal[i]);
        root = root->right;
    }
    return;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    vector<int> arr = preTrav(root);
    for (auto i : arr)
        cout << i << '\t';
    cout << endl;
    return 0;
}