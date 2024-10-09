/**
 * @date 2022/7/25
 * @author 2mu
 * @brief medium 完全二叉树插入器
 *
 * 1. 实现insert
 * 完全二叉树：出最后一层之外，其它每一层都是满的节点。现在要求是插入一个节点之后，
 * 仍然保持完全二叉树的结构。
 * 
 * 有条规律，即完全二叉树的最后一个非叶子节点在数组的位置。
 * 
 * 时间复杂度：构造是层次遍历O(N)， insert操作是O(1)
 * 空间复杂度：O(N)
 * 
 * 2. 优化空间
 *      1. 数组没必要记录所有的节点。只需要用队列按顺序记录**没有完整左右孩子的节点**。每次取出队列首元素，补充其孩子节点。若是左右孩子都有了，就将其从队列中移除。
 *      2. 二进制表示。
 */

#include <iostream>
#include <algorithm>
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

class CBTInserter 
{
public:
    CBTInserter(TreeNode* root) 
    {
        // assert(root)
        vecNodes.push_back(root);
        // 层次遍历，将所有节点记录下来。
        int idx = 0;
        while(idx < vecNodes.size())
        {
            TreeNode* root = vecNodes[idx++];
            if(root->left)
                vecNodes.push_back(root->left);
            if(root->right)
                vecNodes.push_back(root->right);
        }
    }
    
    int insert(int val) {
        int parentIdx = 0;
        if(vecNodes.size() % 2)
            parentIdx = vecNodes.size() / 2;
        else
            parentIdx = vecNodes.size() / 2 - 1;
        TreeNode* newNode = new TreeNode(val);
        vecNodes.push_back(newNode);
        TreeNode* parent = vecNodes[parentIdx];
        if(parent->left == nullptr)
            parent->left = newNode;
        else
            parent->right = newNode;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return vecNodes[0];
    }
private:
    std::vector<TreeNode*> vecNodes;
};

int main()
{
    TreeNode* root = new TreeNode(1, 
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), nullptr));

    CBTInserter inserter(root);
    std::cout << inserter.insert(7) << std::endl;
    std::cout << inserter.insert(8) << std::endl;

    root = inserter.get_root();
    return 0;
}
