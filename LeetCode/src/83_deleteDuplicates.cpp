/**
 * @date 2023/1/14
 * @author 2mu
 * @brief easy 删除排序链表的重复元素
 *
 * 1. 遍历
 * 遍历一遍即可, 因为题目说了链表已经排序好了, 那么重复元素一定是连续的, 所以很好删除;
 * 维护两个指针, 分别表示上一个元素, 当前元素; 只要当前元素和上一个元素相等, 那么当前元素即可删除;
 * 
 * 操作之前给链表加个头节点是否有必要? 实际上看自己的理解, 这里没啥必要....
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 三刷
ListNode *deleteDuplicates(ListNode *head)
{
    if(!head)
        return head;

    ListNode* prev = head, *curr = head->next;
    while(curr)
    {
        if(curr->val == prev->val)
        {
            prev->next = curr->next;
            // delete curr;
        }
        else
        {
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

/* 二刷
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
*/

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
    return 0;
}