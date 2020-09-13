/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/12
 * @brief medium 二叉树转化为单链表
 * 我个人觉得很难，明天继续这一题
 *
 * 1. 先序遍历+重新构造树
 * 由题意可以看出是一个按先序遍历构成的右侧链。所以得出最简单的解法
 * 时间复杂度: O(N)     空间复杂度: O(N)
 * 
 * 2. 先序遍历和重构树同时进行
 * 每次从栈内弹出一个节点作为当前访问的节点，获得该节点的子节点，如果子节点不为空，
 * 则依次将右子节点和左子节点压入栈内（注意入栈顺序）。
 * 展开为单链表的做法是，维护上一个访问的节点 prev，每次访问一个节点时，令当前访问的节点为 curr，
 * 将 prev 的左子节点设为 null 以及将 prev 的右子节点设为 curr，然后将 curr 赋值给 prev，
 * 进入下一个节点的访问，直到遍历结束。
 * 需要注意的是，初始时 prev 为 null，只有在 prev 不为 null 时才能对 prev 的左右子节点进行更新。
 * 时间复杂度：O(N)         空间复杂度：O(N)
 * 
 * 3. 最好的一种，
 * 看了题解总结一下：将当前结点的右子树放在 先序遍历意义下的 前驱结点的右子树去。
 * 同时前驱结点必然是当前结点的左子树的最右端的结点，或者没有左子树，前驱就是当前结点。
 * 然后将当前节点的右子树变成左子树，左子树变成空。
*******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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

void flatten(TreeNode *root)
{
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left)
        {// 将右子树放到左子树下面
            TreeNode* pred = curr->left;// 前驱
            while(pred->right)
                pred = pred->right;// 找到前驱
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

/* 第二种
void flatten(TreeNode *root)
{
    stack<TreeNode *> st;
    if(root)
        st.push(root);
    TreeNode* prev = nullptr;// 记录前驱
    while(!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();
        if(prev != nullptr)
        {
            prev->left = nullptr;
            prev->right =curr;
        }

        // 先右后左
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);

        prev = curr;
    }
} */

/* 先序遍历（非递归版） 
vector<int> preTrav(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    if (root)
        s.push(root);
    while (!s.empty())
    {
        TreeNode *p = s.top();
        s.pop();
        while (p)
        {
            // root
            ans.push_back(p->val);
            // right
            if (p->right)
                s.push(p->right);
            // left
            p = p->left;
        }
    }
    return ans;
}

// 剩下的就是重新建立整个树（右侧链）
void flatten(TreeNode *root)
{
    // 划重点，展开成为一个“单链表”
    // 应该是先序遍历的顺序,只有right
    if (root == nullptr)
        return;
    vector<int> TreeVal = preTrav(root);
    root->val = TreeVal[0];
    for (size_t i = 1; i < TreeVal.size(); i++)
    {
        if (root->left)
            root->left = nullptr;
        root->right = new TreeNode(TreeVal[i]);
        root = root->right;
    }
    return;
} */

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    return 0;
}