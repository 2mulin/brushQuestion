/********************************************************************************************
 * @author reddragon
 * @date 2021/3/20
 * @brief medium 逆波兰表达式
 * 
 * 1. 栈
 * 利用逆波兰式的性质, 我们使用一个栈保存数字, 当碰到运算符的时候, 就从栈中弹出两个数字
 * 运算, 然后放回栈中. 
 * 时间复杂度: O(1)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> opd;
    for(int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == "+")
        {
            int num1 = opd.top(); opd.pop();
            int num2 = opd.top(); opd.pop();
            opd.push(num1 + num2);
        }
        else if(tokens[i] == "-")
        {
            int num1 = opd.top(); opd.pop();
            int num2 = opd.top(); opd.pop();
            opd.push(num2 - num1);
        }
        else if(tokens[i] == "*")
        {
            int num1 = opd.top(); opd.pop();
            int num2 = opd.top(); opd.pop();
            opd.push(num2 * num1);
        }
        else if(tokens[i] == "/")
        {
            int num1 = opd.top(); opd.pop();
            int num2 = opd.top(); opd.pop();
            opd.push(num2 / num1);
        }
        else
            opd.push(stoi(tokens[i]));
    }
    return opd.top();
}

int main()
{

    return 0;
}
