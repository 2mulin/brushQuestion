/**
 * @date 2024/7/29
 * @author 2mu
 * @brief easy 棒球比赛
 *
 * 1. 模拟
 * 按照规则模拟即可，因为可以取消上次成绩，所以需要额外创建数组记录每次的得分。
 * 防止被取消多次。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calPoints(vector<string> &operations)
{
    int result = 0;
    std::vector<int> scores;
    int current_score = 0;
    for(const std::string& operation : operations)
    {
        if(operation == "+")
        {
            int len = scores.size();
            current_score = scores.back() + scores.at(len - 2);
        }
        else if(operation == "D")
        {
            current_score = scores.back() * 2;
        }
        else if(operation == "C")
        {
            result -= scores.back();
            scores.pop_back();
            continue;
        }
        else
        {
            current_score = stoi(operation);
        }

        result += current_score;
        scores.push_back(current_score);
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<std::string> operations{"5","2","C","D","+"};
    std::cout << calPoints(operations) << std::endl;
    return 0;
}

