/**
 * @date 2025/6/28
 * @author 2mu 
 * @brief easy 找到和最大的长度为 K 的子序列
 *
 * 1. 排序
 * 根据元素大小排序，排序完之后，还需要保留之前顺序，也就是之前的idx。
 * 很自然的想到map。
 * 
 * 官方题解差不多，也是这种写法。
 * 
 * 我这里是两层遍历，所以时间复杂度是 O(n*k)
 * 如果是排序，时间复杂度只有O(nlogn)
 * 
 * 时间复杂度: O(n*k)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> maxSubsequence(vector<int> &nums, int k)
{
    std::map<int, int> ma;
    for(int i = 0; i < k; ++i)
    {
        int idx = -1;
        for(int j = 0; j < nums.size(); ++j)
        {
            if (ma.find(j) != ma.end())
                continue;
            if (idx == -1)
                idx = j;
            if (nums[j] > nums[idx])
                idx = j;
        }
        ma.insert({idx, nums[idx]});
    }
    std::vector<int> result;
    for(auto iter = ma.begin(); iter != ma.end(); ++iter)
    {
        result.push_back(iter->second);
    }
    return result;
}


int main()
{
    std::vector<int> nums{3,4,9,1,3,9,5};
    auto result = maxSubsequence(nums, 2);
    for(auto elem : result)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
