/***************************************************************************
 * @date 2020/7/13
 * @author reddragon
 * @description: hard 第350题:两个数组的交集
 * 1. 哈希表
 * 哈希表记录一个数组，num出现的次数，num作为key，count作为value
 * 在遍历另一个数组，作比较。
 * 时间复杂度：O(n+m)  空间复杂度：O(n)
 * 
 * 2. 先排序，双指针一次比较
 * 时间复杂度：O(nlogn + mlonm) 空间复杂度：O(n)
 * 
 * 3. stl
 * 好用的一批
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 哈希表记录num出现的次数，num作为key，count作为value
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int, int> hash;
    if (nums1.size() <= nums2.size())
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            hash[nums1[i]]++; //计数
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (hash.find(nums2[i]) != hash.end() && hash[nums2[i]] != 0)
            {
                ans.push_back(nums2[i]);
                hash[nums2[i]]--;
            }
        }
    }
    else
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            hash[nums2[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (hash.find(nums1[i]) != hash.end() && hash[nums1[i]] != 0)
            {
                ans.push_back(nums1[i]);
                hash[nums1[i]]--;
            }
        }
    }
    return ans;
}

/* C++自带算法求交集：std::set_intersection()
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(ans));
    return ans;
}
*/

/* 暴力，只要用在排序了  时间复杂度：O(nlogn) 空间复杂度：O(n)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums2[j]);
            i++;
            j++;
            continue;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
            i++;
    }
    return ans;
}
*/

int main()
{
    vector<int> nums1{1, 2, 3};
    vector<int> nums2{2, 2, 3, 6};
    vector<int> ans = intersect(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\t';
    }
    return 0;
}
