/**
 * @author ling
 * @date 2021/6/2
 * @brief medium 
 * 
 * 1. 前缀和
 * 这里的子数组是连续的，并且长度至少为2。接下来遍历所有的可能性。
 * 需要三个循环，确定起点，终点，以及子数组和。时间复杂度O（N*N*N）
 * 使用前缀和可以降低复杂度，O（N*N）
 * 时间复杂度：O(N^2)           空间复杂度：O(N)
 * 
 * 2. 前缀和 + 哈希表 + 同余定理
 * 下次做吧。
 */

#include <iostream>
#include <vector>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    if(nums.size() < 2)
        return false;

    // 前缀和
    vector<int> tmp(nums);
    for (int i = 1; i < nums.size(); ++i)
        tmp[i] += tmp[i - 1];

    for (int i = 0; i < tmp.size(); ++i)
    {
        for (int j = i + 1; j < tmp.size(); ++j)
        {
            int sum = tmp[j];
            if (i != 0)
                sum -= tmp[i - 1];
            if (sum % k == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums{23,2,6,4,7};
    cout << checkSubarraySum(nums, 13) << endl;
    return 0;
}