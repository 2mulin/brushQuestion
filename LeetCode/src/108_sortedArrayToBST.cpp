/*******************************************************************************************
 * @author reddragon
 * @date 2020/8/31
 * @brief easy 将有序数组转化为平衡二叉搜索树
 * 
 * 每次二分选出root，然后递归左右两部分就OK了
 * 每个递归需要计算N，N-1，N-2......次，所以是个单调递减数列，空间和时间一样
 * 时间复杂度：O(N*N)     空间复杂度：O(N*N)
 * 
 * 优化版本：
 * 主要是省去了构造左右子树花费的时间。
 * 时间复杂度：O(N)         空间复杂度：O(N*N)
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


// 优化版本
TreeNode *buildTree(const vector<int> &nums,int low, int high)
{
    TreeNode *root = nullptr;
    if(low > high)
        return root;
    else if(low == high)
    {
        root = new TreeNode(nums[low]);
        return root;
    }
    else
    {
        int mid = (low + high) / 2;
        root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, low, mid - 1);
        root->right = buildTree(nums, mid + 1, high);
    }
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return buildTree(nums, 0, nums.size() - 1);
}


// 原版
// TreeNode *sortedArrayToBST(vector<int> &nums)
// {
//     TreeNode *root = NULL;
//     if (nums.empty())
//         return root;
//     else
//     {
//         vector<int> left, right;
//         for (int i = 0; i < nums.size() / 2; i++)
//             left.push_back(nums[i]);
//         root = new TreeNode(nums[nums.size() / 2]);
//         for (int i = nums.size() / 2 + 1; i < nums.size(); i++)
//             right.push_back(nums[i]);
//         root->left = sortedArrayToBST(left);
//         root->right = sortedArrayToBST(right);
//     }
//     return root;
// }

int main()
{
    return 0;
}