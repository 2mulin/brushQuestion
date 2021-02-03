/********************************************************************************************
 * @author reddragon
 * @date 2020/10/9
 * @brief easy 链表是否有环
 * 
 * 1. 哈希表
 * 把所有访问过的链表结点放到哈希表中，如果重复了，说明有环。
 * 时间复杂度：O(N)         空间复杂度：O(N)
 * 
 * 2. 快慢指针
 * 一个指针一次走一步，一个一次走两步，如果有环，最终一定会相遇
 * 时间复杂度：O(N)         空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希表
bool hasCycle(ListNode *head)
{
    unordered_set<ListNode *> seen;
    while (head != nullptr)
    {
        if (seen.count(head))
        {
            return true;
        }
        seen.insert(head);
        head = head->next;
    }
    return false;
}

// 快慢指针
bool hasCycle(ListNode *head)
{
    if (head == nullptr)
        return false;
    ListNode *p1 = head, *p2 = head->next;
    while (p1 && p2 && p2->next)
    {
        if (p1 == p2)
            return true;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return false;
}

int main()
{
    return 0;
}