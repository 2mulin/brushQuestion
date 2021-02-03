/*********************************************************************
 * @author reddragon
 * @date 2020/8/13
 * @brief medium 反转链表2
 * 官方题解是递归和一个非递归
 * 但是我的这种方法也可以：双指针
 * 一个指针指向n前面的一个元素，一个指针指向第n个元素，一个指针指向第m个元素
 * 每次都把n放到m后面去，最终也可以
 * 
 * 记住做这种题目，最好使用画图的方式帮助理解，指针的操作也不容易错
**********************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (!head || m == n)
        return head;
    ListNode *node = new ListNode(-1); // 加一个头结点
    node->next = head;

    ListNode *p, *p1, *p2;
    p = p1 = p2 = node;
    for (int i = 0; i < m - 1; i++)
        p = p->next;
    // p在p1前一个
    p1 = p->next;
    for (int i = 0; i < n; i++)
        p2 = p2->next;

    // 反转：就是不断地将p1放在p2后面
    while (p1 != p2)
    {
        p->next = p1->next;
        p1->next = p2->next;
        p2->next = p1;

        p1 = p->next; //复位，以便下一次循环
    }
    // 这里没有释放node结点，leetcode会报错
    // head = node-next;delete node;
    return node->next;
}

int main()
{
    return 0;
}