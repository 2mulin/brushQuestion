/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/29
 * @brief easy 树的层次遍历
 * 这个有点不一样，他是要求一层一层的输出，而不是整个输出
 * 
 * 还是一样的思路：队列作为辅助结构。
 * 时间复杂度:O(N)         空间复杂度:O(N)
 *******************************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        vector<int> temp;
        size_t len = qu.size();// 得到这一层的元素个数
        for (size_t i = 0; i < len; i++)
        {
            TreeNode *p = qu.front();
            qu.pop();
            temp.push_back(p->val);
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}