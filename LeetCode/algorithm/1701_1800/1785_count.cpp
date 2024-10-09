/**
 * @date 2022/12/17
 * @author 2mu
 * @brief middle 数组...
 * 
 * 一. 计算就是了
 * 题目看起来名字挺长，挺唬人。一看简直就是初学者的题目。
 * 
 * 主要注意题目数字大小，即求和sum是否会越界。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minElements(vector<int> &nums, int limit, int goal)
{
    long long sum = 0;
    for(auto num : nums)
        sum += num;
    long long diff = abs(goal - sum);// 离目标还差多少
    int ans = diff / limit;
    // 向上取整
    if (diff % limit)
        return ans + 1;
    return ans;
}

int main()
{
    std::vector<int> nums{1, -1, 1};
    std::cout << minElements(nums, 3, -4) << std::endl;
    return 0;
}
