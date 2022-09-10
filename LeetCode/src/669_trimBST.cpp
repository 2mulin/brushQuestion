/**
 * @date 2022/9/10
 * @author 2mu 修剪二叉树
 * @brief 
 *
 * 一. 递归
 * 分治的思想，简化这题。对每个节点判断它是不是超过了[low, high]。
 * 注意这里题目给的**BST**，所以：
 *      1. 如果当前节点的值小于low，那么整个节点及其左子树都可以丢弃了。
 *      2. 如果当前节点的值大于high，整个节点及其右子树都可以丢弃了。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 
 * 二. 普通做法
 * 第一次做没注意到是BST，直接每个节点都判断了一次，也可以通过。只要注意指针的操作。
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) 
{
    if(!root)
        return root;
    if(root->val < low)
        return trimBST(root->right, low, high);
    if(root->val > high)
        return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main()
{
    return 0;
}
