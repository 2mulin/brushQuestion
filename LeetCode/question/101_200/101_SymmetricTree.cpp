/******************************************************************************************************************************
 * @author reddragon
 * @date 2020/8/29
 * @brief easy 相同的树
 * 递归：
 * 对于根节点来说，需要比较左子树和右子树是否相等。
 * 对于左右子树来说，需要比较左子树的左子树和右子树的右子树是否相同
 * 同时需要比较左子树的右子树和右子树的左子树是否相同。
 * 时间O(N)         空间O(N)
 *******************************************************************************************************************************/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMrrir(TreeNode *left, TreeNode *right)
{
    if (left == NULL && right == NULL)
        return true;
    else if (left == NULL || right == NULL)
        return false;
    else
        return left->val == right->val &&
               isMrrir(left->left, right->right) &&
               isMrrir(right->left, left->right);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return isMrrir(root->left, root->right);
}

int main()
{
    return 0;
}