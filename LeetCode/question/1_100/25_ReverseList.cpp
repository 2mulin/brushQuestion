/*******************************************************************************
 * @date 2020/6/20
 * @author reddragon
 * @description: hard 链表反转
 * 没什么说的就是要考虑仔细。
 * 本题的目标非常清晰易懂，不涉及复杂的算法，
 * 但是实现过程中需要考虑的细节比较多，容易写出冗长的代码。主要考察面试者设计的能力。
 ******************************************************************************/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k <= 1)
        return head;
    stack<ListNode *> s;
    ListNode *p = head, *p1 = nullptr, *p2 = nullptr;
    for (int j = 0;; j++)
    {
        for (int i = 0; i < k && p; i++)
        {
            s.push(p);
            p = p->next;
        }
        if (s.size() != k)
            break;
        if (p1)
            p1->next = s.top();

        // 反转
        p1 = s.top();
        s.pop();
        if (j == 0)
            head = p1;
        while (!s.empty())
        {
            p2 = s.top();
            s.pop();
            p1->next = p2;
            p1 = p2;
        }
        p1->next = p;
    }
    return head;
}

int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);

    p = reverseKGroup(p, 2);
    while (p)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    return 0;
}
