/**
 * @date 2025/1/30
 * @author 2mu 
 * @brief easy 两个数组的交集II
 * 
 * 1. 哈希表
 * 对两个数组取交集，需要注意的是如果同一个数字在数组中出现多次，则交集中也要出现多次。
 * 所以并不是普通的交集，要考虑数字出现次数。这里使用哈希表记录数字出现次数。
 * 
 * 这里的数组长度小于1000，数组元素大小小于1000。可以考虑直接使用桶计数就行。
 * 
 * 时间复杂度：O(n)  空间复杂度：O(n)
 * 
 * 2. 排序 + 双指针
 * 很有意思的思路，代码会更加清晰。
 * 
 * 时间复杂度：O(nlogn)  空间复杂度：O(n)
 */

#include <iostream>
#include <vector>

using namespace std;


vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    std:vector<int> bucket1(1001, 0), bucket2(1001, 0);
    for(int i = 0; i < nums1.size(); ++i)
    {
        int num = nums1[i];
        ++bucket1[num];
    }
    
    for(int i = 0; i < nums2.size(); ++i)
    {
        int num = nums2[i];
        ++bucket2[num];
    }

    std::vector<int> result;
    for(int i = 0; i < 1001; ++i)
    {
        int min_size = std::min(bucket1[i], bucket2[i]);
        while (min_size >= 1)
        {
            result.push_back(i);
            --min_size;
        }
    }
    return result;
}


int main()
{
    std::vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};
    std::vector<int> result = intersect(nums1, nums2);
    for(auto num : result)
        std::cout << num << '\t';
    std::cout << std::endl;
    return 0;
}
