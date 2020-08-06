/**************************************************************************************
 * @author reddragon
 * @date 2020/6/7
 * @description: 双指针，难点是不好去重
 * 这题还是比较套路，和两数之和没什么关系，三个数等于0，
 * 所以说先排序，以当前点now开始，后面设置low=now和high=size-1，然后把三个数加起来
 * 大于0则high--，小于0则low++，最后当now大于0时候，后面的就没必要找了。三数之和必然大于0.
 *************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() <= 2)
        return ans;
    sort(nums.begin(), nums.end());
    // ans[i]为正数时，后面全部加起来肯定会大于0
    for (size_t i = 0; i < nums.size() - 2 && nums[i] <= 0; i++)
    {
        // 双指针
        size_t low = i + 1, hi = nums.size() - 1;
        while (low < hi)
        {
            int sum = nums[low] + nums[hi] + nums[i];
            if (sum < 0)
                low++;
            else if (sum > 0)
                hi--;
            else
            {
                ans.push_back({nums[i], nums[low], nums[hi]});
                // 去重
                low++;
                hi--;
            }
        }
        // 去重
        while (i < nums.size() - 2 && nums[i] == nums[i + 1])
            i++;
    }
    // 去重
    sort(ans.begin(), ans.end());
    for (size_t i = 1; i < ans.size(); i++)
    {
        if (ans[i][0] == ans[i - 1][0] && ans[i][1] == ans[i - 1][1] && ans[i][2] == ans[i - 1][2])
        {
            ans.erase(ans.begin() + i);
            i--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = threeSum(arr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << '\t';
        cout << endl;
    }
    return 0;
}