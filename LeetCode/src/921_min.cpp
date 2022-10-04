/**
 * @date 2022/10/4
 * @author 2mu
 * @brief medium 使括号有效的最小减少
 *
 * 一. 栈的应用
 * 通过题目来看，首先要满足()相互匹配。可以利用栈。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 
 * 二. 贪心
 * 可以不使用stack，使用两个数字记录当前左括号个数，右括号个数。
 */

#include <iostream>
#include <string>
#include <stack>

int minAddToMakeValid(std::string s)
{
    std::stack<char> st;
    auto iter = s.begin();
    while(iter != s.end())
    {
        if(st.empty())
        {
            st.push(*iter);
            ++iter;
        }
        else
        {
            if(st.top() == '(' && *iter == ')')
            {
                st.pop();
            }
            else
            {
                st.push(*iter);
            }
            ++iter;
        }
    }
    return st.size();
}

int main()
{
    std::cout << minAddToMakeValid("())") << std::endl;
    std::cout << minAddToMakeValid("(((") << std::endl;
    return 0;
}
