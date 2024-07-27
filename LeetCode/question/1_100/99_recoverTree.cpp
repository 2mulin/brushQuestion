/******************************************************************************************************************************
 * @author reddragon
 * @date 2020/8/27
 * @brief hard 恢复搜索二叉树
 * 首先，看到搜索二叉树就要知道中序遍历是有序的，所以第一个思路呼之欲出
 * 1：首先中序遍历取的所有的结点，然后根据数值重新排序。
 * 时间O(N)         空间O(N)
 * Morris 中序遍历
 * 1. 如果 xx 无左孩子，则访问 xx 的右孩子，即 x = x.\textit{right}x=x.right。
 * 2. 如果 xx 有左孩子，则找到 xx 左子树上最右的节点（即左子树中序遍历的最后一个节点，xx 在中序遍历中的前驱节点），
 *    我们记为 \textit{predecessor}predecessor。根据 \textit{predecessor}predecessor 的右孩子是否为空，进行如下操作。
 *      2.1 如果 \textit{predecessor}predecessor 的右孩子为空，则将其右孩子指向 xx，然后访问 xx 的左孩子，即 x = x.\textit{left}x=x.left。
 *      2.2 如果 \textit{predecessor}predecessor 的右孩子不为空，则此时其右孩子指向 xx，说明我们已经遍历完 xx 的左子树，
 *          我们将 \textit{predecessor}predecessor 的右孩子置空，然后访问 xx 的右孩子，即 x = x.\textit{right}x=x.right。
 * 3. 重复上述操作，直至访问完整棵树。
 *******************************************************************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode *root)
{
    vector<TreeNode *> arr;
    stack<TreeNode *> st;
    while(root || !st.empty())
    {
        if(root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            arr.push_back(root);
            root = root->right;
        }
    }
    vector<int> nums(arr.size(),0);
    for(size_t i = 0; i < arr.size(); i++)
        nums[i] = arr[i]->val;
    
    sort(nums.begin(),nums.end());
    for(size_t i = 0; i < arr.size(); i++)
    {
        arr[i]->val = nums[i];
    }
    return;
}

int main()
{
    return 0;
}