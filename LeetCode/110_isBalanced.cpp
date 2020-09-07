/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/7
 * @brief easy 判断树是否平衡
 * 
 * 1. 从上往下，每次判断结点的左子树和右子树的高度，是否合法
 * 递归左右子树，继续判断。
 * 时间复杂度: O(N*N)           空间复杂度: O(N)
 * 
 * 2. 从下往上，对于结点直接递归往下走，一旦不平衡返回-1，平衡返回height，看height函数就好了
 * 时间复杂度: O(N)             空间复杂度: O(N)
*******************************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 若不平衡，返回负数，否则返回高度
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int h = 1;
    int left = height(root->left);
    int right = height(root->right);
    if (left == -1 || right == -1 || left - right >= 1 || left - right <= -1)
        return -1; // 不平衡
    h += max(left, right);
    return h;
}

bool isBalanced(TreeNode *root)
{
    return height(root) >= 0;
}

/* 这是从上往下判断，每一次都会走到Tree的底部，以获得height
int getHigh(TreeNode *root)
{
    int h = 1;
    if(root)
        return h + max(getHigh(root->left),getHigh(root->right));
    return h;
}

bool isBalanced(TreeNode* root) {
    if(root == NULL)
        return true;
    int left = getHigh(root->left);
    int right = getHigh(root->right);
    bool isVaild = left - right <= 1 && left - right >= -1;
    return isVaild && isBalanced(root->left) && isBalanced(root->right);
} */
int main()
{
    return 0;
}