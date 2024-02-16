/**
 * @date 2024/2/16
 * @author 2mu
 * @brief medium 二叉树的锯齿形层序遍历
 *
 * 1. 利用队列
 * 利用队列进行层次遍历; 使用一个数组记录每一层的节点, 在额外使用一个变量表示当前层是否需要反转以
 * 达到z字形的效果;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int> > result;
    std::queue<TreeNode*> que;
    if(root)
        que.push(root);
    bool zip = false;
    while(!que.empty())
    {
        // for循环写在里面吧, 逻辑清晰些, 也不会增加时间复杂度
        std::vector<int> values;
        int sz = que.size();
        while(sz--)
        {
            TreeNode* node = que.front();
            que.pop();
            
            values.push_back(node->val);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
        if(zip)
            std::reverse(values.begin(), values.end());
        zip = !zip;
        result.push_back(values);
    }
    return result;
}


int main()
{
    return 0;
}
