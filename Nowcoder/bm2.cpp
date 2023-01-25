/**
 * @date 2022/1/25
 * @author 2mu
 * @brief medium 反转指定区间链表
 * 
 * 题目链接：https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c
 * 
 * 一、for循环非递归
 * 这种情况下写递归代码，非常麻烦。太多边界条件。这里直接使用普通反转链表的非递归思路。
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

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if(m == n)
        return head;//  反转一个元素，什么都不需要做

    ListNode* pre = nullptr;
    ListNode* curr = head;
    for(int i = 1; i < m; ++i)
    {
        pre = curr;
        curr = curr->next;
    }
    // 开始反转
    ListNode* left = nullptr, *right = nullptr;
    ListNode* pHead = nullptr, *pEnd = nullptr; // 记录反转之后的部分链表头和尾
    for(int i = m; i <= n; ++i)
    {
        ListNode* next = curr->next;
        if(i == m)
        {
            left = pre;// 记录一下
            pEnd = curr;
        }
        else if(i == n)
        {
            right = curr->next;// 记录边界
            curr->next = pre;
            pHead = curr;
        }
        else
            curr->next = pre;
        pre = curr;
        curr = next;
    }
    if(left)
    {
        left->next = pHead;
    }
    if(pEnd)
    {
        pEnd->next = right;
    }

    // 头节点是否变更？
    if(m == 1)
        return pHead;
    return head;
}

int main()
{
    ListNode *head= new ListNode();
    head->val = 1;
    head->next = new ListNode();
    head->next->val = 2;

    ListNode* tmp = head;
    while(tmp)
    {
        std::cout << tmp->val << '\t';
        tmp = tmp->next;
    }
    std::cout << std::endl;

    ListNode* newHead = reverseBetween(head, 1, 2);
    while(newHead)
    {
        std::cout << newHead->val << '\t';
        newHead = newHead->next;
    }
    return 0;
}
