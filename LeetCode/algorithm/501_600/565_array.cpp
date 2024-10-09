/**
 * @date 2022/7/17
 * @author 2mu
 * @brief medium 数组嵌套
 *
 * 1. 动态规划
 * 额外创建一个dp数组，该数组长度和nums一致，记录以该idx为起点满足条件的最大嵌套数组长度。
 * 
 * 则状态转移方程就是：dp[i] = max(dp[dp[i]] + 1, dp[i])
 * 
 * 同时dp数组还可以防止重复计算。
 * 
 * 时间复杂度：O(N * manLen)       manLen是最后返回的最大长度
 * 空间复杂度：O(N)
 * 
 * 2. 图
 * 也可以看成是一个图，且一定存在环。找的就是最长的环。做法还是一样的。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int arrayNesting(vector<int> &nums)
{
    std::unordered_set<int> IndexSet;
    std::vector<int> dp(nums.size(), 0);
    int result = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if(dp[i] != 0)
            continue;
        int currentIndex = i;
        // 直到集合中idx重复，结束循环
        while(IndexSet.find(currentIndex) == IndexSet.end())
        {
            IndexSet.insert(currentIndex);
            dp[currentIndex] = std::max((int)IndexSet.size(), dp[currentIndex]);
            currentIndex = nums[currentIndex];
        }
        result = (IndexSet.size() > result ? IndexSet.size() : result);
        IndexSet.clear();
    }
    return result;
}

int main()
{
    std::vector<int> arr{5,4,0,3,1,6,2};
    std::cout << arrayNesting(arr) << std::endl;
    return 0;
}
