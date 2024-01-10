/**
 * @date 2023/1/10
 * @author 2mu
 * @brief easy 删除子串后的字符串最小长度
 *
 * 1. 一次遍历
 * 最简单的想法就是不停的遍历, 删除AB,CD字符, 直到字符串中没有重复的AB或者CD字符串; 
 * 那么此时就说明已经是最小长度了; 返回;
 * 
 * 仔细一想, 使用一个stack即可, 遍历一遍字符串, 每碰到一个字符就判断, 当栈顶元素和当前元素
 * 能够组成AB或者CD时, 就删除栈顶元素, 跳过当前元素; 否则, 就将当前元素入栈;
 * 
 * 时间复杂度: O(m)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int minLength(string s)
{
    std::stack<char> st;
    for(char ch : s)
    {
        if(st.empty())
        {
            st.push(ch);
        }
        else
        {
            if((st.top() == 'A' && ch == 'B')
                || (st.top() == 'C' && ch == 'D'))
                st.pop();
            else
            {
                st.push(ch);
            }
        }
    }
    return st.size();
}

int main()
{
    std::cout << minLength("ABFCACDB") << std::endl;
    std::cout << minLength("ACBBD") << std::endl;
    return 0;
}