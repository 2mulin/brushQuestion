/*******************************************************************************
 * @author reddragon
 * @date 2020/8/13
 * @brief medium 子集II
 * 穷举：可以再草稿纸上画出解空间树。很清晰，每一个起点就是一个新的解空间树
 * 就是和平常生活中做排列使用的方法一个道理
 * 每次碰到一个数就是两种选择，要或者不要，可以写成尾递归。简单易懂，看代码
 * 难点要去重。几行也可以解决问题
 * 这种形式的递归是尾递归吧（不确定）
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backTrace(vector<vector<int>> &ans, size_t pos, const vector<int> &nums, vector<int> tmp)
{
    if (pos >= nums.size())
    {
        ans.emplace_back(tmp);
        return;
    }
    if (!tmp.empty() && pos - 1 >= 0)
        if (tmp.back() == nums[pos] && nums[pos - 1] == nums[pos])
        { // 去重操作，当pos的数字与pos - 1重复时，pos的数字一定要选。不然...nums[pos]和...nums[pos - 1]重复
            tmp.emplace_back(nums[pos]);
            backTrace(ans, pos + 1, nums, tmp);
            return;
        }
    // 两种选择，不要该数字
    backTrace(ans, pos + 1, nums, tmp);
    // 或者要该数字。
    tmp.emplace_back(nums[pos]);
    backTrace(ans, pos + 1, nums, tmp);
    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
    {
        vector<int> tmp;
        tmp.emplace_back(nums[i]);
        backTrace(ans, i + 1, nums, tmp);
    }
    // 加上空集
    ans.emplace_back(vector<int>());
    return ans;
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