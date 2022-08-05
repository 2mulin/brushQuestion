/**
 * @date 2022/8/5
 * @author 2mu
 * @brief medium 在二叉树中插入一行
 *
 * 1. 按部就班
 * 直接按照规则，先层次遍历到指定depth，然后插入一层。
 * 
 * 注意特殊情况，需要特殊处理。也是depth = 1时，需要换一个root。还有depth=maxDepth时。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
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

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    int currDepth = 1;
    std::queue<TreeNode*> que;
    que.push(root);

    if (depth != 1)
    {
        // 作为新的root，有点区别
        TreeNode* newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }

    while (!que.empty())
    {
        if (currDepth + 1 == depth)
            break;
        int sz = que.size(); // 这一层有多少节点
        for (size_t i = 0; i < sz; ++i)
        {
            TreeNode *currNode = que.front();
            que.pop();
            if (currNode->left)
                que.push(currNode->left);
            if (currNode->right)
                que.push(currNode->right);
        }
        ++currDepth;
    }

    while(!que.empty())
    {
        TreeNode* currNode = que.front();
        que.pop();
        TreeNode* node = new TreeNode(val);
        if(currNode->left)
        {
            node->left = currNode->left;
            currNode->left = node;
        }
        else
            currNode->left = node;
        
        node = new TreeNode(val);
        if(currNode->right)
        {
            node->right = currNode->right;
            currNode->right = node;
        }
        else
            currNode->right = node;
    }
    return root;
}

int main()
{
    TreeNode root(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    addOneRow(&root, 5, 4);
    return 0;
}
