/**
 * @date 2025/4/5
 * @author 2mu
 * @brief medium 最深树节点的最近公共祖先
 *
 * 1. 笨办法
 * 
 * 将每一条root到叶子节点的路径都计算出来, 再统计最长的几条路径的公共祖先,
 * 即从后往前遍历, 发现相同就是公共祖先;
 * 
 * 统计root到叶子节点的路径也是可以直接使用stack模拟一下, 做一遍前序遍历;
 * 
 * 时间复杂度: O(n)       空间复杂度: O(n*n)
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <stack>
 
 using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 
 // 递归找到所有root到叶子节点的路径
 std::vector<std::vector<TreeNode*>> dfs(TreeNode* root, std::vector<TreeNode*> current_path)
 {
     std::vector<std::vector<TreeNode*>> all_path;
     if (!root)
         return all_path;
 
     current_path.push_back(root);
     if (root->left)
     {
         auto left_result = dfs(root->left, current_path);
         for(auto path : left_result)
         {
             all_path.push_back(path);
         }
     }
     if (root->right)
     {
         auto right_result = dfs(root->right, current_path);
         for(auto path : right_result)
         {
             all_path.push_back(path);
         }
     }
 
     if (root->left == NULL && root->right == NULL)
     {
         all_path.push_back(current_path);
     }
     return all_path;
 }
 
 
 TreeNode* lcaDeepestLeaves(TreeNode* root) 
 {
     // 保存最长路径
     std::vector<std::vector<TreeNode*>> path_arr;
     std::vector<std::vector<TreeNode*>> all_path = dfs(root, {});
 
     int max_depth = 0;
     for(auto path : all_path)
     {
         if (path.size() > max_depth)
         {
             max_depth = path.size();
             path_arr.clear();
             path_arr.push_back(path);
         }
         else if (path.size() == max_depth)
         {
             path_arr.push_back(path);
         }
     }
     if(path_arr.empty())
         return NULL;
 
     for(int i = max_depth - 1; i >= 0; --i)
     {
         bool flag = true;
         TreeNode* ptr = path_arr[0][i];
         for(int j = 1; j < path_arr.size(); ++j)
         {
             if (path_arr[j][i] != ptr)
             {
                 flag = false;
                 break;
             }
         }
 
         if (flag == true)
             return ptr;
     }
     return NULL;
 }
 
 
 int main()
 {
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
 
     TreeNode* ptr = lcaDeepestLeaves(root);
     if (ptr)
         std::cout << ptr->val << std::endl;
     else
         std::cout << "NULL" << std::endl;
     return 0;
 }
 