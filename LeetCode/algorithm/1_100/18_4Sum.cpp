/**
 * @date 2023/7/15
 * @author 2mu
 * @brief medium 四数之和
 * 
 * 1. 排序 + 双指针
 * 还是双指针的解题思路，难点是避免重复, 题解的答案避免排序双指针重复比较好;
 * 而且还有剪枝, 我这里没写全剪枝方法;
 * 
 * 时间复杂度: O(n*n*n*)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.size() <= 3)
        return ans;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            break; // 剪枝, 后面都不可能有满足条件的答案了
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                break;
            
            // 双指针; 这里不能用哈希表, 因为建立一个哈希表的时间, 已经可以完成
            int low = j + 1, high = nums.size() - 1;
            while (low < high)
            {
                long long sum = nums[i] + nums[j] + nums[low] + nums[high];
                if (sum < target)
                    ++low;
                else if (sum > target)
                    --high;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                    // 去重
                    while(low < high && nums[low] == nums[low+1])
                        ++low;
                    ++low;
                    while(low < high && nums[high] == nums[high-1])
                        --high;
                    --high;
                }
            }
            while (j < nums.size() - 2 && nums[j] == nums[j + 1])
                ++j;
        }
        while (i < nums.size() - 3 && nums[i] == nums[i + 1])
            ++i;
    }

    return ans;
}


int main()
{
    vector<int> nums{-4, -1, 0, -5, -2, 5, 0, 2};
    vector<vector<int>> ans = fourSum(nums, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << '\t' << ans[i][1] << '\t' << ans[i][2] << '\t' << ans[i][3] << endl;
    }
    return 0;
}
