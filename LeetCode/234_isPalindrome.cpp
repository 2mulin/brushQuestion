/********************************************************************************************
 * @author reddragon
 * @date 2021/2/2
 * @brief easy 回文链表
 * 
 * 1.将链表暂存到数组中
 * 存到数组中之后，就很判断了
 * 时间复杂度：O(n)		空间复杂度：O(n)
 * 
 * 2. 双指针
 * 快慢指针，快指针走两步，满指针走一步，最后快指针到末尾的时候，满指针在中间节点
 * 然后将后半部分链表反转。（我是觉得太麻烦了）
 * 时间复杂度：O(n)		空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
	vector<int> arr;
	while(head)
	{
		arr.push_back(head->val);
		head = head->next;
	}
	int len = arr.size();
	for(int i = 0; i < len; ++i)
	{
		if(arr[i] != arr[len - i - 1])
			return false;
	}
	return true;
}

int main()
{
	ListNode root(1);
	root.next = new ListNode(0);
	root.next->next = new ListNode(1);
	cout << isPalindrome(&root) << endl;
	return 0;
}