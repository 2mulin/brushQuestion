/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/11
 * @brief medium 路径总和
 * 112题的升级版，要求出所有满足条件的路径。
 * 
 * 没有官方题解。
 * 1. 深度优先搜索
 * 递归往下走，知道叶子节点，判断sum是否为0，是的返回节点值，不是的话，返回空的。
 * 注意细节
*******************************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return vector<vector<int>>();

    // 必须是叶子结点，而且sum达到了要求。（递归基）
    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum == root->val)
            return vector<vector<int>>(1, vector<int>(1, sum));
        return vector<vector<int>>();
    }

    vector<int> arr;
    vector<vector<int>> left, right;
    if (root)
    {
        arr.push_back(root->val);
        if (root->left)
            left = pathSum(root->left, sum - root->val);
        if (root->right)
            right = pathSum(root->right, sum - root->val);
    }

    // 将arr和left所有的合并，如果左右都为空，说明sum都不满足条件，没有返回，所以本次递归也是返回空数组
    for (size_t i = 0; i < left.size(); i++)
    {
        vector<int> temp = arr;
        temp.insert(temp.end(), left[i].begin(), left[i].end());
        ans.emplace_back(temp);
    }

    for (size_t i = 0; i < right.size(); i++)
    {
        vector<int> temp = arr;
        temp.insert(temp.end(), right[i].begin(), right[i].end());
        ans.emplace_back(temp);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> ans = pathSum(root, 22);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}