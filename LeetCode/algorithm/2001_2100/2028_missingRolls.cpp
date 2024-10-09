/**
 * @author ling
 * @date 2021/3/27
 * @brief medium 找出缺失的数据
 *
 * 1. 模拟
 * 还是简单的模拟，主要有两点。1. 骰子只能有1~6这几个数字。所以diff < n或者diff > 6n ,就没有答案。
 * 2. 反过来说，就一定有答案。先大致求平均值，然后余数均分前几个就行了。 
 * 时间复杂度：O(N)          空间复杂度: O(N)
 */

#include <iostream>
#include <vector>
#include <string>


std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n)
{
    int missingSum = 0;
    for (auto num : rolls)
    {
        missingSum += num;
    }
    int diff = mean * (rolls.size() + n) - missingSum;

    if(diff > n * 6 || diff < n)
        return std::vector<int>();

    // 必须是1~6的数字，个数不能超过n，和必须是diff
    int quotient = diff / n;  // 近似值。
    int remainder = diff % n; // 余数
    std::vector<int> ans(n, quotient);
    for(int i = 0; i < remainder; ++i)
        ans[i] += 1;

    return ans;
}

int main()
{
    std::vector<int> arr{1,5,6};
    auto ans = missingRolls(arr, 3, 4);
    for(auto num : ans)
        std::cout << num << std::endl;
    return 0;
}
