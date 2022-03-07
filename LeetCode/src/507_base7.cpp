/**
 * @author ling
 * @date 2021/3/7
 * @brief easy 7进制转化
 *
 * 1. 除7取余法
 * 循环做除法，除以7，直到除数为0。记录所有余数，并且最后倒序输出就OK了。
 * 需要注意负数。
 * 时间复杂度：O(N)       空间复杂度：O(1)
 */

#include <iostream>
#include <stack>
#include <string>

std::string func(int num)
{
    std::stack<char> st;
    while (num)
    {
        st.push(num % 7 + '0');
        num /= 7;
    }
    std::string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

std::string convertToBase7(int num)
{
    if (num == 0)
        return "0";
    if (num < 0)
        return "-" + func(-num);
    return func(num);
}

int main()
{
    return 0;
}