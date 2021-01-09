/********************************************************************************************
 * @author reddragon
 * @date 2021/1/9
 * @brief easy 最小栈 HOT一百题
 * 
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 1. 辅助栈
 * 利用一个辅助栈记录当前出现的最小值。
 ********************************************************************************************/
#include <stack>
using namespace std;


class MinStack {
private:
    stack<int> data;
    stack<int> min;

public:
    /** initialize your data structure here. */
    MinStack()
    : data(stack<int>()), min(stack<int>())
    {
    }
    
    void push(int x) {
        data.push(x);
        // 辅助栈记录最小值
        if(min.empty() || x < min.top())
            min.push(x);
        else
            min.push(min.top());
    }
    
    void pop() {
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */