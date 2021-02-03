/********************************************************************************************
 * @author reddragon
 * @date 2020/10/4
 * @brief medium 两数之和
 * 
 * 1.模拟
 * 模拟一下加法。题目给的条件非常好。链表每一位上的数直接加就好了。
 * 因为链表是倒序存放的，并且每一位都是一位数。
 * 时间复杂度：O(max(m,n))  空间复杂度：O(max(m,n))
 ********************************************************************************************/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(0); // 头结点
    ListNode *p = ans;

    int flag = 0; // 表示是否有进位
    while (l1 || l2 || flag)
    {
        int num = 0;
        num += flag;
        flag = 0;
        if (l1)
        {
            num += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            num += l2->val;
            l2 = l2->next;
        }
        if (num > 9)
        {
            flag = 1;
            num -= 10;
        }
        p->next = new ListNode(num);
        p = p->next;
    }
    return ans->next;
}

int main()
{
    return 0;
}