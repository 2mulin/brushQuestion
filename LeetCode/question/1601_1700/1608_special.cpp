/**
 * @date 2022/9/12
 * @author 2mu 特殊数组的特征值
 * @brief
 *
 * 一. 枚举
 * 题目条件 0 < nums[i] < 1000, 先考虑使用枚举, 说明x的值一定也是[0, 1000]的范围
 * 所以从0到1000枚举x的值, 试试哪一个值满足条件
 *
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 *
 * 二. 计数排序
 * 用一个数组记录nums中每个数出现的次数, 然后统计
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

int specialArray(vector<int> &nums)
{
    std::vector<int> counter(1001, 0);
    for (auto num : nums)
    {
        ++counter[num];
    }

    // 实际分析一下, 答案不可能是0的.
    int count = 0;
    for (int x = 1000; x > 0; --x)
    {
        count += counter[x];
        if (count == x)
            return x;
    }
    return -1;
}

/*
// 枚举
int specialArray(vector<int> &nums)
{
    for(int x = 0; x < 1001; ++x)
    {
        int count = 0;
        for(auto num : nums)
        {
            if(num >= x)
                count++;
        }
        if(count == x)
            return x;
    }
    return -1;
}
*/

int main()
{
    return 0;
}
