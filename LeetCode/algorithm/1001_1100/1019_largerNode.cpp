/**
 * @date 2022/4/10
 * @author 2mu
 * @brief 链表中的下一个更大节点 medium
 *
 * 一. dfs
 * 看到题目的第一眼，我就想到了dfs。递归形式
 * 当前节点的 nextLargerNode 取决它的next 是不是大于当前节点，如果大于，那就是 next
 * 如果小于，那就是 next 的 nextLargerNode，或者 nextLargerNode 的。。。中一个比 当前节点大 的节点。
 * 
 * 如果最后为null，表示当前节点没有 nextLargerNode
 * 
 * 时间复杂度：O(n!)        n的阶乘
 * 空间复杂度：O(n)
 * 
 * 二. 遍历+stack
 * 第一种方法复杂度高，而且实现起来也比较费劲。
 * 
 * 先遍历整个List，使用stack记录ListNode和该节点在 ans 数组中的pos
 * 1. 当一个newNode需要入栈时，如果newNode->val > 栈顶topNode->val
 *      将栈顶topNode 出栈，并且将 newNode->val 写入到 ans 数组中topNode的位置。
 *  循环上述步骤，直到栈为空，或者newNode->val > 栈顶topNode->val条件不再满足。
 * 2. 将newNode压入stack
 * 3. 循环1，2步，直到List遍历完成。此时stack若是还有node，将他们的 ans 数组位置全部置为0
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

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

vector<int> nextLargerNodes(ListNode *head)
{
    std::vector<int> ans;
    std::stack<std::pair<ListNode*, size_t>> stListNode;
    int idx = 0;
    ListNode* tmp = head;

    // 原来这就是单调栈，栈中存在的元素都是单挑递减的。如果新元素比栈中元素大，就需要将栈中所有比它小的元素都删除
    while(tmp)
    {
        ans.push_back(0);
        while(!stListNode.empty())
        {
            std::pair<ListNode*, int> topNode = stListNode.top();
            if(topNode.first->val < tmp->val)
            {
                stListNode.pop();
                ans[topNode.second] = tmp->val;
            }
            else
                break;
        }
        stListNode.push({tmp, idx});
        tmp = tmp->next;
        ++idx;
    }
    return ans;
}

int main()
{
    ListNode node1(2);
    ListNode node2(1);
    ListNode node3(5);

    node1.next = &node2;
    node2.next = &node3;

    std::vector<int> ans = nextLargerNodes(&node1);
    for(auto num : ans)
    {
        std::cout << num << '\t';
    }
    return 0;
}
