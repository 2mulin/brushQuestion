/*******************************************************************************
 * @author reddragon
 * @date 2020/8/10
 * @brief medium 链表
 * 关于链表的一道题，挺简单的，就是要认真，仔细，判断是否为nullptr。
 * 链表的题好像都这样。
 *******************************************************************************/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    if (!head)
        return head;

    // 记录小于x的结点的最后一个元素,-1是我设置的头结点
    ListNode *p = new ListNode(-1);
    p->next = head;
    ListNode *p1 = p;
    while (p1->next && p1->next->val < x)
        p1 = p1->next;

    // 从p1开始，p1->next要么是空，要么是第一个 >= x的结点
    ListNode *p2 = p1;
    while (p2->next)
    {
        if (p2->next->val < x)
        {
            ListNode *tmp = p2->next;
            p2->next = p2->next->next;
            // 将tmp插入到p1后面
            tmp->next = p1->next;
            p1->next = tmp;
            p1 = p1->next;
        }
        else
            p2 = p2->next;
    }
    // 释放内存好习惯
    // ListNode* tmp = p;
    // delete tmp;
    // tmp = NULL;
    // 不要头结点-1
    p = p->next;
    return p;
}

int main()
{
    ListNode head(1);
    head.next = new ListNode(4);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(2);
    head.next->next->next->next = new ListNode(5);
    head.next->next->next->next->next = new ListNode(2);

    ListNode *p = partition(&head, 3);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    return 0;
}