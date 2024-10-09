/**
 * @date 2022/6/19
 * @author 2mu
 * @brief medium 出现次数最多的子树和
 *
 * 1. stack模拟dfs
 * 按照规则，先计算出每个节点的 子树和。然后使用一个map记录出现过的 子树和 次数。
 *
 * 使用stack实现非递归dfs，实际没必要。但这样会省内存。
 * 
 * 遍历一遍map，把出现次数是 最多次数 的 子树和 打印出来。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> findFrequentTreeSum(TreeNode *root)
{
    if(!root)
        return vector<int>();

    std::unordered_map<TreeNode*, int> nodeToSum;
    std::unordered_map<int, int> sumToCount;  // sum出现的次数
    nodeToSum[nullptr] = 0;
    std::stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        auto leftIter = nodeToSum.find(node->left);
        auto rightIter = nodeToSum.find(node->right);
        if(leftIter != nodeToSum.end() && rightIter != nodeToSum.end())
        {
            int sum = node->val;
            sum += leftIter->second;
            sum += rightIter->second;
            nodeToSum[node] = sum;
            sumToCount[sum]++;
            st.pop();
        }
        else if(leftIter == nodeToSum.end())
            st.push(node->left);
        else if(rightIter == nodeToSum.end())
            st.push(node->right);
        else
        {
            st.push(node->left);
            st.push(node->right);
        }
    }

    // 找到最大出现次数
    int count = 0;
    for(auto iter = sumToCount.begin(); iter != sumToCount.end(); ++iter)
    {
        count = std::max(count, iter->second);
    }


    std::vector<int> result;
    // 所有出现次数等于最大次数 的 sum
    for(auto iter = sumToCount.begin(); iter != sumToCount.end(); ++iter)
    {
        if(iter->second == count)
            result.push_back(iter->first);
    }
    return result;
}

int main()
{
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(-3);
    TreeNode* root = new TreeNode(5, left, right);

    vector<int> result = findFrequentTreeSum(root);
    for(auto num : result)
        std::cout << num << std::endl;
    return 0;
}
