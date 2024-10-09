/**
 * @date 2022/6/18
 * @author 2mu
 * @brief medium 排序的循环列表
 *
 * 1. 模拟
 * 实际上题目是把单链表当成循环链表了，我只需要模拟循环链表进行一次遍历，然后将元素插入到第一个不小于的结点之前就完事了。
 *
 * 第一步. 找到起点。第二步，遍历。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 *
 */

#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal)
{
    if (head == nullptr)
    {
        Node *newNode = new Node(insertVal);
        newNode->next = newNode;
        return newNode;
    }

    // 找到最小元素
    Node *prev = head, *min_element = head->next;
    while (min_element != head)
    {
        if (prev->val > min_element->val)
            break;
        else
        {
            prev = min_element;
            min_element = min_element->next;
        }
    }
    Node *newNode = new Node(insertVal);
    if (prev == min_element)
    {
        // 只有一个节点
        newNode->next = min_element;
        min_element->next = newNode;
    }
    else
    {
        Node *p = min_element;
        while (p)
        {
            if (p->val >= insertVal)
            {
                prev->next = newNode;
                newNode->next = p;
                break;
            }
            else
            {
                prev = p;
                // 防止insertVal是最大的，需要插入到末尾
                if (p->next == min_element)
                {
                    p->next = newNode;
                    newNode->next = min_element;
                    break;
                }
                p = p->next;
            }
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(3);
    node1->next = new Node(4);
    node1->next->next = new Node(1);
    node1->next->next->next = node1;

    Node *ans = insert(node1, 2);
    std::cout << ans->val << std::endl;
    return 0;
}
