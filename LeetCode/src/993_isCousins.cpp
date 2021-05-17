/*
 * @author ling
 * @date 2021/5/17
 * @brief easy 二叉树的堂兄弟结点
 * 1. 深搜
 * 深度优先遍历去找到x和y的深度和父节点,记录下来, 最后比较
 * 时间复杂度： O(N)        空间复杂度：O(N)
 * 
 * 2. 广搜
 * 每一层比较一次,只看父节点是否相同
 * 时间复杂度： O(N)        空间复杂度：O(N)
 */

#include <iostream>
#include <queue>
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

// 广搜
bool isCousins(TreeNode *root, int x, int y)
{
    queue<TreeNode *> qu;
    if (root == nullptr)
        return false;
    qu.push(root);
    while (!qu.empty())
    { // 层次遍历
        int size = qu.size();
        TreeNode *parentX = nullptr, *parentY = nullptr;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = qu.front();
            qu.pop();
            if (node->left)
            {
                int val = node->left->val;
                if (val == x)
                    parentX = node;
                if (val == y)
                    parentY = node;
                qu.push(node->left);
            }
            if (node->right)
            {
                int val = node->right->val;
                if (val == x)
                    parentX = node;
                if (val == y)
                    parentY = node;
                qu.push(node->right);
            }
        }
        if (parentX == nullptr && parentY == nullptr)
            continue;
        if (parentX && parentY && parentX != parentY)
            return true;
        else
            return false;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    isCousins(root, 4, 5);
    return 0;
}