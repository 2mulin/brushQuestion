/**
 * @date 2024/8/4
 * @author 2mu
 * @brief easy 另一颗树的子树
 *
 * 1. 遍历(递归)
 * root的每颗子树都和subRoot进行一次比较, 确认两者是否相同; 也就是将是否是子树的问题转化为是否相等的问题;
 * 
 * 官方题解思路更加清晰, 直接在遍历root的同时就计算两颗子树是否相同, 不需要先遍历一次将节点都取出来;
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *node1, TreeNode *node2)
{
    // node1和node2一定不为空
    if (node1->val == node2->val)
    {
        bool same_left = false, same_right = false;
        if (node1->left && node2->left)
            same_left = isSameTree(node1->left, node2->left);
        else if (node1->left == node2->left && node1->left == NULL)
            same_left = true;

        if (node1->right && node2->right)
            same_right = isSameTree(node1->right, node2->right);
        else if (node1->right == node2->right && node1->right == NULL)
            same_right = true;
        return same_left && same_right;
    }
    // val不同, 直接返回false
    return false;
}

void preorder(TreeNode *root, std::vector<TreeNode *> &result)
{
    if (root)
    {
        result.push_back(root);
        if (root->left)
            preorder(root->left, result);
        if (root->right)
            preorder(root->right, result);
    }
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    std::vector<TreeNode *> nodes;
    preorder(root, nodes);
    for (TreeNode *node : nodes)
    {
        if (isSameTree(node, subRoot))
            return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    return 0;
}

