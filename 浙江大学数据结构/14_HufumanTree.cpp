/********************************************************************************************
 * @author reddragon
 * @date 2020/12/2
 * @brief Huffman编码
 * 
 * 1. Hufuman
 * 第一步：建一颗哈夫曼树，求出最小的wsl。以此比较其他所有的Hufuman编码是否正确。
 * 首先建立好所有的树，根据root的大小放到优先队列（最小堆）中。
 * 每次选出root最小的两颗树出来构造成一颗新树，放会优先队列中（最小堆）。
 * 直到hufuman树建完。
 * 第二步：由于哈夫曼树并不唯一，所以判断hufuman编码是否正确的方式
 * 1. wpl相等。
 * 2. 保证叶子节点都是正确的。
 * 上述2比较麻烦，使用最直接的方法：根据输入直接建立一个新树，一旦结点冲突，或者不为叶子就错了。
 * 最后写的根据用户Hufuman编码得到Hufuman Tree的函数最难。
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Tree{
    char ch;
    int data;
    Tree* left;
    Tree* right;
    Tree() = default;
    Tree(char _ch,int _data)
        :ch(_ch),data(_data),left(nullptr),right(nullptr)
    {};
};
// 函数对象,priority_queue要用
struct cmp{
    bool operator()(const struct Tree *t1, const struct Tree *t2)const
    {
        return t1->data > t2->data;
    }
};

// 根据HufumanTree计算带权路径长度和
int WPL(Tree* root, int depth = 1)
{
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return depth*root->data;
    else if(root->left && root->right == nullptr)
        return WPL(root->left, depth + 1);
    else if(root->left == nullptr && root->right)
        return WPL(root->right, depth + 1);
    else
        return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
}

// 根据每个结点的权值构造哈夫曼树
Tree* HufumanTree(const map<char,int> &ma)
{
    // 构建堆
    priority_queue<Tree*,vector<Tree*>,cmp> qu;
    for(auto i : ma)
    {
        qu.push(new Tree(i.first,i.second));
    }
    // 建树
    while(qu.size() > 1)
    {
        Tree* left = qu.top();
        qu.pop();
        Tree* right = qu.top();
        qu.pop();
        Tree *node = new Tree('0', left->data + right->data);
        node->left = left;
        node->right = right;
        qu.push(node);
    }
    return qu.top();
}

// 根据用户输入的hufuman编码建立hufuman树，不一定成功，因为编码可能是错的，失败返回nullptr
Tree* HufumanTree(map<char,int> &ma, int N)
{
    Tree *root = new Tree('s',-1);
    bool fail = false;
    for(int i = 0; i < N; ++i)
    {
        char ch;
        string path;
        cin >> ch >> path;
        Tree* p = root;
        for(size_t i = 0; i < path.size(); ++i)
        {
            if(path[i] == '1')
            {
                if(p->left == nullptr)
                    p ->left = new Tree('s', -1);                    
                p = p->left;
            }
            else
            {
                if(p->right == nullptr)
                    p->right = new Tree('s', -1);
                p = p->right;
            }
        }
        if(p->ch != 's')
            fail = true;
        else
        {
            p->ch = ch;
            p->data = ma[ch];
        }
    }
    if(fail)
        return nullptr;
    return root;
}

int main()
{
    int N;
    while(cin >> N)
    {
        char ch;
        int w;
        map<char,int> ma;
        for(int i = 0; i < N; ++i)
        {
            cin >> ch >> w;
            ma.insert(pair<char,int>(ch,w));
        }

        Tree *root = HufumanTree(ma);
        int wpl = WPL(root);
        int M;
        cin >> M;
        for(int i = 0; i < M; ++i)
        {
            Tree* root = HufumanTree(ma,N);
            int len = WPL(root);
            // 判断wpl是否相等
            if(wpl == len)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}