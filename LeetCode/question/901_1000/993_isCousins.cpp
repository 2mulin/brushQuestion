/**
 * @date 2024/2/8
 * @author 2mu
 * @brief easy 二叉树的堂兄弟节点
 * 
 * 1. 层次遍历
 * 
 * 首先明确只是一个二叉树, 所以只有左右孩子; 题目保证每个结点的val的唯一;
 * 不好处理的是, TreeNode结构没有父节点; 
 * 
 * 使用层次遍历, 使用队列保存下一层的所有结点, 同时使用整形变量记录一层的节点数量;
 * 遍历当前层节点的途中, 顺便判断x,y是否出现过在下一层节点; 同时记录x,y的父亲节点;
 * 
 * 每遍历完一层之后, 判断: 如果出现在同一个父亲的左右孩子, 直接返回false; 否则如果同时出现过, 返回true;
 * 如果只出现了x,y的其中一个, 表示没有x,y不在同一层, 也返回false;
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

bool isCousins(TreeNode *root, int x, int y)
{
    std::queue<TreeNode*> que;
    if(root)
        que.push(root);
    
    int level_node_count = 1;
    TreeNode* x_node_parent = NULL;
    TreeNode* y_node_parent = NULL;
    while(!que.empty())
    {
        TreeNode* node = que.front();
        que.pop();
        --level_node_count;

        if(node->left)
        {
            que.push(node->left);
            if(node->left->val == x)
                x_node_parent = node;
            if(node->left->val == y)
                y_node_parent = node;
        }
        if(node->right)
        {
            que.push(node->right);
            if(node->right->val == x)
                x_node_parent = node;
            if(node->right->val == y)
                y_node_parent = node;
        }

        if(level_node_count == 0)
        {
            if(x_node_parent && y_node_parent)
            {
                if(x_node_parent != y_node_parent)
                    return true;
                else
                    return false;
            }
            else if(x_node_parent || y_node_parent)
            {
                // 只有一个节点在下一层, 另外节点不在同一层, 绝对不可能满足条件, 直接返回false;
                return false;
            }
            
            level_node_count = que.size();
        }
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, NULL, new TreeNode(4));
    root->right = new TreeNode(3, NULL, new TreeNode(5));

    std::cout << isCousins(root, 4, 5) << std::endl;
    return 0;
}
