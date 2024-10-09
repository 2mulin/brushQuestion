/**
 * @author ling
 * @date 2021/3/12
 * @brief easy N叉树的后续遍历
 * 
 * 1. 递归
 * 按照左右根来就是了
 * 时间复杂度：O(N)       空间复杂度：O(N)    
 *
 * 1. 利用stack实现非递归版遍历
 * 后序遍历的非递归是最不好写的，所以使用 《根右左》 模仿先序遍历。
 * 然后翻转成后续遍历。
 * 时间复杂度：O(N)       空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
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

std::vector<int> postorder(Node *root)
{
    std::vector<int> ans;
    if(!root)
        return ans;

    // 先得到 根右左
    std::stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);
        for(auto iter = root->children.begin(); iter != root->children.end(); ++iter)
        {
            st.push(*iter);
        }
    }
    // 反转为 左右根
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}