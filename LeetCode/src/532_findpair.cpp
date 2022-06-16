/**
 * @date 2022/6/16
 * @author 2mu
 * @brief medium 数组中的k-diff数对
 *
 * 1. 暴力枚举
 * 先理解题意，就是将数组中任意两个数，做差，找到差值等于k的对 有多少个。
 * 暴力求解。根据组合数公式：从N个元素中任意取2个，总共有N*(N+1)/2种取法。
 * 枚举所有差值。
 * 
 * 时间复杂度：O(N*N)
 * 空间复杂度：O(N)
 * 
 * 2. 哈希表
 * 使用哈希表去重。等于k的两种情况：num[i] - num[j] == k 或者 num[j] - num[i] == k
 * 也就是说，知道k值和一个num[i]，剩下一个num[j]的大小就是已知的了。
 * 
 * 所以一个哈希表存储数组元素，然后上述两种情况比较。而且num存在哈希表中，可以加速查找。O(1)
 * 
 * 时间复杂度: O(N)
 * 空间复杂度：O(N)
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
// 暴力枚举(超时了)
int findPairs(vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());
    int result = 0;
    for(size_t i = 0; i != nums.size(); ++i)
    {
        if(i >= 1 && nums[i] == nums[i - 1])
            continue;
        for(size_t j = i + 1; j < nums.size(); ++j)
        {
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            if(nums[i] - nums[j] == k || nums[j] - nums[i] == k)
                ++result;
        }
    }
    return result;
}
*/

/* // 我的丑陋代码
int findPairs(vector<int>& nums, int k)
{
    unordered_set<int> setNums;
    unordered_set<int> setRes;

    // k == 0的情况必须特判
    int zero = 0;
    for(auto num : nums)
    {
        if(setNums.count(num) && !setRes.count(num))
        {
            ++zero;
            setRes.insert(num);
            continue;
        }
        setNums.insert(num);
    }
    if(k == 0)
        return zero;

    setRes.clear();
    for(auto num : nums)
    {
        int expectation = k + num;  // 第一种：expectation - num == k
        if(setNums.count(expectation))
            setRes.insert(expectation);
        expectation = num - k;      // 第二种：num - expectation == k
        if(setNums.count(expectation))
            setRes.insert(num);
    }
    return setRes.size();
}
*/


// leetcode的完美代码
int findPairs(vector<int>& nums, int k)
{    
    unordered_set<int> setNums;
    unordered_set<int> res;// res实际上最后就是setNums的子集，res并不是完整k-diff对所有数，少了一个。
    for (auto num : nums)
    {
        int expectation = k + num;  // 第一种：expectation - num == k
        if(setNums.count(expectation))
            res.insert(expectation);
        expectation = num - k;      // 第二种：num - expectation == k
        if(setNums.count(expectation))
            res.insert(num);
        setNums.insert(num);
    }
    return res.size();
}


int main()
{
    vector<int> nums{1,2,4,4,3,3,0,9,2,3};
    int k = 3;
    std::cout << findPairs(nums, k) << std::endl;
    return 0;
}
