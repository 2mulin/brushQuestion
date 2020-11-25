/********************************************************************************************
 * @author reddragon
 * @date 2020/11/25
 * @brief 链表反转
 * 
 * 1.模拟
 * 非常复杂，不想再写了
 * 
 * 2.递归
 * 陈姥姥的链表反转还是有点东西的,不知道为什么题目改成这样，但是我还是有个样例过不了
 * 陈姥姥还是厉害,几天都没做出来
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    string addr;
    string data;
    string next;
    Node()
    {}
    Node(string _addr,string _data,string _next)
        :addr(_addr), data(_data), next(_next)
    {}
};

// 根据arr创建链表
vector<Node> ListCtreate(const vector<Node>& arr, string start)
{
    vector<Node> ls;
    bool isEnd = true;
    while(isEnd)
    { 
        Node temp;
        for(auto node : arr)
        {
            if(node.addr == start)
            {// 找到第一个结点
                temp.addr = node.addr;
                temp.data = node.data;
                temp.next = node.next;
                break;
            }
        }
        ls.push_back(temp);
        start = temp.next;
        if(start == "-1")
            isEnd = false;
    }
    return ls;
}

// 输出链表
void print(const vector<Node>& ls)
{
    for(auto node : ls)
        cout << node.addr << ' ' << node.data << ' ' << node.next << endl;
    return;
}

void ListRevers(vector<Node>& ls, size_t K)
{
    if(ls.size() == K)
    {
        reverse(ls.begin(), ls.end());
    }
    else if(ls.size() < K)
        return;
    else
    {
        auto left = ls.begin();
        while(left + K <= ls.end())
        {
            reverse(left, left + K);
            left = left + K;
        }
    }
    // 完成addr和next的反转
    auto it = ls.begin();
    for(it = ls.begin(); it != ls.end() - 1; ++it)
        it->next = (it+1)->addr;
    it->next = "-1";
    return;
}

int main()
{
    string start;
    int count, K;
    while(cin >> start >> count >> K)
    {
        vector<Node> arr;
        for(int i = 0 ;i < count; ++i)
        {
            string addr,data,next;
            cin >> addr >> data >> next;
            arr.push_back(Node(addr,data,next));
        }
        vector<Node> ls = ListCtreate(arr, start);
        ListRevers(ls, K);
        print(ls);
    }
    return 0;
}