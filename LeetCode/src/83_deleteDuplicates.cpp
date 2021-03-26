/*****************************************
 * @author reddragon
 * @date 2021/3/26
 * @brief easy 链表去重
 * 
 * 1. 一次遍历
 * 去重, 每个数字只出现一次
 * 先给链表加个头结点-1(好习惯, 防止头结点被删除)
 * 每次判断相邻的两个结点的val是否相等, 如果相等
 * 那就删除后面的那个结点.
 * 时间复杂度: O(N)     空间复杂度: O(1)
******************************************/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 二刷
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *prevHead = new ListNode(-1);
    prevHead->next = head;

    ListNode *curr = head, *prev = prevHead;
    while (curr)
    {
        while (curr->next && curr->next->val == curr->val)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        prev = curr;
        curr = curr->next;
    }
    return prevHead->next;
}

/* 一刷
ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return head;
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (p2)
    {
        if (p1->val != p2->val)
        {
            p1->next = p2;
            p1 = p1->next;
        }
        p2 = p2->next;
    }
    p1->next = nullptr;
    return head;
} */

int main()
{
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(2);

    ListNode *p = deleteDuplicates(&head);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }

    return 0;
}