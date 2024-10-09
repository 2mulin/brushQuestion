/**
 * @date 2022/8/27
 * @author 2mu
 * @brief medium 二叉树最大宽度
 *
 * 一. 遍历一遍
 * 1. 给树的每个节点都打上编号，什么编号？ 即完满二叉树的形成数组的数组下标。如root标号为0，root->left就是1，root->right就是2。
 * 2. 对整棵树使用层次遍历，其它遍历也行。找到每一层节点不为nullptr最左边的编号，节点不为nullptr最右边的编号。然后对编号做差+1，就是宽度。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <deque>

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

int widthOfBinaryTree(TreeNode *root)
{
    if(!root)
        return 0;
    std::deque<std::pair<TreeNode*, unsigned long long>> deq;
    unsigned long long result = 1;
    deq.push_back(std::pair<TreeNode*, unsigned long long>(root, 0));
    int sz = 0;
    while(!deq.empty())
    {
        if(sz == 0)
        {
            sz = deq.size();
            result = std::max(result, deq.back().second - deq.front().second + 1);
        }
        std::pair<TreeNode*, unsigned long long> pa= deq.front();
        deq.pop_front();
        --sz;
        if(pa.first->left)
        {
            deq.push_back(std::pair<TreeNode*, unsigned long long>(pa.first->left, pa.second * 2 + 1));
        }
        if(pa.first->right)
        {
            deq.push_back(std::pair<TreeNode*, unsigned long long>(pa.first->right, pa.second * 2 + 2));
        }
    }
    return result;
}

int main()
{

    return 0;
}
