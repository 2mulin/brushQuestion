/**
 * @date 2025/6/30
 * @author 2mu 
 * @brief easy 最长和谐子序列
 *
 * 1. 排序
 * 排序之后，遍历一遍，找到连续两个相同数字最长的。然后遍历排序后数组，
 * 不断移动first num和second num来统计差值为1时，first num和second num出现次数总和。
 * 
 * 写起来会稍微复杂一点点，需要注意边界条件。
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 * 
 * 2. map
 * 直接使用map，key为num，value为出现次数。最后遍历map，来统计相邻两个iter的first差值为1时，second之和的最大值。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int findLHS(vector<int> &nums)
{
    std::map<int, int> ma;
    for(auto num : nums)
    {
        ma[num]++;
    }

    int result = 0;
    for(auto iter = ma.begin(); iter != ma.end(); ++iter)
    {
        auto iter2 = std::next(iter);
        if (iter2->first - iter->first == 1)
        {
            result = std::max(result, iter2->second + iter->second);
        }
    }
    return result;
}


int main()
{
    std::vector<int> nums{1,3,2,2,5,2,3,7};
    std::cout << findLHS(nums) << std::endl;
    return 0;
}
