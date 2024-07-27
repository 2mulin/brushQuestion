/**
 * @date 2023/4/30
 * @author 2mu
 * @brief easy 满足目标工作时长的员工数目
 *
 * 1. 遍历
 * 
 * 过于简单, 这么简单的题目为什么也能上LeetCode...
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
{
    int count = 0;
    for (auto hour : hours)
    {
        if (hour >= target)
            ++count;
    }
    return count;
}

int main(int argc, char **argv)
{
    return 0;
}