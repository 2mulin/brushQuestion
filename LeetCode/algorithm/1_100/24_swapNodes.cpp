/**
 * @date 2023/8/6
 * @author 2mu
 * @brief medium 两两交换链表中的节点 
 * 
 * 1. 迭代
 * 一般链表操作都是两种, 递归或者迭代; 递归写出来代码优雅易懂, 但是空间复杂度高;
 * 迭代写出来代码比较难懂, 但是占用空间相对较少;
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

// 递归实现
// istNode *swapPairs(ListNode *head)
// {
//     if(head == nullptr || head->next == nullptr)
//         return head;
    
//     ListNode* newHead = head->next;
//     head->next = swapPairs(newHead->next);
//     newHead->next = head;
//     return newHead;
// }


ListNode *swapPairs(ListNode *head)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode* newList = new ListNode(-1, head->next); // 头节点;

    ListNode* p = head;
    ListNode* curr = head, *next = head->next;
    while(next)
    {
        p = next->next;

        next->next = curr;
        if(p && p->next)
            curr->next = p->next;
        else
            curr->next = p;

        curr = p;
        if(p)
            next = p->next;
        else
            next = NULL;
    }
    p = newList->next;
    delete newList;
    return p;
}


int main()
{
    return 0;
}
