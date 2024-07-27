/**
 * @author ling
 * @date 2021/10/6
 * @brief easy 第三大的数字
 * 
 * 1. 排序+去重
 * 时间复杂度: O(NlogN)         空间复杂度: O(N)
 * 
 * 2. 有序集合(set)
 * 用set的好处, 他自动去重了, 接下来只要考虑拿到最大的三个数。所以说就是如果只要出现
 * 超过三个数，我们就把最小的那一个数字删除。
 * 时间复杂度: O(N)          空间复杂度: O()
 * 
 * 3. 维护三个数字，最大到第三大。
 * 时间复杂度: O(N)          空间复杂度: O()
 */

#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
/* 
int thirdMax(vector<int>& nums)
{
    set<int> numset;
    for(auto num : nums)
    {
        numset.insert(num);
        if (numset.size() > 3)
            numset.erase(numset.begin()); // 删除最小的那个元素
    }
    
    return numset.size() == 3 ? *numset.begin() : *numset.rbegin();
}
 */

int thirdMax(vector<int>& nums) {
    if(nums.empty())
        return 0;
    long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
    for (auto num : nums)
    {
        if (num == a || num == b || num == c)
            continue;
        if(num > c)
        {
            a = b;
            b = c;
            c = num;
        }
        else if(num > b)
        {
            a = b;
            b = num;
        }
        else if(num > a)
            a = num;
        else
            continue;
    }
    if (a == LONG_MIN)
        return static_cast<int>(c);           // 第三大的数不存在，返回最大值。
    return static_cast<int>(a);               // 返回第三大的值。
}

int main()
{
    vector<int> nums1{2,2,3,1};
    vector<int> nums2{1,2};
    vector<int> nums3{3,2,1};
    std::cout << thirdMax(nums1) << endl;
    std::cout << thirdMax(nums2) << endl;
    std::cout << thirdMax(nums3) << endl;
    return 0;
}