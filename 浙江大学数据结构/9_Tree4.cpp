/********************************************************************************************
 * @author reddragon
 * @date 2020/11/28
 * @brief 是否是同一颗二叉搜索树
 * 
 * 1. 模拟
 * 按顺序建立好二叉树就行了。然后判断两棵树是否相等。
 * 时间复杂度：O(NlogN)结点数目
 * 2. 递归
 * 每次找到root,左右子树分别递归继续判断
 * 但每次找root也很麻烦.
 * 3. 建一棵树
 * 题目给出的第一颗树建立出来, 后面的序列的每一个数去第一棵树中查找,
 * 如果这个数字的路径不是当前数字前面的序列已经出现过了,那么就会失败.
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

tree CreateTree(int n)
{
    int num;
    cin >> num;
    tree root = new node(num);
    for(int i = 1; i < n; ++i)
    {
        cin >> num;
        tree tmp = root,next = root;
        bool LeftRight = true;
        do
        {
            tmp = next;
            if(num > tmp->data)
            {
                next = tmp->right;
                LeftRight = true;
            }
            else
            {
                next = tmp->left;
                LeftRight = false;
            }
        }while(next);
        if(LeftRight)
            tmp->right = new node(num);
        else
            tmp->left = new node(num);
    }
    return root;
}

bool isSome(tree t1, tree t2)
{
    if(t1 == nullptr && t2 == nullptr)
        return true;
    if(t1 && !t2)
        return false;
    if(!t1 && t2)
        return false;
    if(t1->data == t2->data)
        return isSome(t1->left, t2->left) && isSome(t1->right, t2->right); 
    else
        return false;
}

int main()
{
    int N,L;
    while(cin >> N)
    {
        if(N == 0)
            return 0;
        cin >> L;
        tree t = CreateTree(N);// 得到初始序列
        for(int i = 0; i < L; ++i)
        {
            tree t1 = CreateTree(N);
            if(isSome(t,t1))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}