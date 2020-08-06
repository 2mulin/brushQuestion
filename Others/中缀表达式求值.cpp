
// (1+2^3!-4)*(5!-(6-(7-(89-0!))))=2013     一个测试用例

#include <iostream>
#include <cmath> //pow()计算乘方
#include <stack>
using std::cin;
using std::cout;
using std::stack;

//大于号表示当前运算符的优先级高于栈顶运算符，小于号则相反
//符号相同栈顶优先级高，因为按顺序计算（先来后到）
const char pri[9][9] =
    {
        //	^是乘方，！是阶乘,输入'\n'表示表达式输入完毕,' '空格表示不可能出现的情况
        //				当前运算符
        //  '+', '-', '*', '/', '^', '!', '(', ')', '\n'
        '<', '<', '>', '>', '>', '>', '>', '<', '<', // '+'
        '<', '<', '>', '>', '>', '>', '>', '<', '<', // '-'
        '<', '<', '<', '<', '>', '>', '>', '<', '<', // '*' 栈
        '<', '<', '<', '<', '>', '>', '>', '<', '<', // '/' 顶
        '<', '<', '<', '<', '<', '>', '>', '<', '<', // '^' 运
        '<', '<', '<', '<', '<', '<', '>', '<', '<', // '!' 算
        '>', '>', '>', '>', '>', '>', '>', '=', ' ', // '(' 符
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // ')'
        '>', '>', '>', '>', '>', '>', '>', '>', '='  // '\n'
};

//得到对应字符在运算符优先级表的下标
inline int getIndex(const char op)
{
    switch (op)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    case '!':
        return 5;
    case '(':
        return 6;
    case ')':
        return 7;
    case '\n':
        return 8;
    default:
        cout << "输入运算符错误！优先级表没有此运算符";
        exit(-1);
        break;
    }
    return -1;
}

//得到一个一元运算符计算结果
inline float Calculation(float num, char op)
{
    if (op == '!') //阶乘计算
    {
        float ans = 1;
        for (int i = 1; i <= num; i++)
        {
            ans *= i;
        }
        return ans;
    }
    else
        cout << "错误位置：!计算" << std::endl;
    return -1;
}

//得到一个二元运算符计算结果
inline float Calculation(float num1, char op, float num2)
{
    switch (op)
    {
    case '+':
        return num2 + num1;
    case '-':
        return num2 - num1;
    case '*':
        return num2 * num1;
    case '/':
        return num2 / num1;
    case '^':
        return pow(num2, num1);
    default:
        cout << "需要计算的运算符错误：Calculation()函数";
        break;
    }
    exit(-1);
    return 0;
}

//中缀表达式求值
float evaluate()
{
    stack<float> opnd; //操作数栈
    stack<char> optr;  //运算符栈
    optr.push('\n');
    //逐个处理运算符栈，直到栈为空
    while (!optr.empty())
    {
        char ch = cin.get(); //读	入输入流的第一个字符

        if (isdigit(ch)) //如果是数字，则需要读入操作数，否则读入操作符
        {
            cin.putback(ch); //将字符放回流中，直接cin读取操作数
            float num;
            cin >> num;
            opnd.push(num);
            continue;
        }
        if (ch == ' ' || ch == '\t') //过滤空格和tab
            continue;
        int x = getIndex(optr.top()), y = getIndex(ch);
        if (pri[x][y] == '>') //当前运算符优先级高
        {
            optr.push(ch); //当前运算符直接入栈
            continue;
        }
        while (pri[x][y] == '<') //栈顶运算符优先级高的时候
        {
            char op = optr.top();
            optr.pop();
            x = getIndex(optr.top());
            if (op == '!') //一元运算符处理
            {
                float num = opnd.top();
                opnd.pop();
                float ans = Calculation(num, op);
                opnd.push(ans);
            }
            else //二元运算符处理
            {
                float num1 = opnd.top();
                opnd.pop();
                float num2 = opnd.top();
                opnd.pop();
                float ans = Calculation(num1, op, num2);
                opnd.push(ans);
            }
        }
        //运算处理完，判断当前符号是不是'\n'，是的话结束，不是的话，将当前运算符入栈
        if (ch == '\n' || ch == ')')
            optr.pop();
        else
            optr.push(ch);
    }
    return opnd.top();
}

int main()
{
    float ans = evaluate();
    cout << '=' << ans;
    return 0;
}