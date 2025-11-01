/**
 * @date 2025/11/1
 * @author 2mu
 * @brief medium 从链表中移除在数组中存在的节点
 *
 * 1. 哈希表+链表操作
 * 使用哈希表记录nums，然后遍历链表，每次判断当前链表元素值是否存在于哈希表中。
 * 如果存在就删除该链表节点。另外使用1个额外ListNode标记头结点的前一个，方便删除节点逻辑。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    std::unordered_set<int> numSets(nums.begin(), nums.end());
    ListNode *fakeNode = new ListNode();
    fakeNode->next = head;

    ListNode *preNode = fakeNode;
    while (head)
    {
        if (numSets.find(head->val) != numSets.end())
        {
            head = head->next;
            preNode->next = head;
        }
        else
        {
            preNode = head;
            head = head->next;
        }
    }
    ListNode *result = fakeNode->next;
    delete fakeNode;
    return result;
}

int main()
{
    ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    std::vector<int> nums = {1, 2, 3};
    modifiedList(nums, &node1);
    std::cout << node1.val << std::endl;
};