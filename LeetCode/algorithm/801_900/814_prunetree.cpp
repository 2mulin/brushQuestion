/**
 * @date 2022/7/20
 * @author 2mu
 * @brief medium 二叉树剪枝
 *
 * 1. 找找思路
 * 首先这是一棵树，然后要求减去没有节点值为1的子树。那就要找到节点为1的子树。
 * 那么树遍历有4种方式，先序遍历，中序遍历，后续遍历，和bfs。
 * 
 * 使用前3种遍历应该都行，递归版。我这里用后序遍历。如果当前节点包含1，或者其左右子树包含1，返回节点本身。否则返回nullptr。
 *
 * 时间复杂度：O(M)
 * 空间复杂度：O(1)
 * 
 * 2. 优化空间占用
 * 递归版本还是会占用一些空间，使用非递归版本肯定能降低空间占用。但是不太好写，现在题解也没有非递归版本。
 */

#include <iostream>
#include <algorithm>
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

TreeNode *pruneTree(TreeNode *root)
{
    if(!root)
        return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->left || root->right)
        return root;
    else if(root->val == 1)
        return root;
    else
        return nullptr;
}

int main()
{
    return 0;
}
