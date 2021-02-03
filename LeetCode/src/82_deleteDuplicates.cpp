/*******************************************************************************
 * @author reddragon
 * @date 2020/8/8
 * @brief medium 
 * 链表内去掉重复过的元素
 * 思路很简单，写起来非常麻烦，看到这个递归的解法，觉得非常棒
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
}

int main()
{
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(2);
    head.next->next->next = new ListNode(3);

    ListNode* p = deleteDuplicates(&head);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    
    return 0;
}