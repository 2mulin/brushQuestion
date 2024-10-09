/**
 * @date 2022/8/7
 * @author 2mu
 * @brief medium 函数的独占时间
 *
 * 1. stack
 * 
 * 这里比较难处理的是如何记录时间，因为函数调用中间，可能会递归调用其他函数。
 * 题解的处理方法每次记录一小部分，然后更新时间戳，这样会方便记录后续的时间。
 *
 * 时间复杂度：O(N*N)   分析log也需要时间O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

std::vector<std::string> Split(std::string str, char sep)
{
    std::vector<std::string> words;
    std::string word;
    for(char ch : str)
    {
        if(ch == sep)
        {
            words.push_back(word);
            word.clear();
        }
        else
            word.push_back(ch);
    }
    if(!word.empty())
        words.push_back(word);
    return words;
}

vector<int> exclusiveTime(int n, vector<string> &logs)
{
    std::stack<std::pair<int,int>> st;
    std::vector<int> vctElapse(n, 0);
    for(auto log : logs)
    {
        std::vector<std::string> infos = Split(log, ':');
        if(infos[1] == "start")
        {
            int startTime = std::stoi(infos[2]);
            if(!st.empty())
            {
                vctElapse[st.top().first] += (startTime - st.top().second);
                st.top().second = startTime;
            }
            st.push({std::stoi(infos[0]), startTime});
        }
        else
        {
            int FuncNo = std::stoi(infos[0]);
            int endTime = std::stoi(infos[2]);
            vctElapse[FuncNo] += (endTime - st.top().second + 1);
            st.pop();
            if(!st.empty())
                st.top().second = endTime + 1;
        }
    }

    return vctElapse;
}

int main()
{
    return 0;
}
