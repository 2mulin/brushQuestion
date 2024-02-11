/**
 * @date 2024/2/11
 * @author 2mu
 * @brief easy  二叉树的前序遍历
 *
 * 1. 递归版
 * 很简单, 就不多说了, 但是空间复杂度高
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. 非递归的二叉树前序遍历
 * 需要利用stack, 先找到左侧链, 也就是先将root入栈; 然后一个循环判断栈为空时退出循环;
 * 循环中, 每次取出栈顶节点:
 *    1. 如果当前节点的左孩子不为空, 则入栈, 继续下一轮循环
 *    2. 如果左孩子为空, 那就判断右孩子, 右孩子不为空则入栈, 继续下一轮循环
 *    3. 如果左右孩子都为空, 则需要**向右拐**, 也就是右上方找到一个合适的节点;
 * 第2,3步骤可以合并, 实际上都是找合适的右孩子, 第2步是往右下方找, 第3步是往右上方找;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// std::vector<int> preorderTraversal(TreeNode *root)
// {
//     std::vector<int> vct;
//     if(!root)
//         return vct;
//     else
//         vct.push_back(root->val);
//     if(root->left)
//     {
//         std::vector<int> tmp = preorderTraversal(root->left);
//         for(auto val : tmp)
//             vct.push_back(val);
//     }
//     if(root->right)
//     {
//         std::vector<int> tmp = preorderTraversal(root->right);
//         for(auto val : tmp)
//             vct.push_back(val);
//     }
//     return vct;
// }

std::vector<int> preorderTraversal(TreeNode* root)
{
    std::vector<int> vct;
    std::stack<TreeNode*> st;
    if(root)
        st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        vct.push_back(node->val);
        if(node->left)
        {
            st.push(node->left);
        }
        else if(node->right)
        {
            st.push(node->right);
        }
        else
        {
            st.pop();
            if(st.empty())
                return vct;
            TreeNode* parent = st.top();
            while( parent->right == NULL || parent->right == node )
            {
                node = parent;
                st.pop();
                if(st.empty())
                    return vct;
                else
                    parent = st.top();
            }
            st.push(parent->right);
        }
    }
    return  vct;
}

int main()
{
    std::cout << "hello world!" << std::endl;
    return 0;
}
