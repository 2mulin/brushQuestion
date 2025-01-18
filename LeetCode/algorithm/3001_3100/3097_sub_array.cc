/**
 * @date 2025/1/18
 * @author 2mu
 * @brief medium 或值至少k的最短子数组II
 *
 * 1. 枚举
 * 注意是非空子数组，也就是至少1个元素，且是连续的数组元素
 * 从子数组长度为1开始枚举，枚举到子数组长度为nums原长度，如果这都没有
 * 说明没有
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 滑动窗口
 * 该题目相比于3095题，本题数字范围加大。普通的枚举O(n*n)无法通过。
 * 必须使用滑动窗口。这里数字不断增加，多数字的按位或值只会不断增加，满足单调性。
 * 可以使用滑动窗口。难点在于窗口减小时，如何减小 按位或值（肯定不能遍历一遍窗口所有数字重新计算，那太耗时了）
 * 可以统计32位bit，每位1出现的次数
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>


using namespace std;


int minimumSubarrayLength(vector<int> &nums, int k)
{
    if (k == 0)
    {
        if (nums.size() > 0)
            return 1;
        else
            return 0;
    } 

    int or_value = 0, min_len = INT_MAX;
    std::deque<int> deq;
    std::vector<int> bit_count(32, 0);

    int idx = 0;
    while(idx < nums.size())
    {
        if(or_value < k)
        {
            int num = nums[idx];
            ++idx;

            deq.push_back(num);
            or_value |= num;
            for(int i = 0; i < 32; ++i)
            {
                if (num & (1 << i))
                    ++bit_count[i];
            }
        }
        while(or_value >= k)
        {
            if ( min_len > deq.size())
                min_len = deq.size();

            // 缩小窗口
            int current_num = deq.front();
            deq.pop_front();

            // 缩小or值
            or_value = 0;
            for(int i = 0; i < 32; ++i)
            {
                if (current_num & (1 << i))
                    --bit_count[i];

                if (bit_count[i])
                    or_value = or_value + (1 << i);
            }
        }
    }

    if (min_len == INT_MAX)
        return -1;
    return min_len;
}


int main()
{
    std::vector<int> nums = {2,25,32,1};
    std::cout << minimumSubarrayLength(nums, 59) << std::endl;
    return 0;
}
