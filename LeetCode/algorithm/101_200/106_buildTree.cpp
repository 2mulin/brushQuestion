/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/31
 * @brief medium 从中序遍历和后序遍历推出先序遍历
 * 
 * 思路很简答，每次先确定root，然后左右子树递归。
 * 时间复杂度：O(N)     空间复杂度：O(N)
 * 
 * 官方题解，使用哈希表优化了，很厉害。在线模仿
 * 时间复杂度：O(N)     空间复杂度：O(N)
 ******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 优化关键，利用哈希表快速查找root
unordered_map<int, int> index;

// 优化版本
TreeNode *myBuildTree(const vector<int> &inorder, const vector<int> &postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
{
    if (postorder_left > postorder_right)
        return nullptr;

    // 后序遍历中的最后一个节点就是根节点
    int postorder_root = postorder_right;
    // 在中序遍历中定位根节点
    int inorder_root = index[postorder[postorder_root]];

    // 先把根节点建立出来
    TreeNode *root = new TreeNode(postorder[postorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    root->left = myBuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + size_left_subtree - 1);
    // 递归地构造右子树，并连接到根节点
    root->right = myBuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + size_left_subtree, postorder_right - 1);
    return root;
}

TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int n = postorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i)
    {
        index[inorder[i]] = i;
    }
    return myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
}

// 思路
/* 
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.empty() || postorder.empty())
        return NULL;

    // 根
    int rootVal = postorder.back();
    TreeNode *root = new TreeNode(rootVal);
    // 左子树的中序和后序
    vector<int> leftTreeIn, leftTreePost;
    int i = 0;
    for (i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == rootVal)
            break;
        leftTreeIn.push_back(inorder[i]);
        leftTreePost.push_back(postorder[i]);
    }
    if (!leftTreeIn.empty() && !leftTreePost.empty())
        root->left = buildTree(leftTreeIn, leftTreePost);
    // 右子树的中序和后序
    vector<int> rightTreeIn, rightTreePost;
    for (i; i < postorder.size() - 1; i++)
    {
        rightTreeIn.push_back(inorder[i + 1]);
        rightTreePost.push_back(postorder[i]);
    }
    if (!rightTreeIn.empty() && !rightTreePost.empty())
        root->right = buildTree(rightTreeIn, rightTreePost);
    return root;
}
 */
int main()
{
    return 0;
}