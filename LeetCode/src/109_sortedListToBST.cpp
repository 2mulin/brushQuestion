/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/7
 * @brief medium 将有序链表转化为平衡二叉搜索树
 * 
 * 1. 将链表记录为数组，然后用上一题的思路，使用二分。
 * 
 * 2. 分治：先找到root。使用快慢指针，快指针一次走两步，满指针一次走一步。
 * 最终快指针走到底的时候，满指针在中位数，也就是root上。然后递归
*******************************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* getMedian(ListNode* left, ListNode* right) {
    ListNode* fast = left;
    ListNode* slow = left;
    while (fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

TreeNode* buildTree(ListNode* left, ListNode* right) {
    if (left == right) {
        return nullptr;
    }
    ListNode* mid = getMedian(left, right);
    TreeNode* root = new TreeNode(mid->val);
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return buildTree(head, nullptr);
}

/* 
将链表记录为数组，然后用上一题的思路，使用二分。
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

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while(head)
    {
        nums.push_back(head->val);
        head = head->next;
    }
    return buildTree(nums, 0 ,nums.size() - 1);
}
*/

int main()
{
    return 0;
}