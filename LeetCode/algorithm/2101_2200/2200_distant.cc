/**
 * @date 2025/6/24
 * @author 2mu
 * @brief easy 找出数组中的所有 K 近邻下标
 *
 * 1. 遍历
 * 又是简单题，看题目就是遍历一遍数组，每个元素按照题目要求判断一下，
 * 如果满足条件，那就是1个 k近邻下标，如果不满足，那就不是。
 * 
 * 最后输出所有满足条件的下标。
 * 
 * 时间复杂度: O(n*k)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;


// 方法一
vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    std::vector<int> result;
    for(int i = 0; i < nums.size(); ++i)
    {
        int start = max(i - k, 0);
        int end = min(i + k, (int)nums.size() - 1);
        bool valid = false;
        for(int j = start; j <= end; ++j)
        {
            if (nums[j] == key)
            {
                valid = true;
                break;
            }
        }
        if (valid)
            result.push_back(i);
    }
    return result;
}


int main()
{
    std::vector<int> nums{3,4,9,1,3,9,5};
    auto result = findKDistantIndices(nums, 9, 1);
    for(auto elem : result)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
