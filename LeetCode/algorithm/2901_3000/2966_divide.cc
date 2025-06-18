/**
 * @date 2025/6/18
 * @author 2mu
 * @brief medium 划分数组并满足最大差限制
 *
 * 1. 排序+贪心
 * 和官方题解做出来一模一样，想要尽可能满足最大差值限制，显然就是让间隔小的元素尽量放在一起。
 * 那就可以直接对nums排序，然后依次取3个元素即可，并且判断3个元素中最大差值是否大于k
 * 
 * 由于排序了，3个元素的最大差值也很好算。
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());
    
    std::vector<std::vector<int>> result;
    std::vector<int> tmpArray;

    for(int i = 0; i < nums.size(); ++i)
    {
        if (tmpArray.size() == 3)
        {
            if (tmpArray.back() - tmpArray.front() > k)
                return {};
            result.push_back(tmpArray);
            tmpArray.clear();
        }
        tmpArray.push_back(nums[i]);
    }
    if (!tmpArray.empty())
    {
        if (tmpArray.back() - tmpArray.front() > k)
            return {};
        result.push_back(tmpArray);
    }
    return result;
}

int main()
{
    std::vector<int> nums{2,4,2,2,5,2};
    std::vector<std::vector<int>> result = divideArray(nums, 2);
    for(auto arr : result)
    {
        for (auto num : arr)
        {
            std::cout << num << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}
