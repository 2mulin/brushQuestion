/**
 * @date 2024/2/14
 * @author 2mu
 * @brief medium 二叉树的层次遍历
 * 
 * 1. 利用队列
 * 利用队列进行层次遍历; 额外使用一个变量记录每层的节点数量; 就可以完成分层;
 * 
 * 时间复杂度:O(N)
 * 空间复杂度:O(N)
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    std::vector<vector<int>> ans;
    std::queue<TreeNode*> que;
    if(root)
        que.push(root);

    std::vector<int> level;// 一层节点
    int level_node_count = 1;
    while(!que.empty())
    {
        TreeNode* node = que.front();
        que.pop();
        level.push_back(node->val);
        --level_node_count;

        if(node->left)
            que.push(node->left);
        if(node->right)
            que.push(node->right);
        if(level_node_count == 0)
        {
            level_node_count = que.size();
            ans.push_back(level);
            level.clear();
        }
    }
    return ans;
}


int main()
{
    return 0;
}