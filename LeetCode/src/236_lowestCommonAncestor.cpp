/********************************************************************************************
 * @author reddragon
 * @date 2021/2/3
 * @brief medium 最近公共祖先
 * 
 * 1.将路径暂存
 * 题目保证相同的结点不会出现两次，所以我们利用一个数组存储root到指定p、q的路径
 * 最终判断两条路径的最后一个相同点，那就是最近公共祖先。
 * 时间复杂度：O(n)		空间复杂度：O(n)
 * 
 * 官方题解的想法是利用map存下父节点和子节点的关系，这样就可以通过子节点找到父节点了
 * 
 * 2.递归
 * 如果x的左右子树，包含p、q结点，那么x可能是我们要找的，以此为条件递归
 * 
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <dataStruct.h>
using namespace std;

bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
{
    if (root == nullptr)
        return false;
    path.push_back(root);
    if (root == node)
        return true;
    if (findPath(root->left, node, path))
        return true;
    else
    {
        while (path.back() != root)
            path.pop_back(); // 回溯
        if (findPath(root->right, node, path))
            return true;
    }
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // 得到root-》p和root-》q的两条路径
    vector<TreeNode *> vecP, vecQ;
    findPath(root, p, vecP);
    findPath(root, q, vecQ);
    int i = 0;
    int len = min(vecP.size(), vecQ.size());
    if (len == 0)
        return nullptr;
    while (i < len && vecP[i] == vecQ[i])
        ++i;
    return vecP[i - 1];
}

int main()
{
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    cout << lowestCommonAncestor(&root, root.right, root.left)->val << endl;
    return 0;
}