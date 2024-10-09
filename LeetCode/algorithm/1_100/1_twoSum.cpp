/**
 * @date 2023/7/1
 * @author 2mu
 * @brief easy 两数之和
 *
 * 1. 哈希表
 * 重新刷一遍
 * 
 * 如果考虑有重复元素这一点, 还是比较难的, 因为如果3个重复元素, 则可以生成多种index的序列;
 * 但是题目给了限制, 只有一个答案; 所以就好做多了;
 * 
 * 官方题解给的程序更加棒, 因为它是遍历数组时, 将元素一个个加进哈希表的, 就不需要判断是否重复元素满足条件的情况; 
 * 
 * 代码更加高效, 优美; 看我下次不看题解能不能想到这种优美写法;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    std::unordered_multimap<int, int> hashMap;
    for(int i = 0; i < nums.size(); ++i)
    {
        hashMap.insert({nums[i], i});
    }

    std::vector<int> ans;
    for(auto iter = hashMap.begin(); iter != hashMap.end(); ++iter)
    {
        int diff = target - iter->first;
        auto iter2 = hashMap.find(diff);
        if(iter2 == hashMap.end())
            continue;
        
        if(iter2 != iter)
        {
            ans.push_back(iter->second);
            ans.push_back(iter2->second);
            return ans;
        }
        else
        {
            // 题目说只有一个答案, 所以只最多两个相同元素
            if(hashMap.count(diff) == 2)
            {
                auto range = hashMap.equal_range(diff);
                for(auto it = range.first; it != range.second; ++it)
                {
                    ans.push_back(it->second);
                }
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> ans = twoSum(nums, 9);
    for(auto pos : ans)
        std::cout << pos << ' ';
    std::cout << std::endl;

    nums = {3, 3};
    ans = twoSum(nums, 6);
    for(auto pos : ans)
        std::cout << pos << ' ';
    std::cout << std::endl;
    return 0;
}