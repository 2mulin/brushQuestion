/**
 * @date 2023/1/6
 * @author 2mu
 * @brief medium 在链表中插入最大公约数
 *
 * 1. 遍历
 * 通过题目, 只需要遍历一遍, 使用一个指针变量保留前一个链表节点prev;
 * 然后计算出 prev 和 curr 的最大公约数, 并且插入到链表中; 知道遍历完整个链表;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
//#include <numeric>  c++ 17才支持std::gcd

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* prev = head;
    ListNode* curr = head->next;
    while(curr)
    {
        int val = __gcd(prev->val, curr->val);
        ListNode* node = new ListNode(val);
        prev->next = node;
        node->next = curr;
        
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main()
{
    return 0;
}