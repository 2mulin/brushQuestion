#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * @brief 二叉树中序遍历非递归版本, 使用stack即可模拟整个递归过程; 非常棒
 * @param pRoot 二叉树的root节点
 * @return 中序遍历结果
 */
vector<int> in_order_traversal(TreeNode *pRoot)
{
    vector<int> result;

    stack<TreeNode*> st;
    // ptr可以为NULL
    while (true)
    {
        // 到达左侧链最下面
        if (pRoot)
        {
            st.push(pRoot);
            pRoot = pRoot->left;
        }
        else if (!st.empty())
        {
            pRoot = st.top();
            st.pop();
            // 注意: 这里是唯一访问节点数据的位置
            result.push_back(pRoot->val);
            // 右转
            pRoot = pRoot->right;
        }
        else
            break;// st已经空了, 直接退出
    }
    return result;
}


int main()
{
    return 0;
}