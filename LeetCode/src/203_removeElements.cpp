/**
 * @author ling
 * @date 2021/6/5
 * @brief easy 删除链表元素
 * 
 * 1. 遍历
 * 遍历一次,按顺序删除即可.
 * 时间复杂度：O(N)           空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *tmpHead = new ListNode(-1, head);
    ListNode *prev = tmpHead, *curr = head;
    while (curr)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
            ListNode* rmNode = curr;
            curr = curr->next;
            delete rmNode;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    ListNode* ret = tmpHead->next;
    delete tmpHead;
    return ret;
}

void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val << '\t';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    printList(head);
    ListNode* ans = removeElements(head, 6);
    printList(ans);
    return 0;
}