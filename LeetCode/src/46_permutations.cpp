/***************************************************************************
 * @date 2020/7/12
 * @author reddragon
 * @description: hard 第46题:求全排列
 * 1. 暴力回溯
 * 回溯列出所有的可能，再排序
 * 时间复杂度：O(n*n!)  空间复杂度：O(n)
 * 
 * 2. stl
 * 好用的一批
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> ans;

void pre_son(const vector<int> &nums, vector<bool> &isVisit, vector<int> &temp, int index)
{
    if (index == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < isVisit.size(); i++)
    {
        if (isVisit[i])
            continue;
        else
        {
            isVisit[i] = true;
            temp[index++] = nums[i];
            pre_son(nums, isVisit, temp, index);
            isVisit[i] = false;
            index--;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.empty())
        return ans;
    int n = nums.size();
    // 标记数组
    vector<bool> isVisit(n, false);
    for (size_t i = 0; i < n; i++)
    {
        vector<int> temp(n, 0);
        isVisit[i] = true;
        temp[0] = nums[i];
        pre_son(nums, isVisit, temp, 1);
        isVisit[i] = false;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/*利用next_permutation()函数求全排列
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    sort(nums.begin(), nums.end());
    ans.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        ans.push_back(nums);
    }
    return ans;
}
*/

int main()
{
    vector<int> arr{1, 2, 3};
    vector<vector<int>> ans = permute(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << '\t';
        cout << endl;
    }
    return 0;
}
