/**
 * @date 2022/7/27
 * @author 2mu
 * @brief medium 分数加减运算
 *
 * 1. 模拟
 * 写起来比较麻烦。
 * 看下题解，学习一下它的写法。
 * 
 * 官方题解还是写的比较棒，全部当作加法。加一个负数相当于减法了。
 *
 * 时间复杂度：O(n+logC)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <numeric>
#include <string>

using namespace std;

string fractionAddition(string expression)
{
    long long denominator = 0, numerator = 1; // 分子，分母
    int index = 0, n = expression.size();
    while (index < n)
    {
        // 读取分子正负号
        long long denominator1 = 0, sign = 1;
        if (expression[index] == '-' || expression[index] == '+')
        {
            sign = expression[index] == '-' ? -1 : 1;
            index++;
        }

        // 读取分子
        while (index < n && isdigit(expression[index]))
        {
            denominator1 = denominator1 * 10 + expression[index] - '0';
            index++;
        }
        denominator1 = sign * denominator1;
        index++;

        // 读取分母
        long long numerator1 = 0;
        while (index < n && isdigit(expression[index]))
        {
            numerator1 = numerator1 * 10 + expression[index] - '0';
            index++;
        }

        // 通分
        denominator = denominator * numerator1 + denominator1 * numerator; // 计算分子
        numerator *= numerator1;    // 分母相乘，就是新的分母
    }
    if (denominator == 0)
    {
        return "0/1";
    }
    // C++17 以上才有 std::gcd函数
    long long g = std::gcd(std::abs(denominator), numerator); // 获取最大公约数
    return to_string(denominator / g) + "/" + to_string(numerator / g);
}

int main()
{
    std::cout << fractionAddition("-1/2+1/2+1/3") << std::endl;
    return 0;
}
