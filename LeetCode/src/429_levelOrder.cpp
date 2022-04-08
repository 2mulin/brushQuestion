/**
 * @author ling
 * @date 2021/4/8
 * @brief medium N叉树的层次遍历
 *
 * 1. 广度优先搜索
 * 利用queue记录下来每一层的所有孩子节点。
 * 
 * 时间复杂度: O(N)         空间复杂度: O(N)
 */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) 
{
    std::vector<std::vector<int>> ans;
    if(!root)
        return ans;
    std::queue<Node*> que;
    que.push(root);
    while(!que.empty())
    {
        int count = que.size(); // 同一层的节点数量
        std::vector<int> nums;
        for(int i = 0; i < count; ++i)
        {
            Node* p = que.front();
            que.pop();
            nums.push_back(p->val);
            for(auto iter = p->children.begin(); iter != p->children.end(); ++iter)
            {
                que.push(*iter);
            }
        }
        ans.push_back(nums);
    }
    return ans;
}

int main()
{
    return 0;
}
