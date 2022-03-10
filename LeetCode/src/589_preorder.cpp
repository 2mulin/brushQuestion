/**
 * @author ling
 * @date 2021/3/10
 * @brief easy N叉树的前序遍历
 *
 * 1. 递归
 * 时间复杂度：O(N)       空间复杂度：O(N)
 * 
 * 2. 迭代
 * 时间复杂度：O(N)       空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<int> preorder(Node* root)
{
    std::vector<int> ans;
    if(!root)
        return ans;

    std::stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* node = st.top();
        st.pop();
        if (!node)
            continue;
        ans.push_back(node->val);
        for(auto it = node->children.rbegin(); it != node->children.rend(); ++it)
            st.push((*it));
    }
    return ans;
}

int main()
{
    return 0;
}