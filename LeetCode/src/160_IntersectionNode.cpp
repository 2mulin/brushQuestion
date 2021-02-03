/********************************************************************************************
 * @author reddragon
 * @date 2021/1/14
 * @brief easy 相交链表
 * 
 * 1，暴力
 * 双层循环遍历一遍，每两个节点判断是否相等，相等就输出，不相等就继续比较。
 * 时间复杂度：O(m*n)       空间复杂度：O(1)
 * 
 * 2. 哈希表
 * 先用一个保存一个链表的所有节点，然后遍历另一个链表的时候，检查哈希表中是否有重复的
 * 有就输出
 * 时间复杂度：O(n)         空间复杂度：O(n)
 * 
 * 3. 双指针
 * 两个指针分别指向两个链表的首结点，A指针沿着链表A走到末尾之后，指向B的头结点，再继续走到底，
 * B指针沿着链表B走到末尾之后，在指向A的头结点，再继续走到底。
 * 如果中途AB相等，那就是有交点，否则，就是没有。
 * 
 * 如果相交，那么最终会走到同一个节点，因为走过的长度是一样的。否则，两个指针都会走到null结点
 * 时间复杂度：O(m + n)         空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 暴力做法
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
// {
//     ListNode* pA = headA, *pB = NULL;
//     while(pA)
//     {
//         pB = headB;
//         while(pB)
//         {
//             if(pB == pA)
//                 return pA;
//             pB = pB->next;
//         }
//         pA = pA->next;
//     }
//     return NULL;
// }

//  哈希表法
// ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     unordered_set<ListNode*> s;
//     while(headA)
//     {
//         s.insert(headA);
//         headA = headA->next;
//     }
//     while(headB)
//     {
//         // 有重复，返回
//         if(s.find(headB) != s.end())
//             return headB;
//         headB = headB->next;
//     }
//     return nullptr;
// }

// 双指针
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA,*b = headB;
    bool isChA = true, isChB = true;
    while(a && b)
    {
        if(a == b)
            return a;
        else
        {
            a = a->next;
            b = b->next;
        }
        if(a == nullptr && isChA)
        {
            a = headB;
            isChA = false;
        }
        if(b == nullptr && isChB)
        {
            b = headA;
            isChB = false;
        }
    }
    return nullptr;
}

int main()
{
    return 0;
}