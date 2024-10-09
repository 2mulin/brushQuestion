/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/8
 * @brief easy 树的最小深度
 * 
 * 1. 深度优先搜索
 * 对于每一个非叶子节点，我们只需要分别计算其左右子树的最小叶子节点深度。
 * 这样就将一个大问题转化为了小问题，可以递归地解决该问题。
 * 时间复杂度: O(N)           空间复杂度: O(N)
 * 
 * 2. 广度优先搜索
 * 当我们找到 ***第一个叶子*** 节点时，直接返回这个叶子节点的深度。
 * 广度优先搜索的性质保证了最先搜索到的叶子节点的深度一定最小。
 * 时间复杂度: O(N)             空间复杂度: O(N)
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

// 广度优先搜索
int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int depth = 1;
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        int size = qu.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *p = qu.front();
            qu.pop();
            if (p->left == nullptr && p->right == nullptr)
                return depth;
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
        depth++;
    }
    return depth;
}

/* 深度优先搜索
int Depth(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    // 注意左右子树都为null，才是叶子节点
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 1 + min(Depth(root->left), Depth(root->right));
}

int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return Depth(root);
} */

int main()
{
    return 0;
}