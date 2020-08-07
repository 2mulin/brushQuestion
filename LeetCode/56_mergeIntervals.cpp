/************************************************************
 * @date 2020/7/19
 * @author reddragon
 * @brief 合并区间 medium
 * 先将数组排序，然后依次判断相邻的区间是否可以合并。
 * 主要是排序的时间，合并是O(n)
 * 时间复杂度：O(nlogn)  空间复杂度：O(n)
************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    for (auto it = intervals.begin(); it != intervals.end() - 1; it++)
    {
        // 当前可能需要合并的区间
        int L = it->operator[](0);
        int R = it->operator[](1);
        if (ans.empty() || ans.back().operator[](1) < L)
            ans.push_back(*it);
        else
        {
            // vector<int> temp(2);
            // temp[0] = ans.back()[0];
            // 确定右边界
            // temp[1] = max(R,ans.back()[1]);
            // ans.back() = temp;
            // 通过观察上面的代码，实际上只是替换了ans最后元素的右边界值
            ans.back()[1] = max(R, ans.back()[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr;
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp(2, rand() % 10);
        arr.push_back(temp);
    }
    return 0;
}