/**
 * @date 2023/8/20
 * @author 2mu
 * @brief easy  
 * 
 * 1. 过于简单
 * 
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkTree(TreeNode *root)
{
    if(root)
    {
        if(root->left && root->right)
        {
            if(root->left->val + root->right->val == root->val)
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}
