/**
 * @date 2023/8/5
 * @author 2mu
 * @brief easy 合并两个有序链表 
 * 
 * 1. 遍历
 * 
 * 直接模拟, 同时遍历两个链表, 并且比较元素大小, 然后合并;
 * 官方题解说还可以用递归写, 优雅一些, 但是效率没有这种方式高;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode* newList = new ListNode(-1, NULL); // 头节点;
    ListNode* p = newList;
    while(list1 && list2)
    {
        if(list1->val <= list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2= list2->next;
        }
        p = p->next;
    }
    // 此时 list1 和 list2 最多不为NULL
    if(list1)
    {
        p->next = list1;
    }
    if(list2)
    {
        p->next = list2;
    }
    p = newList->next;
    delete newList;
    return p;
}


int main()
{
    return 0;
}
