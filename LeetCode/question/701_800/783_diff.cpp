/**
 * @author mulin
 * @date 2024/4/14
 * @brief easy 搜索二叉树的最小距离
 * 
 * 1. 搜索二叉树性质
 * 一定要先想起搜索二叉树的性质, 也就是搜索二叉树的中序遍历是有序的;
 * 所以先中序遍历得到一个有序数组, 然后遍历数组, 每相邻两个元素做差, 记录差的最小值;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

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


void mid_traversal(TreeNode *root, std::vector<int>& sorted_array)
{
    if (root == nullptr)
        return;
    mid_traversal(root->left, sorted_array);
    sorted_array.push_back(root->val);
    mid_traversal(root->right, sorted_array);
}

int minDiffInBST(TreeNode *root)
{
    std::vector<int> sorted_array;
    // 中序遍历获得有序数列
    mid_traversal(root, sorted_array);
    int ans = INT_MAX;
    for (int i = 1; i < sorted_array.size(); ++i)
        ans = min(ans, abs(sorted_array[i] - sorted_array[i - 1]));
    return ans;
}


int main()
{
    return 0;
}
