/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/8
 * @brief easy 路径总和
 * 
 * 1.递归
 * 时间复杂度: O(N)           空间复杂度: O(N)
 * 
 * 2.广度优先搜索
 * 两个队列，一个treeNode，一个val保存当前路径和
 * 时间复杂度: O(N)         空间复杂度: O(N)
*******************************************************************************************/
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return false;
    sum -= root->val;
    if (root->left == NULL && root->right == NULL && sum == 0)
        return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main()
{
    return 0;
}