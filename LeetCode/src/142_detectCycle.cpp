/********************************************************************************************
 * @author reddragon
 * @date 2021/2/8
 * @brief medium 环形链表2
 * 
 * 1. 哈希表
 * 使用unordered_multiset保存所有链表结点, 如果插入的时候, 发现节点已经存在, 那么说明这就是重复的
 * 那个节点.
 * 时间复杂度: O(N)				空间复杂度: O(N)哈希表
 * 
 * 2. 双指针
 * 我们都知道双指针可以找到重复节点
 * 首先找到利用快慢指针可以得到一个快慢指针的相遇点, 再创建一个新的指针指向0, 新指针和slow每次各走
 * 一步, 最终相遇时, 就是圆环的起点.
 * 时间复杂度: O(N)				空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <dataStruct.h>
using namespace std;

// 双指针
ListNode *detectCycle(ListNode *head)
{
	ListNode* p1 = head, *p2 = head;
	do{
		if(p2 == nullptr || p2->next == nullptr)
			return nullptr;
		p1 = p1->next;
		p2 = p2->next->next;			
	}while(p1 != p2);
	// 利用公式得出的结论
	ListNode* newPtr = head;
	while(newPtr != p1)
	{
		newPtr = newPtr->next;
		p1 = p1->next;
	}
	return newPtr;
}

// 哈希表
// ListNode *detectCycle(ListNode *head)
// {
// 	unordered_set<ListNode*> set;
// 	while(head)
// 	{
// 		if(set.find(head) != set.end())
// 			return head;
// 		set.insert(head);
// 		head = head->next;
// 	}
// 	return nullptr;
// }

int main()
{
	long long tm1 = getTime();

	// 不测试了, 链表难建

	long long tm2 = getTime();
	cout << "消耗时间: " << tm2 - tm1 << "毫秒" << endl;
	return 0;
}