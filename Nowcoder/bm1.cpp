/**
 * @date 2022/1/25
 * @author 2mu
 * @brief easy 反转链表
 * 
 * 题目链接：https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca
 * 
 * 一、链表反转
 * 
 * 链表反转两种方式，一种递归，但是需要O(n)空间。实际上就是记录所有的节点，最后将指针都反过来。
 * 一种非递归，循环。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
};


// ListNode *ReverseList(ListNode *pHead)
// {
//     if(!pHead)
//         return pHead;
//     if(!pHead->next)
//         return pHead;
//     ListNode* pHeadNext = pHead->next;

//     pHead->next = nullptr;
//     ListNode* newHead = ReverseList(pHeadNext);
//     if(pHeadNext)
//         pHeadNext->next = pHead;
//     return newHead;
// }


ListNode *ReverseList(ListNode *pHead)
{
    ListNode *curr = pHead;
    ListNode *pre = nullptr;
    while (curr)
    {
        ListNode *currNext = curr->next;
        curr->next = pre;
        pre = curr;
        curr = currNext;
    }
    return pre;
}

int main()
{
    ListNode* lst = new ListNode();
    lst->val = 1;
    lst->next = new ListNode();
    lst->next->val = 2;
    lst->next->next = new ListNode();
    lst->next->next->val = 3;

    ListNode* tmp = ReverseList(lst);;
    while(tmp)
    {
        std::cout << tmp->val << '\t';
        tmp = tmp->next;
    }
    return 0;
}
