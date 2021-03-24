/********************************************************************************************
 * @author reddragon
 * @date 2021/3/24
 * @brief medium 132模式 
 * 
 * 1. 暴力(3层循环)
 * 使用三层循环尝试所有的情况
 * 时间复杂度: O(n^3)               空间复杂度: O(1)
 * 
 * 2. 枚举
 * a, b ,c三个数满足a<c<b, 可以枚举b的位置, 然后取a-b之间的元素的最小值
 * 最后在b-c之间一个一个尝试c
 * 时间复杂度: O(n^2)               空间复杂度: O(1)
 * 
 * 3. 单调栈
 * 从后往前维护一个单调栈, 只要
*********************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

// 枚举b
bool find132pattern(vector<int> &nums)
{
    auto it = nums.begin();
    while(it != nums.end())
    {
        auto a = min_element(nums.begin(), it);
        if(a == it)
        {
            ++it;
            continue;// a为null
        }
        auto tmp = it + 1;
        while(tmp != nums.end())
        {
            if(*a < *it && *a < *tmp && *it > *tmp)
                return true;
            ++tmp;
        }
        ++it;
    }
    return false;
}

/*  暴力
bool find132pattern(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                if (nums[i] < nums[j] && nums[i] < nums[k] && nums[j] > nums[k])
                    return true;
            }
        }
    }
    return false;
} */

int main()
{
    vector<int> arr{1,2,3,4};
    cout << find132pattern(arr) << endl;
    return 0;
}