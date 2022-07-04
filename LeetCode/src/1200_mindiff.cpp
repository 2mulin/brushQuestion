/**
 * @date 2022/7/4
 * @author 2mu
 * @brief easy 最小绝对差
 *
 * 1. 排序
 * 排序喽，然后数组中两个元素的最小绝对值差，显然就是两个大小最接近的数做差喽。也就是相邻的数做差。
 * 假设数组长度为N，那么就存在n-1个差值，全部算出来，然后记录差值和index。最后将最小值的全部遍历出来。
 * 
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    size_t sz = arr.size();
    std::vector<int> diff(sz - 1, 0);
    int minNum = INT_MAX;
    for(int i = 0; i < diff.size(); ++i)
    {
        diff[i] = abs(arr[i + 1] - arr[i]);
        minNum = min(minNum, diff[i]);
    }

    vector<vector<int>> results;
    for(int i = 0; i < diff.size(); ++i)
    {
        if(diff[i] == minNum)
        {
            results.push_back({arr[i], arr[i+1]});
        }
    }
    return results;
}

int main()
{
    std::vector<int> arr{4,2,1,3};
    minimumAbsDifference(arr);
    return 0;
}
