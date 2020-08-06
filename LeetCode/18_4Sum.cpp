/*************************************************
 * @date 2020/6/15
 * @author reddragon
 * @description: 中等题，四数之和
 * 还是双指针的解题思路，难点是避免重复
 ************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.size() <= 3)
        return ans;

    sort(nums.begin(), nums.end());
    int one, two, three, four;
    bool isExist = false;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            int low = j + 1, high = nums.size() - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[j] + nums[low] + nums[high];
                if (sum < target)
                    low++;
                else if (sum > target)
                    high--;
                else
                {
                    // 去重
                    if (!isExist || one != nums[i] || two != nums[j] || three != nums[low] || four != nums[high])
                    {
                        one = nums[i];
                        two = nums[j];
                        three = nums[low];
                        four = nums[high];
                        ans.push_back(vector<int>{nums[i], nums[j], nums[low], nums[high]});
                        isExist = true;
                    }
                    low++;
                    high--;
                }
            }
            while (j < nums.size() - 2 && nums[j] == nums[j + 1])
                j++;
        }
        while (i < nums.size() - 3 && nums[i] == nums[i + 1])
            i++;
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
