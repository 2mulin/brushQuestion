/*****************************************************************************
 * @author reddragon
 * @date 2020/7/23
 * @brief 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 思路：先将链表变成循环链表。然后确定新的header
 * len - k%len - 1
 * 时间复杂度：O(N)  空间复杂度：O(1)
 *****************************************************************************/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || k == 0 || !head->next)
        return head;
    ListNode *p = head;
    int len = 1;
    while (p->next)
    {
        p = p->next;
        len++;
    }
    p->next = head; // 连接成循环链表
    int num = len - k % len - 1;
    //
    while (num--)
        head = head->next;
    p = head;
    head = head->next;
    p->next = NULL;
    return head;
}

int main()
{
    return 0;
}