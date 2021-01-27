/********************************************************************************************
 * @author reddragon
 * @date 2021/1/25
 * @brief easy 反转链表
 * 
 * 1.迭代版
 * 需要三个指针，从前往后，prev、curr、next，这样就能改变方向，
 * 并且迭代后移
 * 时间复杂度：O(n)			空间复杂度：O(1)
 * 
 * 2.递归版
 * 时间复杂度：O(n)         空间复杂度：O(n)
 ********************************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代版
ListNode *reverseList(ListNode *head)
{
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while(curr)
	{
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// 递归版
ListNode *reverseList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode* newHead = reverseList(head->next);
    newHead->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
	ListNode head(1), second(2), third(3);
	head.next = &second;
	head.next->next = &third;

	ListNode* ans = reverseList(&head);
	while(ans)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}