/**
 * @author ling
 * @date 2021/3/26
 * @brief easy 棒球比赛
 *
 * 1. stack
 * 利用vector模拟栈。主要原因是“D”的操作，需要访问最后两个元素。而stack只能访问最后一个元素。
 * 时间复杂度：O(N)          空间复杂度: O(N)
 */

#include <iostream>
#include <vector>
#include <string>

int calPoints(std::vector<std::string> &ops)
{
    std::vector<std::string> st;
    for(auto str : ops)
    {
        if(str == "C")
            st.pop_back();
        else if(str == "D")
        {
            int num = std::stoi(st.back()) * 2;
            st.push_back(std::to_string(num));
        }
        else if(str == "+")
        {
            int num = std::stoi(st.back());
            num += std::stoi(st[st.size() - 2]);
            st.push_back(std::to_string(num));
        }
        else
            st.push_back(str);
    }
    int ans = 0;
    for(auto str : st)
        ans += std::stoi(str);
    return ans;
}

int main()
{
    std::vector<std::string> arr{"5","2","C","D","+"};
    std::cout << calPoints(arr) << std::endl;
    return 0;
}
