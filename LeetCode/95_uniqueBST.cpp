/*******************************************************************************
 * @author reddragon
 * @date 2020/8/14
 * @brief medium 不同的二叉搜索树
 * 96题的升级版。96只有算出有几个，这里不仅要算有几个，还要把结果也输出
 * 自己没想得出来，看的题解，题解的递归写的真的好，要学着点
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
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

vector<TreeNode*> generateTrees(int low,int high)
{
    if(low >high)
        return {nullptr};
    vector<TreeNode*> allTree;
    // 枚举根节点（i为root，小于i的就只能是leftTree，大于i的就只能是rightTree）
    for(int i = low; i <= high; i++)
    {
        // 递归枚举左子树
        vector<TreeNode*> leftTree = generateTrees(low,i - 1);
        // 递归枚举右子树
        vector<TreeNode*> rightTree = generateTrees(i + 1, high);

        // 从左子树集合中选一颗，从右子树集合中选一颗。拼接到root上
        for(auto left : leftTree)
        {
            for(auto right : rightTree)
            {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                allTree.push_back(root);
            }
        }
    }
    return allTree;
}

vector<TreeNode *> generateTrees(int n)
{
    if(!n)
        return {};
    return generateTrees(1,n);
}

int main()
{
    vector<TreeNode*> ans = generateTrees(3);
    for (auto root : ans)
    {// 层次遍历
        queue<TreeNode *> qu;
        if(root)
            qu.push(root);
        while (!qu.empty())
        {
            TreeNode* p = qu.front();
            qu.pop();
            cout << p->val;
            if(p->left)
                qu.push(p->left);
            if(p->right)
                qu.push(p->right);
        }
        cout << endl;
    }
    return 0;
}