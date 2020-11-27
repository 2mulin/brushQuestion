/********************************************************************************************
 * @author reddragon
 * @date 2020/11/27
 * @brief 树的同构
 * 
 * 1.递归
 * 这题很简单，但是难点是在建树上面，因为不是按顺序输入的，所以只能先建立所有的结点
 * 最后再把所有关联起来，成为一棵树。
 * 判断同构比较简单，只有两种情况，
 * 1. 树1的左子树等于树2的左子树，树1的右子树等于树2的右子树。
 * 2. 树1的右子树等于树2的左子树，树1的左子树等于树2的右子树。
 * 时间复杂度：O(2的深度次方)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct node
{
    char data;
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
    vector<char> str(n);// 所有的结点
    vector<char> left(n),right(n);
    for(int i = 0; i < n; ++i)
        cin >> str[i] >> left[i] >> right[i];
    // 先创建所有的结点
    vector<node*> arr;// 结点指针数组
    for(int i = 0; i < n; ++i)
        arr.push_back(new node(str[i]));
    vector<bool> root(n, true);
    // 建立起连接关系
    for(int i = 0; i < n; ++i)
    {
        char lch = left[i],rch = right[i];
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

bool isSome(tree t1, tree t2)
{
    if(t1 == nullptr && t2 == nullptr)
        return true;
    if(t1 == nullptr && t2)
        return false;
    if(t1 && t2 == nullptr)
        return false;
    if(t1->data == t2->data)
        return (isSome(t1->left, t2->left) && isSome(t1->right, t2->right))
             || (isSome(t1->left, t2->right) && isSome(t1->right, t2->left));
    else
        return false;
}

int main()
{
    tree t1,t2;
    int n;
    cin >> n;
    t1 = createTree(n);
    cin >> n;
    t2 = createTree(n);
    if(isSome(t1, t2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}