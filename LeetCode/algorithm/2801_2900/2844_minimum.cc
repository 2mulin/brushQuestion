/**
 * @date 2024/7/25
 * @author 2mu
 * @brief medium 生成特殊数字的最少次数
 *
 * 1. 枚举
 * 简单思路, 枚举每一种情况, 题目说明num数字长度最大为100;
 * 那么最多有多少种情况呢? 字符串中出现的每个数字都有两种选择, 删除, 或者留下;
 * 
 * 即2的len次方种, 最多2的100次方种; 显然枚举会超时
 * 
 * 时间复杂度: O(2的n次方)
 * 空间复杂度: O(1)
 * 
 * 2. 贪心
 * 仔细分析下, 能够被25整除的数字, 该数字末尾肯定是 25, 50, 75, 00这几种, 或者数字0
 * 遍历数组, 找到这几个数字, 然后根据idx枚举这几种情况, 得到删除次数最少的情况
 * 
 * 可以看下题解, 实际上不需要O(n)空间复杂度去维护, 只需要记录下位置即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int minimumOperations(string num)
{
    int count = num.length();
    std::unordered_map<int, std::vector<int>> target_idx;
    for(int i = 0; i < num.length(); ++i)
    {
        if (num[i] == '0' || num[i] == '2'
            || num[i] == '5' || num[i] == '7')
        {
            int n = num[i] - '0';
            target_idx[n].push_back(i);
        }
    }

    // 00
    for(int i = 1; i < target_idx[0].size(); ++i)
    {
        int left_idx = target_idx[0][i - 1], right_idx = target_idx[0][i];
        int current_count = right_idx - left_idx - 1 + (num.length() - right_idx - 1);
        count = std::min(count, current_count);
    }

    // 25
    for(int i = 0; i < target_idx[2].size(); ++i)
    {
        for(int j = 0; j < target_idx[5].size(); ++j)
        {
            int idx_2 = target_idx[2][i], idx_5 = target_idx[5][j];
            if(idx_2 < idx_5)
            {
                int current_count = idx_5 - idx_2 - 1 + (num.length() - idx_5 - 1);
                count = std::min(count, current_count);
            }
        }
    }

    // 50
    for(int i = 0; i < target_idx[5].size(); ++i)
    {
        for(int j = 0; j < target_idx[0].size(); ++j)
        {
            int idx_5 = target_idx[5][i], idx_0 = target_idx[0][j];
            if(idx_5 < idx_0)
            {
                int current_count = idx_0 - idx_5 - 1 + (num.length() - idx_0 - 1);
                count = std::min(count, current_count);
            }
        }
    }

    // 75
    for(int i = 0; i < target_idx[7].size(); ++i)
    {
        for(int j = 0; j < target_idx[5].size(); ++j)
        {
            int idx_7 = target_idx[7][i], idx_5 = target_idx[5][j];
            if(idx_7 < idx_5)
            {
                int current_count = idx_5 - idx_7 - 1 + (num.length() - idx_5 - 1);
                count = std::min(count, current_count);
            }
        }
    }

    // 删除到只剩下一个0
    if(count == num.length() && target_idx[0].size() > 0)
    {
        return count - 1;
    }
    return count;
}

int main(int argc, char **argv)
{
    std::cout << minimumOperations("2908305") << std::endl;
    std::cout << minimumOperations("2245047") << std::endl;
    std::cout << minimumOperations("1000") << std::endl;
    std::cout << minimumOperations("1075") << std::endl;
    return 0;
}

