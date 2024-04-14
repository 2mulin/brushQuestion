/********************************************************************************************
 * @author reddragon
 * @date 2021/4/14
 * @brief medium 搜索二叉树的最小差值
 * 
 * 1，性质
 * 首先一定要想得起，搜索二叉树的性质，也就是搜索二叉树的中序遍历是
 * 一个有序的数列。
 * 那么最简单的思路就有了，那就是中序遍历得到有序数列，
 * 在有序数列中找到差值最小就很简单了。
 * 时间复杂度： O(n)         空间复杂度：O(n)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
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

vector<int> arr;

void midTrav(TreeNode *root)
{
    if (root == nullptr)
        return;
    midTrav(root->left);
    arr.push_back(root->val);
    midTrav(root->right);
}

int minDiffInBST(TreeNode *root)
{
    // 中序遍历获得有序数列
    midTrav(root);
    int ans = INT_MAX;
    for (int i = 1; i < arr.size(); ++i)
        ans = min(ans, abs(arr[i] - arr[i - 1]));
    return ans;
}

int main()
{
    return 0;
}