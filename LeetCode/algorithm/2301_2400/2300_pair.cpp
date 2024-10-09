/**
 * @date 2023/11/10
 * @author 2mu
 * @brief medium 咒语和药水的成功对数
 *
 * 1. 遍历
 * 最简单的方式, 2分钟解决; 但是效率不高;
 *
 * 时间复杂度: O(n * m)
 * 空间复杂度: O(n)
 * 
 * 2. 前缀和数组
 * 由于 1 <= spells[i], potions[i] <= 1e5 这个条件, 可以开辟一个大空间 arr[100000], valgrind显示分配过480MB内存
 * leetcode过不去, 内存爆了...
 * 
 * 作为一个前缀和数组, arr[i]表示spells中大于i的元素有多少个; 则第二轮循环可以省略;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    std::vector<int> ans(spells.size(), 0);
    for(size_t i = 0; i < spells.size(); ++i)
    {
        for(const auto& potion : potions)
        {
            if(spells[i] * (long long)potion >= success)
            {
                ans[i]++;
            }
        }
    }
    return ans;
}

// 优化
vector<int> successfulPairsV2(vector<int> &spells, vector<int> &potions, long long success)
{
    std::vector<int> prefixSum(100001, 0);
    for(const auto& potion : potions)
    {
        ++prefixSum[potion];
    }
    for(int i = 1e5 - 1; i >= 0; --i)
    {
        prefixSum[i] += prefixSum[i + 1];
    }

    std::vector<int> ans(spells.size(), 0);
    for(size_t i = 0; i < spells.size(); ++i)
    {
        // 向上取整
        int div = (success + spells[i] - 1) / spells[i];
        ans[i] = prefixSum[div];
    }
    return ans;
}

int main()
{
    std::vector<int> spells{5, 1, 3};
    std::vector<int> potions{1, 2, 3, 4, 5};
    std::vector<int> ans = successfulPairsV2(spells, potions, 7);

    for(auto num : ans)
    {
        std::cout << num << std::endl;
    }

    
    return 0;
}
