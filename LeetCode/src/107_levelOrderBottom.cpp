/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/31
 * @brief easy 树的层次遍历
 * 将层次遍历反转一下就OK了
 * 时间复杂度：O(N)     空间复杂度：O(N)
 ******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int> > ans;
    queue<TreeNode*> qu;
    if(root)
        qu.push(root);
    while(!qu.empty())
    {
        size_t size = qu.size();
        vector<int> arr(size);
        // 一层层记录
        for(size_t i = 0; i < size; i++)
        {
            TreeNode *p = qu.front();
            arr[i] = p->val;
            qu.pop();
            if(p->left)
                qu.push(p->left);
            if(p->right)
                qu.push(p->right);
        }
        ans.push_back(arr);
    }
    // 将最后结果反转就是从tree底端到root了
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    return 0;
}