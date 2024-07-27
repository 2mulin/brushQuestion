/**
 * @date 2023/1/3
 * @author 2mu
 * @brief medium 从链表中移除节点
 *
 * 1. 递减链表
 * 看题目意思, 就是将链表中所有非递减的节点删除; 留下一个递减节点 链表;
 * 可以遍历一遍链表, 并且在遍历途中使用一个双端队列记录节点, 当碰到当前节点 大于 队列尾部节点;
 * 就将队列尾部节点删除...直到当前节点 小于 队列尾部节点
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *removeNodes(ListNode *head)
{
    std::deque<ListNode*> deq;
    deq.push_back(head);
    while(head->next)
    {
        ListNode* cur = head->next;
        while(!deq.empty() && cur->val > deq.back()->val)
        {
            deq.pop_back();
        }
        if(!deq.empty())
            deq.back()->next = cur;
        deq.push_back(cur);
        head = head->next;
    }
    if(deq.empty())
        head = NULL;
    else
        head = deq.front();
    return head;
}

int main()
{
    return 0;
}