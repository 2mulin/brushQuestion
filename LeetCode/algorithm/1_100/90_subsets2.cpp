/*******************************************************************************
 * @author reddragon
 * @date 2020/8/13
 * @brief medium 子集II
 * 1.枚举
 * 每次碰到一个数就是两种选择，要或者不要，可以写成尾递归。简单易懂，看代码
 * 难点要去重. 官方题解的去重很巧妙, 也很高效
 * 时间复杂度: O(n*2^n)         空间复杂度: O(n)
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> curr;
vector<vector<int>> ret;

// 枚举： 选或者不选
void dfs(const vector<int> &nums, int idx, bool choosePre)
{
    // 递归基
    if (idx >= nums.size())
    {
        ret.push_back(curr);
        return;
    }

    dfs(nums, idx + 1, false); // 不选
    if (!choosePre && idx > 0 && nums[idx - 1] == nums[idx])
    {
        // 加入序列 1, 1     可以避免1,null   null,1重复
        return; // 去重, !choosePre && nums[idx - 1] == nums[idx]的话说明这个数已经枚举过了
    }
    // 选
    curr.push_back(nums[idx]);
    dfs(nums, idx + 1, true);
    curr.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    // 这是去重的基本前提
    sort(nums.begin(), nums.end()); 
    dfs(nums, 0, false);
    return ret;
}

int main()
{
    vector<int> arr{1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(arr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << '\t';
        cout << endl;
    }
    return 0;
}