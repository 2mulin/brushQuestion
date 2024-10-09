/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/13
 * @brief medium 填充每个节点的下一个右侧节点II
 * 1. 层次遍历
 * 根据层次遍历就能得到一层，把每一层从左到右连接起来就是了
 * 时间复杂度：O(N)         空间复杂度：O(N)
 * 
 * 2. 使用已经建立的next指针
 * 一种Tree中，存在两种类型的next指针。第一种是连接同一个父节点的两个子节点
 * 第二种相邻的不同父节点的子节点之间建立连接
*******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 使用已经建立的next指针
Node *connect(Node *root)
{
    Node* curr = root;
    Node* lineLeft = root;// 每一行最左边的结点
    while(curr)
    {
        if(curr->left)
        {// 完美二叉树，有左孩子就一定有右孩子，要么没有孩子
            curr->left->next = curr->right;
            if(curr->next)
                curr->right->next = curr->next->left;
            else
                curr->right->next = nullptr;
        }
        if(curr->next)
            curr = curr->next;
        else
        {// 没有next，说明要换行了
            curr = lineLeft->left;
            lineLeft = lineLeft->left;
        }
    }
    return root;
}

/* 层次遍历
Node *connect(Node *root)
{
    queue<Node *> qu;
    if (root)
        qu.push(root);
    while (!qu.empty())
    { // 层次遍历
        int len = qu.size();
        for (int i = 0; i < len; i++)
        {
            Node *p = qu.front();
            qu.pop();
            if (i != len - 1)
                p->next = qu.front();
            else
                p->next = NULL;
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
    }
    return root;
} */

int main()
{

    return 0;
}