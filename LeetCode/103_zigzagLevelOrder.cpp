/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/29
 * @brief medium 树的锯齿状遍历
 * 1. 直接层次遍历，每一层单独拎出来判断，是否需要reverse。达到锯齿状的效果。
 * 时间复杂度:O(N)         空间复杂度:O(N)
 * 
 * 2. 利用deque,可以直接往尾部添加，或者往头部添加，我觉得有点问题。
 * 就像是[1,2,3,4,null,null,5]这种树。
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    bool flag = false;
    queue<TreeNode *> qu;
    vector<vector<int>> ans;
    if (root)
        qu.push(root);
    while (!qu.empty())
    {
        size_t len = qu.size();
        vector<int> temp(len);
        for (size_t i = 0; i < len; i++)
        {
            TreeNode *p = qu.front();
            qu.pop();
            temp[i] = p->val;
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
        // 翻转
        if (flag)
            reverse(temp.begin(), temp.end());
        flag = !flag;
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}