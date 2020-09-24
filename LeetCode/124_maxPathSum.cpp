/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/24
 * @brief hard 二叉树的最大路径和
 * 
 * 1. 不说了，没看懂，明天继续
 * 时间复杂度：             空间复杂度：
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxSum = INT_MIN;

int maxGain(TreeNode *node)
{
    if(!node)
        return 0;
    
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    int nodePrice = node->val + leftGain + rightGain;

    maxSum = max(maxSum, nodePrice);

    return node->val + max(leftGain,rightGain);
}

int maxPathSum(TreeNode *root)
{
    maxGain(root);
    return maxSum;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxPathSum(root) << endl;
    return 0;
}