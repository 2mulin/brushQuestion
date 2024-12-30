/**
 * @date 2024/12/30
 * @author 2mu
 * @brief medium 二叉树中的链表
 *
 * 1. 暴力搜索
 * 遍历一遍树，得到所有的路径，然后再和head进行比较，是不是子串，可以判断出是否有满足条件的路径。
 * 树高最多是100，树的路径最多是2的100次方。时间复杂度很高。
 * 
 * 时间复杂度: O(2的100次方)
 * 空间复杂度: O(n)
 * 
 * 2. 递归
 * 递归遍历树，每次root节点和链表head进行比较，只要找到一个路径就可以返回true。
 * 全部遍历完都没找到，返回false。遍历写起来比较麻烦，注意区分一个是连续的判断节点是否相等。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 树的节点连续相等才返回true
bool isSequencePath(ListNode* head, TreeNode* root)
{
    if (head == nullptr)
        return true;
    else if(root == nullptr)
        return false;

    if (head->val == root->val)
        return isSequencePath(head->next, root->left) || isSequencePath(head->next, root->right);
    else
        return false;
}


bool isSubPath(ListNode* head, TreeNode* root)
{
    if (head == nullptr)
        return true;
    if (root == nullptr)
        return false;

    if (head->val == root->val && (isSequencePath(head->next, root->left) || isSequencePath(head->next, root->right)))
    {
        return true;
    }

    return isSubPath(head, root->left) || isSubPath(head, root->right);
}


int main()
{
    return 0;
}
