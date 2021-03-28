/********************************************************************************************
 * @author reddragon
 * @date 2021/3/28
 * @brief medium 二叉搜索树迭代器
 * 
 * 1，中序遍历
 * 可以直接中序遍历一次, 把中序遍历结果放在vector中, 然后依次返回就是了
 * 时间复杂度：O(n)			空间复杂度: O(n)
 * 
 * 2. 迭代版
 * 中序遍历可以实现为迭代版, 这里就是实现迭代版的
 * 使用一个辅助stack, 重要的点还是左侧连, 左侧连走到底, 然后访问的时候右转
 * 左侧连到底
 * 时间复杂度: O(n)         空间复杂度: O(n)
 ********************************************************************************************/
#include <iostream>
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

class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *curr = st.top();
        st.pop();
        TreeNode *tmp = curr;
        // 将当前结点向右转, 并且左侧连全部入栈
        tmp = tmp->right;
        while (tmp)
        {
            st.push(tmp);
            tmp = tmp->left;
        }
        return curr->val;
    }

    bool hasNext()
    {
        if (!st.empty())
            return true;
        return false;
    }
};

int main()
{
    return 0;
}
