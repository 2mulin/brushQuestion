/**
 * @date 2023/2/26
 * @author 2mu
 * @brief easy 二叉搜索树的范围和
 *
 * 1. 中序遍历
 * 对整颗二叉搜索树进行一次中序遍历, 遍历途中判断节点的值, 如果到达末尾, 或者当前节点值已经大于high, 就不需要继续遍历了;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode *root, int low, int high)
{
    if(!root)
        return 0;

    int sum = 0;
    if(root->left)
        sum += rangeSumBST(root->left, low, high);
    if(root->val >= low && root->val <= high)
        sum += root->val;
    if(root->val <= high && root->right)
        sum += rangeSumBST(root->right, low, high);
    return sum;
}

int main()
{

    return 0;
}