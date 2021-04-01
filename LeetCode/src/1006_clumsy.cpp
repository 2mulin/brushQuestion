/********************************************************************************************
 * @author reddragon
 * @date 2021/4/1
 * @brief medium 笨阶乘
 * 
 * 1，deque
 * 简单思路： 先乘法除法做完，优先级高。最后解决加减法。
 * 最开始想的是stack。但是发现stack在最后的加减法中顺寻不对，因为运算法则是从左往右
 * 于是就用queue，但是queue在乘法除法那里又有问题。
 * 最终发现deque才是最合适的。
 * 
 * 有一些小小的优化：由于是阶乘，所以数字都是正数，那么减法可以转变位加法。
 * 比如说1-2*3/4 等价于 1+(-2)*3/4, 这样做的好处是最好只要执行加法就OK，不需要判断加法还是减法
 * 时间复杂度: O(N)           空间复杂度: O(N)
 * 
 * 2. 数学
 * 数学推理：https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/
 * 时间复杂度: O(1)        空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <deque>
using namespace std;

int clumsy(int N)
{
    int opt = 0; // 0=乘法，1=除法，2=加法，3=减法
    deque<int> opts;// 乘法除法直接计算，加减法压入找中，最后计算
    deque<int> operands;
    operands.push_back(N);
    for (int i = N - 1; i > 0; --i)
    {
        switch (opt)
        {
            case 0:
            {
                int num = operands.back();
                operands.pop_back();
                operands.push_back(num * i);
                break;
            }
            case 1:
            {
                int num = operands.back();
                operands.pop_back();
                operands.push_back(num / i);
                break;
            }
            case 2:
            case 3:
                operands.push_back(i);
                opts.push_back(opt);
                break;
            default:
                cout << "error opt!" << endl;
                break;
        }
        opt++;
        opt %= 4;
    }
    while(!opts.empty())
    {
        int num1 = operands.front(); operands.pop_front();
        int num2 = operands.front(); operands.pop_front();
        if(opts.front() == 2)
            operands.push_front(num1 + num2);
        else
            operands.push_front(num1 - num2);// 顺序不能错
        opts.pop_front();
    }
    return operands.front();
}

int main()
{
    cout << clumsy(10) << endl;
    return 0;
}