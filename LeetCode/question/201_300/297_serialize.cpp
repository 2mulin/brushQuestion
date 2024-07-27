/********************************************************************************************
 * @author reddragon
 * @date 2021/3/11
 * @brief hard 二叉树的序列化和反序列化
 * 1. 递归
 * 序列化不需要说, 很简单, 前序,后序,层次遍历啊都可以, 但是不要用中序, 中序无法反序列化
 * 时间复杂度: O(N)         空间复杂度: O(N)
 * 
 * 2. 非递归版遍历
 * 可能会快一些, 没有递归地消耗
 * 时间复杂度: O(N)         空间复杂度: O(N)
 ********************************************************************************************/
#include "LeetCode/include/dataStruct.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string ans;
    if (root == NULL)
        return "N/";
    else
        ans = std::to_string(root->val) + '/';
    ans += serialize(root->left);
    ans += serialize(root->right);
    return ans;
}

TreeNode *buildTree(string &data)
{
    // 找到元素间的分隔符'/'
    auto it = data.begin();
    string str;
    while (*it != '/')
    {
        str.push_back(*it);
        data.erase(it);
    }
    data.erase(it);
    TreeNode *root = NULL;
    if (str != "N")
    {
        root = new TreeNode(stoi(str));
        root->left = buildTree(data);
        root->right = buildTree(data);
    }
    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    return buildTree(data);
}

void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << '\t';
    print(root->left);
    print(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    string ret = serialize(root);
    cout << ret << std::endl;

    TreeNode *tmp = deserialize(ret);
    print(tmp);
}
