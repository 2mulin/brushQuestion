/**
 * @author ling
 * @date 2021/3/8
 * @brief medium 蜡烛之间的盘子
 *
 * 1. 前缀和
 * 注意不是一个前缀和数组解决的，总共3个前缀和数组。
 * 时间复杂度：O(N)       空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <string>

std::vector<int> platesBetweenCandles(std::string s, std::vector<std::vector<int>> &queries)
{
    size_t len = s.length();
    std::vector<int> preSum(len);// 前缀和，记录盘子前面有多少个蜡烛。
    int num = 0;
    for(size_t i = 0; i < len; ++i)
    {
        if(s[i] == '*')
            ++num;
        preSum[i] = num;
    }

    std::vector<int> leftIdx(len);
    int idx = -1;// '|'的位置
    for(size_t i = 0; i < len; ++i)
    {
        if(s[i] == '|')
            idx = i;
        leftIdx[i] = idx;
    }

    std::vector<int> rightIdx(len);
    idx = -1;
    for(int i = len - 1; i >= 0; --i)
    {
        if(s[i] == '|')
            idx = i;
        rightIdx[i] = idx;
    }

    std::vector<int> ans;
    for(auto query : queries)
    {
        int right = leftIdx[query[1]];
        int left = rightIdx[query[0]];
        if(right == -1 || left == -1 || left > right)
            ans.push_back(0);
        else
            ans.push_back(preSum[right] - preSum[left]);
    }
    return ans;
}

int main()
{
    std::string str = "**|**|***|";
    std::vector<std::vector<int>> arr{{2,5}, {5,9}};
    auto ans = platesBetweenCandles(str, arr);
    for(auto i : ans)
        std::cout << i << '\t';
    return 0;
}