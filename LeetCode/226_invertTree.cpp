/********************************************************************************************
 * @author reddragon
 * @date 2021/2/2
 * @brief easy 翻转二叉树
 * 
 * 1.递归
 * 反转二叉树，好像有点太简单了把
 * 时间复杂度：O(m*n)		空间复杂度：O(m,n)
 ********************************************************************************************/
#include <iostream>
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

// 递归实现
TreeNode *invertTree(TreeNode *root)
{
	if (root == nullptr)
		return root;
	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

int main()
{
	return 0;
}