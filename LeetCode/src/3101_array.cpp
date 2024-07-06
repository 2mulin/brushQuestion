/**
 * @date 2024/7/6
 * @author 2mu
 * @brief medium 交替子数组计数
 *
 * 1. 枚举
 * 首先计算出该数组的所有子数组, 然后判断每个子数组是否是交替子数组;
 * 最后输出交替子数组的个数;
 * 
 * 看题目意义, 这里是值的连续子数组; 所以遍历一次是O(n*n)
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(1)
 * 
 * 2. 找规律
 * 具体请看代码, 我也没想到这为什么会成立....
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;


long long countAlternatingSubarrays(vector<int> &nums)
{
    long long count = 0, cur = 0;

    if(nums.size() > 0)
    {
        count = 1;
        cur = 1;
    }
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] == nums[i - 1])
        {
            cur = 1;
        }
        else
        {
            cur += 1;
        }
        count += cur;
    }
    return count;
}


/**
 * @brief 模拟双层遍历, O(n*n) 提交会超时...
 */

/*
long long countAlternatingSubarrays(vector<int> &nums)
{
    int count = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        ++count;// 单独的nums[i]也是交替子数组
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[j] != nums[j - 1])
                ++count;
            else
                break;
        }
    }
    return count;
}
*/


int main(int argc, char **argv)
{
    return 0;
}

