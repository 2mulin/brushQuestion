/***************************************************************************
 * @date 2020/7/12
 * @author reddragon
 * @description: medium 全排列
 * 
 * 1. 暴力回溯
 * 回溯, 每次确定nums[i]的元素是谁
 * 时间复杂度：O(n*n!)          空间复杂度：O(n)
 * 
 * 2. STL
 * STL算法中有一个next_premutation()函数, 它可以用来求全排列
 * 时间复杂度：O(n*n!)          空间复杂度：O(n)
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void backTrack(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[i], nums[index]);
        backTrack(nums, index + 1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    backTrack(nums, 0);
    return ans;
}

/*利用next_permutation()函数求全排列
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    sort(nums.begin(), nums.end());
    do
    {
        ans.push_back(nums);
    }while (next_permutation(nums.begin(), nums.end()))
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
