/**
 * @author ling
 * @date 2022/3/19
 * @brief  根据二叉树构建字符串
 *
 * 1.递归
 * 前序遍历，难点在于加括号的4种情况。
 * 时间复杂度：O(N)  空间复杂度：O(N)
 *
 * 2.迭代
 * 有递归就有迭代版本，只要用栈模拟就行了。
 */

#include <iostream>
#include <string>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int v):val(v),left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode* l, TreeNode* r):val(v),left(l),right(r){}
};

std::string dfs(TreeNode* root)
{
    if(!root)
        return "()";
    if(root->left && root->right)
        return std::to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    else if(!root->left && root->right)
        return std::to_string(root->val) + "()(" + dfs(root->right) + ")";
    else if(root->left && !root->right)
        return std::to_string(root->val) + "(" + dfs(root->left)  + ")";
    return std::to_string(root->val);

}

std::string tree2str(TreeNode* tree)
{
    if(!tree)
        return "";
    std::string str = dfs(tree);
    return str;
}

int main()
{
    return 0;
}
