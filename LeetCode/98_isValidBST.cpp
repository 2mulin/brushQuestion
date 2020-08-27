/**************************************************************************
 * @author reddragon
 * @date 2020/8/27
 * @brief medium 验证搜索二叉树
 * 1.中序遍历：二叉搜索树的中序遍历一定是有序的，否则不合法。空间可以优化成O(1)
 * 时间：O(N)       空间：O(N)
 * 
 * 2.递归：要注意一点的就是，不是说左节点小于root且右结点大于root就OK了，
 * 而是左子树小于root且右子树小于root
 * 时间：O(N)       空间:O(N)
 ***************************************************************************/
#include <iostream>
#include <climits>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode *root, long min, long max)
{
    if(!root)
        return true;
    if(root->val <= min || root->val >= max)
        return false;
    return helper(root->left,min,root->val) && helper(root->right, root->val, max);
}

bool isValidBST(TreeNode *root)
{
    return helper(root,LONG_MIN,LONG_MAX);
}


bool isValidBST(TreeNode *root)
{
    stack<TreeNode *> st;
    // vector<int> arr;
    bool isInit = false;
    int now = 0;
    // 中序遍历
    TreeNode *p = root;
    while(p || !st.empty())
    {
        if(p)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
            //arr.push_back(p->val);
            if(!isInit || now < p->val)
            {
                isInit = true;
                now = p->val;
            }
            else
                return false;
            p = p->right;
        }
    }
    // for(int i = 1; i < arr.size(); i++)
    // {
    //     if(arr[i] < arr[i-1])
    //         return false;
    // }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    cout << isValidBST(root) << endl;
    return 0;
}