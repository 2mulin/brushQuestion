/*****************************************************************************
 * @author reddragon
 * @date 2021/3/27
 * @brief 旋转链表 medium
 * 
 * 1.两次循环
 * 先一次循环, 计算出链表长度, 并且把尾结点和头结点连接起来
 * 然后head向前移动len - (len%k)步, 就是新的头结点
 * 时间复杂度：O(N)         空间复杂度：O(1)
 *****************************************************************************/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
    int len = 1;// 链表长度
    // 找到尾结点
    ListNode* tail = head;
    while(tail->next)
    {
        tail = tail->next;
        ++len;
    }
    // 变成循环链表
    tail->next = head;
    int i = len - (k % len);
    while(--i)
    {
        head = head->next;
    }
    tail = head;
    head = head->next;
    tail->next = nullptr;
    return head;
}

int main()
{
    return 0;
}