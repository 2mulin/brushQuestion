/*****************************************
 * @author reddragon
 * @date 2020/8/8
 * @brief easy 链表去重
 * 双指针
******************************************/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
}

int main()
{
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(2);

    ListNode* p = deleteDuplicates(&head);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    
    return 0;
}