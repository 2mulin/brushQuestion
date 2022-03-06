/**
 * @author ling
 * @date 2021/3/6
 * @brief medium 最适合打劫的日子
 *
 * 1. 遍历
 * 按照要求，遍历每一个可能合法日子，判定一次是否合法。
 * 时间复杂度：O(N* 2time)       空间复杂度：O(1)
 *
 * 2. 记忆化搜索
 * 对于判断每一个日子是否合法，其实不用每次都重新判断，可以记录下来上次的结果。
 * 不管是递增还是递减，显然这种都是和前一个状态有关系。
 * 时间复杂度：O(3*N)       空间复杂度：O(2N)
 */

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> goodDaysToRobBank(std::vector<int> &security, int time)
{
    if(security.size() <= time * 2)
        return std::vector<int>();

    size_t sz = security.size();
    int count = 0;
    std::vector<bool> decreasing(sz, false);
    decreasing[0] = true;
    for(size_t i = 1; i < sz; ++i)
    {
        if(security[i - 1] >= security[i])
            count++;
        else
            count = 0;
        if(count >= time)
            decreasing[i] = true;
    }

    count = 0;
    std::vector<bool> increasing(sz, false);
    increasing[sz - 1] = true;
    for(int i = sz - 2; i >= 0; --i)
    {
        if(security[i] <= security[i + 1])
            count++;
        else
            count = 0;
        if(count >= time)
            increasing[i] = true;
    }

    std::vector<int> ans;
    for(size_t i = time; i < sz - time; ++i)
    {
        if(decreasing[i] && increasing[i])
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {1,1,1,1,1};
    std::vector<int> ans = goodDaysToRobBank(nums,0);
    for(auto i : ans)
        std::cout << i << '\t';
    std::cout << std::endl;
    return 0;
}