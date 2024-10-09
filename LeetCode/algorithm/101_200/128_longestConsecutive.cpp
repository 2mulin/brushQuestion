/********************************************************************************************
 * @author reddragon
 * @date 2020/10/4
 * @brief hard 最长连续序列
 * 
 * 1. 枚举
 * 对于数组中的每一个数，查看以它为起点的每一个段连续的序列 的长度 给计算出来。
 * 找到最大的那个长度。
 * 时间复杂度：O(N*N)       空间复杂度：O(N)
 * 
 * 枚举优化
 * 加一个判断，当前选出的起点i是在i-1这个数不存在时，才去尝试计算它的长度。
 * 省去很多无用的枚举
 * 时间复杂度：O(N)         空间复杂度：O(N)
 * 
 * 2. 并查集
 * 显而易见，可以使用并查集，将每一个连续的序列放在同一个集合内，最后查看所有的集合的大小，
 * 选出最大的。
 * 
 * 但是代码量应该有点多
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 枚举
int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    // 哈希表加快查找
    unordered_set<int> num_set;
    for (auto i : nums)
        num_set.insert(i);
    int ans = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        // 避免重复的枚举           精髓所在
        if (num_set.find(nums[i] - 1) != num_set.end())
            continue;
        // 找到最远的终点j
        int j = nums[i] + 1;
        while (num_set.find(j) != num_set.end())
            j++;

        ans = max(ans, j - nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr{100, 4, 200, 3, 1, 2};
    cout << longestConsecutive(arr) << endl;
    return 0;
}