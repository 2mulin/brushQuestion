/**
 * @date 2024/2/9
 * @author 2mu
 * @brief medium 二叉树的最近公共祖先
 * 
 * 1. DFS(将路径暂存)
 * 由于是二叉树, 所以root节点到指定节点的路径只存在一条; 现在需要求公共祖先节点;
 * 可以转换为求路径上的同时出现的节点; 那只要先把节点的路径求出来即可; 然后求两条路径上
 * 都出现的节点;
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 
 * 官方题解的想法是利用map存下父节点和子节点的关系，这样就可以通过子节点找到父节点了
 * 
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归解法, 还是非常不错的...
// bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
// {
//     if (root == nullptr)
//         return false;
//     path.push_back(root);
//     if (root == node)
//         return true;
//     if (findPath(root->left, node, path))
//         return true;
//     else
//     {
//         while (path.back() != root)
//             path.pop_back(); // 回溯
//         if (findPath(root->right, node, path))
//             return true;
//     }
//     return false;
// }

// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     // 得到root-》p和root-》q的两条路径
//     vector<TreeNode *> vecP, vecQ;
//     findPath(root, p, vecP);
//     findPath(root, q, vecQ);
//     int i = 0;
//     int len = min(vecP.size(), vecQ.size());
//     if (len == 0)
//         return nullptr;
//     while (i < len && vecP[i] == vecQ[i])
//         ++i;
//     return vecP[i - 1];
// }


// 非递归搜索路径
std::vector<TreeNode*> getSearchPath(TreeNode* root, TreeNode* target)
{
    std::vector<TreeNode*> vct;
    vct.push_back(root);
    if(root == target)
        return vct;

    while(!vct.empty())
    {
        TreeNode* node = vct.back();
        
        if (node->left)
        {
            vct.push_back(node->left);
        }
        else if(node->right)
        {
            vct.push_back(node->right);
        }
        else
        {
            TreeNode* tmp = node;
            do
            {
                tmp = node;
                vct.pop_back();
                if(vct.empty())
                    break;// 按照题目来说, 路径一定存在, 不可能出现搜索不到的情况....
                node = vct.back();
            }while(!node->right || node->right == tmp);
            vct.push_back(node->right);
        }
        if(vct.back() == target)
            return vct;
    }
    return {};
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    std::vector<TreeNode*> vct1 = getSearchPath(root, p);
    std::vector<TreeNode*> vct2 = getSearchPath(root, q);
    // 前半部分祖先节点一定是相同的...
    int len = min(vct1.size(), vct2.size());
    for(int i = 0; i < len; ++i)
    {
        if(vct2[i] != vct1[i])
        {
            return vct1[i - 1];
        }
    }
    return vct1[len - 1];
}

int main()
{
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    cout << lowestCommonAncestor(&root, root.right, root.left)->val << endl;
    return 0;
}