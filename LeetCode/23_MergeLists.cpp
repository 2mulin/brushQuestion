/********************************************************
 * @date 2020/6/15
 * @author reddragon
 * @description: hard，合并k个已排序的链表为一个排序链表
 * 我使用的是暴力方法，每次遍历找出当前最小的元素。
 * 时间复杂度：O(k*k*n) 空间复杂度：O(1)
 * 
 * 优化。使用优先队列存链表头结点
 * 时间复杂度：O(k*n*logk) 空间复杂度：O(k)
 ********************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *ans = new ListNode(1);
    ListNode *p = ans;
    int min = 0; // 元素最小的索引
    while (min >= 0)
    {
        min = -1;
        for (int i = 0; i < lists.size(); i++)
        {
            if ((lists[i] != nullptr) && (min == -1 || lists[min]->val > lists[i]->val))
                min = i;
        }
        if (min >= 0)
        {
            p->next = lists[min];
            lists[min] = lists[min]->next;
            p = p->next;
        }
    }
    ans = ans->next; //第一个元素去掉，是我自己加的，不是本来就有的
    return ans;
}

int main()
{
    vector<ListNode *> arr;
    ListNode *p = new ListNode(1);
    p->next = new ListNode(4);
    p->next->next = new ListNode(5);

    arr.push_back(p);

    p = new ListNode(1);
    p->next = new ListNode(3);
    p->next->next = new ListNode(4);

    arr.push_back(p);

    p = new ListNode(2);
    p->next = new ListNode(6);

    arr.push_back(p);

    p = mergeKLists(arr);

    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    return 0;
}
