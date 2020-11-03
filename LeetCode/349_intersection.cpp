/********************************************************************************************
 * @author reddragon
 * @date 2020/11/3
 * @brief easy 两个数组的交集
 * 1. 去重，哈希表
 * 先对第一个数组去重，然后把第二个数组的所有元素都放在哈希表中（unordered_set也去重了），
 * for循环判断第一个数组的元素，在第二个数组中是否存在。
 * 排序时间比较多
 * 时间复杂度：O(NlogN)        空间复杂度：O(N)
 * 
 * 2. 排序+双指针
 * 时间差不多，比较省空间
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::unordered_set;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    // num1去重
    sort(nums1.begin(), nums1.end());
    auto last = unique(nums1.begin(), nums1.end());
    nums1.erase(last, nums1.end());

    // 哈希表查找快
    unordered_set<int> se;    
    for (int i = 0; i < nums2.size(); ++i)
    {
        se.insert(nums2[i]);
    }
    
    // 求交集
    vector<int> ans;
    for(auto num : nums1)
    {
        if(se.find(num) != se.end())
            ans.push_back(num);
    }
    return ans;
}

int main()
{
    vector<int> nums1{1,2,3,5,46,3,5};
    vector<int> nums2{1,2,5,3};

    vector<int> ans = intersection(nums1, nums2);
    for(auto num: ans)
        cout << num << std::endl;
    return 0;
}