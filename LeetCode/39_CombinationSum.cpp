/****************************************************************************
 * @author reddragon
 * @date 2020/7/9
 * @description: medium
 * 
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。题目没说的是，数组的数一定是正数，不重复
 * 
 * dfs加一点优化，过了
 * 
 ****************************************************************************/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void dfs(const vector<int> &candidates, int index, int target, vector<int> nums, int sum)
{
    if (sum == target)
        ans.push_back(nums);
    else if (sum > target)
        return;
    else
    {
        for (int i = index; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > target) //优化
                break;
            nums.push_back(candidates[i]);
            dfs(candidates, i, target, nums, sum + candidates[i]);
            nums.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> nums(1, candidates[i]);
        dfs(candidates, i, target, nums, candidates[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums{2, 3, 6, 7};
    combinationSum(nums, 7);
    return 0;
}
