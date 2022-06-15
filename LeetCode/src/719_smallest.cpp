/**
 * @date 2022/6/15
 * @author 2mu
 * @brief hard 找出第K小的数对距离
 *
 * 1. 暴力枚举
 * 先理解题意，就是将数组中任意两个数，做差。全部记录下来，最后得到这个差值的第K小的数。
 * 题意理解了，接下来先是最简单的解法。暴力求解。根据组合数公式：从N个元素中任意取2个，总共有N*(N+1)/2种取法。
 * 枚举所有差值。
 * 
 * 时间复杂度：O(N*N)
 * 空间复杂度：O(N)
 * 
 * 2. 排序
 * 排序有什么好处？ 它要求的是最小差值，a-b的差值怎样会比较小，当然是a，b越接近越小。
 * 数组排序后，枚举数量可以减少很多。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/* 暴力枚举
int smallestDistancePair(vector<int> &nums, int k)
{
    std::priority_queue<int, vector<int>, std::greater<int>> diffs;
    for(size_t i = 0; i < nums.size(); ++i)
    {
        for(size_t j = i + 1; j < nums.size(); ++j)
        {
            int diff = abs(nums[i] - nums[j]);
            diffs.push(diff);
        }
    }
    for(int i = 1; i < k; ++i)
    {
        if(!diffs.empty())
            diffs.pop();
    }
    return diffs.top();
}
*/

int smallestDistancePair(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    // 没了，没看懂题解，为什么第K小的数一定在 [0,max(nums)−min(nums)] 内？？？？ 哎，二刷吧
}

int main()
{
    vector<int> nums{1,3,1};
    int k = 1;
    std::cout << smallestDistancePair(nums, k) << std::endl;
    return 0;
}
