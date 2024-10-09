/**
 * @date 2023/2/17
 * @author 2mu
 * @brief medium N叉树的层次遍历
 *
 * 1. 队列
 * 
 * 利用queue记录下来每一层的所有孩子节点; 最后统一输出;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>


using namespace std;


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


vector<vector<int>> levelOrder(Node *root)
{
    std::vector<std::vector<int>> results;
    std::queue<Node*> que;
    if(root)
        que.push(root);
    while(!que.empty())
    {
        int level_node_count = que.size();
        std::vector<int> level_node;
        while(level_node_count--)
        {
            Node* node = que.front();
            que.pop();
            level_node.push_back(node->val);

            for(Node* children : node->children)
                que.push(children);
        }
        results.push_back(level_node);
    }
    return results;
}


int main()
{
    return 0;
}
