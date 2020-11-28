/********************************************************************************************
 * @author reddragon
 * @date 2020/11/28
 * @brief 根据入栈顺序得到后序遍历序列
 * 
 * 1. 模拟
 * 主要的任务就是见一棵树，然后后序遍历就OK了。
 * 这个输入的思路优点像是先序遍历的非递归实现，根据这个建立一棵树，最后输出后序遍历就行了
 * 时间复杂度：O(N)结点数目
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int num)
        :data(num){}
};
typedef node* tree;

void printAns(vector<int>& ans, tree root)
{
    if(root)
    {
        printAns(ans, root->left);
        printAns(ans, root->right);
        ans.push_back(root->data);
    }
}

int main()
{
    int n;
    cin >> n;
    string input;
    int num;
    cin >> input >> num;
    tree root = new node(num);
    tree t1 = root;
    stack<tree> st;
    st.push(root);
    bool LeftOrRight = true;// true为左
    for(int i = 1; i < n*2; ++i)
    {
        cin >> input;
        if(input == "Push")
        {
            int num;
            cin >> num;
            if(LeftOrRight)
            {
                root->left = new node(num);
                root = root->left;
                st.push(root);
            }
            else
            {
                root->right = new node(num);
                root = root->right;
                st.push(root);
            }
            LeftOrRight = true;
        }
        else
        {
            root = st.top();
            st.pop();
            LeftOrRight = false;
        }
    }
    vector<int> ans;
    printAns(ans, t1);
    for(size_t i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << ' ';
    cout << ans[ans.size() - 1];
    return 0;
}