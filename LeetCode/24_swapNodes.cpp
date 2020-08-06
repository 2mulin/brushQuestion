/*************************************************
 * @date 2020/6/19
 * @author reddragon
 * @description: 中等题，两两交换链表结点
 * 三个指针，迭代无脑换。注意细节就好了
 * 时间复杂度：O(N)   空间复杂度：O(1)
 ************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    // 如果是0或1个结点
    if (!head || !head->next)
        return head;
    // 两个结点以上
    ListNode *ans = head->next, *pre = nullptr;
    ListNode *p1 = head, *p2 = head->next;
    while (p1 && p2)
    {
        // 交换
        p1->next = p2->next;
        p2->next = p1;
        if (pre)
            pre->next = p2;
        // 前进
        pre = p1;
        p1 = p1->next;
        if (!p1)
            break;
        p2 = p1->next;
    }
    return ans;
}

int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);

    return 0;
}
