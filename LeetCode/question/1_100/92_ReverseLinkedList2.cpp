/*********************************************************************
 * @author reddragon
 * @date 2020/8/13
 * @brief medium 反转链表2
 * 1.双指针
 * 这种题目看一眼就知道思路, 就是指针换来换去, 所以特别要注意指针的操作
 * 难点就是指针的操作, 逻辑请不清晰.
 * 记住做这种题目，最好使用画图的方式帮助理解，指针的操作也不容易错
 * 时间复杂度: O(N)     空间复杂度: O(1)
**********************************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;

    for (int i = 0; i < left - 1; ++i)
    {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next = nullptr;

    for (int i = 0; i < right - left; ++i)
    {
        next = cur->next;
        cur->next = next->next;

        next->next = pre->next;
        pre->next = next;
    }
    // head可能被反转了, 所以需要一个dummyNode一直呆在第一位
    return dummyNode->next;
}

/* 一刷
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (!head || m == n)
        return head;
    ListNode *node = new ListNode(-1); // 加一个头结点
    node->next = head;

    ListNode *p, *p1, *p2;
    p = p1 = p2 = node;
    for (int i = 0; i < m - 1; i++)
        p = p->next;
    // p在p1前一个
    p1 = p->next;
    for (int i = 0; i < n; i++)
        p2 = p2->next;

    // 反转：就是不断地将p1放在p2后面
    while (p1 != p2)
    {
        p->next = p1->next;
        p1->next = p2->next;
        p2->next = p1;

        p1 = p->next; //复位，以便下一次循环
    }
    // 这里没有释放node结点，leetcode会报错
    // head = node-next;delete node;
    return node->next;
} */

int main()
{
    return 0;
}