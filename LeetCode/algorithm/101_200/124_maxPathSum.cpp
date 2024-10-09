/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief hard 二叉树的最大路径和
 * 
 * 前面题目没有看懂，以为可以转成中序遍历再求最大连续数组和，最后发现想错了。
 * 这题目的意思就是路径只要能连起来就是行了
 * 
 * 1. 递归
 * 实现一个简化的函数maxGain(),得到二叉树的一个结点最大贡献值。
 * 具体而言，就是在以该节点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的节点值之和最大。
 * 在找maxGain的过程中就可以实时记录一下路径和的最大值。
 * 
 * 时间复杂度：O(N)             空间复杂度：O(N)
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
    // 递归基
    if(node == nullptr)
        return 0;
    
    // 负数就直接算成0
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    int nodePrice = node->val + leftGain + rightGain;

    // 实时更新maxSum
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