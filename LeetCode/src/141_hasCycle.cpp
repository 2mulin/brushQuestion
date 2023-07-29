/**
 * @date 2023/7/29
 * @author 2mu
 * @brief easy 环形链表
 * 
 * 1. 快慢指针
 * 使用快慢指针即可; 慢指针每次往前移动一个元素, 快指针每次往前移动两个元素;
 * 如果该链表有环, 那么最终两个指针会在环中相遇;
 * 如果无环, 那么链表尾部是NULL, 快指针会先一步到达链表尾部;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if(head == nullptr)
        return false;
    ListNode* fast = head->next, *slow = head;
    while(fast != slow)
    {
        // 这里还可以优化, 不需要判断slow指针, 因为如果不是环形链表, 则一定是 fast 指针先到尾部
        if(fast == nullptr || fast->next == nullptr || slow == nullptr)
            return false;
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}


int main()
{
    return 0;
}
