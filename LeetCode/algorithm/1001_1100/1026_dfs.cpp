/**
 * @date 2023/4/5
 * @author 2mu
 * @brief medium 节点与其祖先之间的最大差值
 *
 * 1. DFS
 * 深度优先搜索, 遍历每一条路径, 将该路径上的**任意**两个相邻节点都计算一次差值;
 * 保留最大差值; 时间复杂度较高, 每个节点都需要和同一条路径上的其它节点做一次计算;
 * 设一条路径最多n个节点, 则时间复杂度是 n*(n-1)
 * 
 * 时间复杂度: O(n * (n-1))
 * 空间复杂度: O(n)
 * 
 * 2. 官方题解
 * 思路也是DFS, 找到子孙节点所在的同一条路径上, 不同的是, 它同一条路径只计算一次;
 * 只需要用同一条路径上的最大值和最小值做差, 就可以...
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int dfs(TreeNode* root, std::vector<int>& dfs_path)
{
    int max_diff = 0;
    if(!dfs_path.empty())
    {
        for(auto val : dfs_path)
        {
            max_diff = std::max(max_diff, abs(root->val - val));
        }
        
    }
    dfs_path.push_back(root->val);

    if(root->left)
    {
        int val = dfs(root->left, dfs_path);
        max_diff = std::max(max_diff, val);
    }

    if(root->right)
    {
        int val = dfs(root->right, dfs_path);
        max_diff = std::max(max_diff, val);
    }
    
    dfs_path.pop_back();
    return max_diff;
}


int maxAncestorDiff(TreeNode* root)
{
    if(!root)
        return 0;
    std::vector<int> dfs_path;
    int max_diff = dfs(root, dfs_path);
    return max_diff;
}

 
int main(int argc, char **argv)
{
    return 0;
}