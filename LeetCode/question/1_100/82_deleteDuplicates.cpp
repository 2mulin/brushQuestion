/*******************************************************************************
 * @author reddragon
 * @date 2020/8/8
 * @brief medium 删除链表中重复的元素
 * 1. 递归
 * 链表内去掉重复过的元素
 * 思路很简单，写起来非常麻烦，看到这个递归的解法，觉得非常棒
 * 
 * 2. 一次遍历
 * 在head之前的添加一个prevHead结点, 因为head可能会被删除
 * , 每次找出相等元素的区域, 全部删除
 * 时间复杂度: O(N)         空间复杂度: O(1)
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *prevHead = new ListNode(-1);
    prevHead->next = head;

    ListNode *prev = prevHead;
    ListNode *tmp = head;
    while (tmp)
    {
        ListNode *begin = tmp;
        while (tmp->next && tmp->next->val == tmp->val)
            tmp = tmp->next;
        ListNode *end = tmp;

        tmp = tmp->next;
        if (begin == end)
        {
            prev = end;
            continue;
        }

        prev->next = end->next;
        // 删除begin到end这一片相等的区域
        while (begin && begin != prev->next)
        {
            ListNode *tt = begin->next;
            delete begin;
            begin = tt;
        }
    }
    return prevHead->next;
}
/* 递归版本
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return head;
    if (head->next != NULL && head->val == head->next->val)
    { //找相同数
        while (head->next != NULL && head->val == head->next->val)
            head = head->next;               //忽略所有相同数
        return deleteDuplicates(head->next); //从下一个不同数再开始递归
    }
    else
        head->next = deleteDuplicates(head->next);
    return head;
} */

int main()
{
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(2);
    head.next->next->next = new ListNode(3);

    ListNode *p = deleteDuplicates(&head);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }

    return 0;
}