/**
 * @date 2025/7/6
 * @author 2mu 
 * @brief medium 找出和为指定值下标对
 *
 * 1. 哈希表
 * 实际上题目非常像两数之和，所以很容易就会想到哈希表。
 * 一开始想歪了，是用哈希表记录nums1的val和idx，val可能重复，所以使用的multimap。
 * 但这样效率不高，会超时
 * 
 * 使用哈希表记录nums2中各个val的出现次数。即使改变了nums2数组，也只是修改一下哈希表出现次数。
 * count逻辑也很简单。
 * 
 * 时间复杂度：构造O(n), add是O(1), count是O(n)
 * 空间复杂度：忽略
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num : nums2){
            ++cnt[num];
        }  
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }
    
    int count(int tot) {
        int result = 0;
        for(int j = 0; j < this->nums1.size(); ++j)
        {
            int diff = tot - this->nums1[j];
            auto iter = this->cnt.find(diff);
            if (iter != this->cnt.end())
                result += iter->second;
        }
        return result;
    }
};


int main()
{
    return 0;
}
