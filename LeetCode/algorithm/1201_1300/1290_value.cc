/**
 * @date 2025/7/14
 * @author 2mu 
 * @brief easy 二进制链表转整数
 * 
 * 1. 模拟
 * 按照要求进行模拟，顺序遍历，累计数字和，从0开始。
 * 每次遍历就将原来累计的数字左移1位，就扩大两倍。然后加上当前节点的value
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int getDecimalValue(ListNode* head) {
    int num = 0;
    while(head)
    {
        num = (num << 1) + head->val;
        head = head->next;
    }
    return num;
}


int main()
{
    std::cout << getDecimalValue(NULL) << std::endl;
    return 0;
}
