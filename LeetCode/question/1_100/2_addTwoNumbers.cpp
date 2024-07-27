/**
 * @date 2023/7/2
 * @author 2mu
 * @brief medium 两数相加
 *
 * 1. 模拟
 * 题目实际上看起来就是要求使用链表模拟数字加法; 链表每个节点只表示一位数字, 需要考虑向上进位
 * 恰巧数字是逆序排放, 只要遍历一遍, 按照进位规则将所有链表元素加起来就可以;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 返回ListNode内存没有释放, 不过刷题不考虑这些, 也不太好考虑...
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    ListNode* head = new ListNode(-1), *p1 = l1, *p2 = l2;
    ListNode* p3 = head;
    int num = 0; // 是否需要进位?
    while(p1 || p2)
    {
        if(p1 && p2)
        {
            int sum = p1->val + p2->val + num;
            p3->next = new ListNode(sum % 10);
            num = sum / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1)
        {
            int sum = p1->val + num;
            p3->next = new ListNode(sum % 10);
            num = sum / 10;
            p1 = p1->next;
        }
        else if(p2)
        {
            int sum = p2->val + num;
            p3->next = new ListNode(sum % 10);
            num = sum / 10;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(num)
        p3->next = new ListNode(num);
    return head->next;
}

int main()
{
    return 0;
}