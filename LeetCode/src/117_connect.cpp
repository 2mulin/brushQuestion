/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/13
 * @brief medium 填充每个节点的下一个右侧节点II
 * 这一题实在前一题增强了难度，不再是完美二叉树
 * 
 * 1. 层次遍历
 * 根据层次遍历就能得到一层，把每一层从左到右连接起来就是了
 * 时间复杂度：O(N)         空间复杂度：O(N)
 * 
 * 2. 使用已经建立的next指针（第二种还没有做）
 * 因为必须处理树上的所有节点，所以无法降低时间复杂度，但是可以尝试降低空间复杂度
 * 显而易见不像上一题一样只有两种类型的next
 * 时间复杂度：O(N)         空间复杂度：O(1)
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

// 层次遍历
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
}

int main()
{

    return 0;
} 