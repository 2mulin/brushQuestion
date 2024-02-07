/**
 * @date 2024/2/7
 * @author 2mu
 * @brief medium 二叉树的堂兄弟节点
 * 
 * 1. 层次遍历
 * 
 * 首先明确只是一个二叉树, 所以只有左右孩子;
 * 也就是每一层的总和, 再减去当前左右孩子的和, 就是堂兄弟的和; 赋值即可;
 * 
 * 用了半小时, 思路写法和官方基本一致
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
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

TreeNode *replaceValueInTree(TreeNode *root)
{
    // 一层的总和
    int next_level_sum = 0, level_node_count = 1;
    std:queue<TreeNode*> que;
    std::vector<TreeNode*> level_node;
    
    if(root)
    {
        root->val = 0;
        que.push(root);
    }
    while(!que.empty())
    {
        TreeNode* node = que.front();
        level_node.push_back(node);
        que.pop();
        if(node->left)
        {
            next_level_sum += node->left->val;
            que.push(node->left);
        }
        if(node->right)
        {
            next_level_sum += node->right->val;
            que.push(node->right);
        }
        --level_node_count;
        if(level_node_count == 0)
        {
            for(TreeNode* parent : level_node)
            {
                int sum = 0;
                if(parent->left)
                    sum += parent->left->val;
                if(parent->right)
                    sum += parent->right->val;
                // 堂兄弟节点的和 = 层级所有节点和 - 兄弟节点总和
                int val = next_level_sum - sum;
                if(parent->left)
                    parent->left->val = val;
                if(parent->right)
                    parent->right->val = val;
            }
            level_node.clear();
            level_node_count = que.size();
            next_level_sum = 0;
        }
    }
    return root;
}

int main()
{
    return 0;
}
