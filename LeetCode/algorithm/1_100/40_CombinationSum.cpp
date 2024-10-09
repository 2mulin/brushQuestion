/***************************************************************************
 * @date 2020/7/9
 * @author reddragon
 * @description: medium 组合总和
 * 上一题的改版，数字不可以无限使用，数组给的数字可能重复。
 * 只要注意去重就好了，也是dfs。
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

// 注意nums是个引用，真的可以加速好多。
void dfs(const vector<int> &candidates, int target, int index, vector<int> &nums, int sum)
{
    if (sum == target)
        ans.push_back(nums);
    else if (sum > target)
        return;
    else
    {
        for (int i = index; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > target)
                break;
            nums.push_back(candidates[i]);
            dfs(candidates, target, i + 1, nums, sum + candidates[i]);
            nums.pop_back();
            // 去重
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                i++;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> nums(1, candidates[i]);
        dfs(candidates, target, i + 1, nums, candidates[i]);
        //去重
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;
    }
    return ans;
}

int main()
{
    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    combinationSum2(nums, 8);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << '\t';
        }
        cout << '\n';
    }
    return 0;
}
