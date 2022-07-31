/**
 * @date 2022/7/31
 * @author 2mu
 * @brief medium 最大层内元素和
 *
 * 1. 层次遍历
 *
 * 求二叉树每一层的节点值的和，然后计算出最大值。并且记录是第几层。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

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

int maxLevelSum(TreeNode *root)
{
    if(!root)
        return 0;
    std::queue<TreeNode*> que;
    que.push(root);
    int maxSum = INT_MIN;
    int levelNo = 1;
    int result = 0;
    while(!que.empty())
    {
        int sum = 0;
        size_t sz = que.size();
        for(size_t i = 0; i < sz; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);

            sum += node->val;
        }
        if(maxSum < sum)
        {
            maxSum = sum;
            result = levelNo;
        }
        ++levelNo;
    }
    return result;
}

int main()
{
    TreeNode root(1, new TreeNode(7, new TreeNode(7), new TreeNode(-8)), new TreeNode(0));
    std::cout << maxLevelSum(&root) << std::endl;
    return 0;
}
