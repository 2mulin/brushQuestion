/**
 * @date 2022/6/24
 * @author 2mu
 * @brief medium 树中每一行节点最大值
 *
 * 1. 层次遍历
 * 要求找出每一层的节点最大值，这就很简单，明摆的层次遍历bfs
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 *
 * 2. dfs
 * 题解还想到了dfs，我是压根没去想。先序遍历树，遍历时记录当前节点高度。
 * 利用一个数组记录对应高度的最大值，遍历边更新就完事了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(height)
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> largestValues(TreeNode *root)
{
    std::vector<int> result;
    if(!root)
        return result;
    std::vector<TreeNode*> que;
    que.push_back(root);
    while(!que.empty())
    {
        std::vector<TreeNode*> tmp(que.begin(), que.end());
        que.clear();
        int maxVal = INT_MIN;
        for(auto node : tmp)
        {
            if(node->val > maxVal)
                maxVal = node->val;
            if(node->left)
                que.push_back(node->left);
            if(node->right)
                que.push_back(node->right);
        }
        result.push_back(maxVal);
    }

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    auto result = largestValues(root);
    for(auto val : result)
    {
        std::cout << val << std::endl;
    }
    return 0;
}
