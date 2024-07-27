/**
 * @author ling
 * @date 2021/6/3
 * @brief medium 连续数组
 * 
 * 1. 前缀和
 * 找到最长子数组的长度(0和1的个数相等)，首先最简单的思路，确定字数组起点和终点，然后判断其中的
 * 0和1的个数是否相等，相等就记录下长度。遍历完所有子数组，就知道长度了。时间复杂度是O(N^3)。
 * 利用前缀和，可以减少最后计算0和1个数那层循环。
 * 时间复杂度：O(N^2)           空间复杂度：O(N)
 * 
 * 2. 前缀和 + 哈希表
 * 首先创建一个新数组sum，其中的0转化为-1，这样当子数组的和等于0时，说明子数组的0和1的个数相等。
 * 如i->j的前缀和就等于sum[j] - sum[i -1]。
 * 实际实现不需要真的创建新数组，使用一个变量，记录当前前缀和。使用哈希表记录之前的前缀和。
 * 使用哈希表保存（前缀和，当前下标）。
 * 时间复杂度：O(N)             空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int sz = nums.size();
    if( sz <= 1)
        return false;
    // 初始化哈希表，插入一个(0，-1)表示哈希表为空的时候
    unordered_map<int, int> ma;
    ma.insert(std::pair<int, int>(0, -1));
    // 前缀和
    int sum = 0;
    // 最终答案
    int ans = 0;
    for(int i  = 0 ; i < sz; ++i)
    {
        if(nums[i] == 0)
            sum -= 1;
        else
            sum += 1;
        if(ma.find(sum) != ma.end())
        {
            int len = i - ma[sum];
            ans = max(ans, len);
        }
        else
            ma[sum] = i;
    }
    return ans;
}

/* int findMaxLength(vector<int> &nums)
{
    // 前缀和
    int sz = nums.size();
    if (sz <= 1)
        return 0;
    vector<int> prefixZero(sz, 0), prefixOne(sz, 0);
    if (nums[0] == 0)
    {
        prefixOne[0] = 0;
        prefixZero[0] = 1;
    }
    else
    {
        prefixOne[0] = 1;
        prefixZero[0] = 0;
    }
    for (int i = 1; i < sz; ++i)
    {
        if (nums[i] == 0)
        {
            prefixZero[i] = prefixZero[i - 1] + 1;
            prefixOne[i] = prefixOne[i - 1];
        }
        else
        {
            prefixZero[i] = prefixZero[i - 1];
            prefixOne[i] = prefixOne[i - 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i + 1; j < sz; ++j)
        {
            int countOfOne = 0, countOfZero = 0;
            if (i == 0)
            {
                countOfZero = prefixZero[j];
                countOfOne = prefixOne[j];
            }
            else
            {
                countOfZero = prefixZero[j] - prefixZero[i - 1];
                countOfOne = prefixOne[j] - prefixOne[i - 1];
            }
            if (countOfOne == countOfZero)
                ans = max(ans, countOfOne * 2);
        }
    }
    return ans;
} */

int main()
{
    vector<int> nums{0,1,1,0,1,1,1,0};
    cout << findMaxLength(nums) << endl;
    nums = vector<int>{0,0,1,0,0,0,1,1};
    cout << findMaxLength(nums) << endl;
    return 0;
}