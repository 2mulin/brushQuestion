/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/29
 * @brief easy 求二叉树深度
 * 1. 递归。
 * 很简单，尾递归
 * 时间复杂度:O(N)         空间复杂度:O(1)
 * 
 * 2. BFS
 * BFS时记录下来层次数，就OK了。
 * 时间复杂度:O(N)         空间复杂度:O(1)
 *******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 广度优先搜索
int maxDepth(TreeNode *root)
{
    int ans = 0;
    queue<TreeNode*> qu;
    if(root == nullptr)
        qu.push(root);
    while(!qu.empty())
    {
        ans++;// 层次数++
        size_t len = qu.size();
        for(size_t i = 0; i < len; i++){
            TreeNode* p = qu.front();qu.pop();
            if(p->left)
                qu.push(p->left);
            if(p->right)
                qu.push(p->right);
        }
    }
    return ans;
}

// 递归
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    return 0;
}