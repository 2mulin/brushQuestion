/********************************************************************************************
 * @author reddragon
 * @date 2020/10/29
 * @brief medium 求根到叶子节点数字之和
 * 
 * 1. 深度优先搜索
 * 从根节点开始对每个叶子结点递归，如果是叶子节点，就直接返回计算好的数字和，否则继续向下递归
 * 时间上，每个结点都访问了一遍，空间上，等于递归栈的深度，最坏情况下，链表
 * 时间复杂度：O(N)          空间复杂度：O(N)
 * 
 * 2. 广度优先搜索
 * 需要维护两个队列，分别是TreeNode和加到该节点数字和。
 * 时间上，对每个结点访问一次，空间上取决于队列大小
 * 时间复杂度：O(N)          空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 深度优先搜索
int dfs(TreeNode *root, int num)
{
    num *= 10;
    num += root->val;
    if(root->left == nullptr && root->right == nullptr)
        return num;
    int ans = 0;
    if(root->left)
        ans += dfs(root->left, num);
    if(root->right)
        ans += dfs(root->right, num);
    return ans;
}

int sumNumbers(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    return dfs(root, 0);
}
/* 
int ans = 0;

int sumNumbers(TreeNode *root)
{
    ans = 0;
    if (root == nullptr)
        return ans;
    // 广度优先搜索
    queue<TreeNode *> qu;
    queue<int> nums;
    qu.push(root);
    nums.push(root->val);
    while (!qu.empty())
    {
        TreeNode *node = qu.front();
        int num = nums.front();
        if (node->left)
        {
            qu.push(node->left);
            nums.push(num * 10 + node->left->val);
        }
        if (node->right)
        {
            qu.push(node->right);
            nums.push(num * 10 + node->right->val);
        }
        if (node->left == nullptr && node->right == nullptr)
            ans += num;
        nums.pop();
        qu.pop();
    }
    return ans;
}
 */
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root) << endl;
    return 0;
}