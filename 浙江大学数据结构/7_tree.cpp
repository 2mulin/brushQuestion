/********************************************************************************************
 * @author reddragon
 * @date 2020/11/27
 * @brief 输出树的所有叶子节点
 * 
 * 1.层次遍历
 * 根据题意可得，从上至下，从左至右输出叶子结点，显而易见层次遍历
 * 遍历过程中记录下来所有的叶子结点
 * 最后输出
 * 时间复杂度：O(N)结点数目
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node() = default;
    node(char _data)
        :data(_data), left(nullptr), right(nullptr){}
};

typedef node* tree;

tree createTree(int n)
{
    if(n == 0)
        return nullptr;
    // 先创建所有的结点
    vector<node*> arr;// 结点指针数组
    for(int i = 0; i < n; ++i)
        arr.push_back(new node(i));
    vector<bool> root(n, true);
    // 建立起连接关系
    for(int i = 0; i < n; ++i)
    {
        char lch, rch;
        cin >> lch >> rch;
        if(lch != '-')
        {
            arr[i]->left = arr[lch - '0'];
            root[lch - '0'] = false;// 入度不为0，一定不是根节点
        }
        if(rch != '-')
        {
            arr[i]->right = arr[rch - '0'];
            root[rch - '0'] = false;// 入度不为0，一定不是根节点
        }
    }
    int ret = 0;
    for(int i = 0; i < n; ++i)
        if(root[i])
        {
            ret = i;
            break;
        }
    return arr[ret];// 返回root结点
}

void print(tree root)
{
    vector<int> ans;
    // 层次遍历
    queue<tree> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int len = qu.size();
        for(int i = 0; i < len; ++i)
        {
            tree temp = qu.front();
            qu.pop();
            if(!temp->left && !temp->right)
            {
                ans.push_back(temp->data);
                continue;
            }
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
        }
    }
    size_t len = ans.size();
    for(size_t i = 0; i < len - 1; ++i)
        cout << ans[i] << ' ';
    cout << ans[len - 1];
}

int main()
{
    int n;
    cin >> n;
    tree t = createTree(n);
    print(t);
    return 0;
}