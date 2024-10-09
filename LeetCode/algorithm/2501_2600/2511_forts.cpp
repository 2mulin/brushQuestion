/**
 * @date 2023/9/2
 * @author 2mu
 * @brief easy 最多可以摧毁的敌人城堡数量
 *
 * 1. 前缀数组
 * 准备一个前缀数组记录0的数量, 也就是敌人城堡的数量; 这样, 当找到自己城堡位置和敌人城堡位置时, 就可以快速计算出两点之间有多少敌人的城堡;
 * 然后再遍历一遍数组, 使用两个变量分别记录自己位置, 和敌人城堡位置;
 * 
 * 注意这个条件: 军队经过的位置 只有 敌人的城堡。正式的，对于所有 min(i,j) < k < max(i,j) 的 k ，都满足 forts[k] == 0 
 * 
 * 由于这个条件的存在, [1,0,0,-1,0,0,-1,0,0,1] 的答案是2
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int captureForts(vector<int> &forts)
{
    if(forts.size() <= 1)
        return 0;

    vector<int> prefixForts(forts.size(), 0);
    if(prefixForts.front() == 0)
        prefixForts.front() = 1;
    for(int i = 1; i < forts.size(); ++i)
    {
        if(forts[i] == 0)
            prefixForts[i] = prefixForts[i - 1] + 1;
        else
            prefixForts[i] = prefixForts[i - 1];
    }

    // 分别记录遍历过程中最后一次计算过的 自家城堡 和 空地
    int ans = 0;
    int lastMyFortPos = -1, lastSpacePos = -1;
    for(int i = 0; i < forts.size(); ++i)
    {
        if(forts[i] == -1)
        {
            if(lastMyFortPos != -1)
            {
                int enemyCnt = prefixForts[i] - prefixForts[lastMyFortPos];
                ans = std::max(enemyCnt, ans);
            }
            lastSpacePos = i;
            lastMyFortPos = -1;// 解决那个特殊条件
        }
        if(forts[i] == 1)
        {
            if(lastSpacePos != -1)
            {
                int enemyCnt = prefixForts[i] - prefixForts[lastSpacePos];
                ans = std::max(enemyCnt, ans);
            }
            lastMyFortPos = i;
            lastSpacePos = -1;// 解决那个特殊条件
        }
    }
    return ans;
}

int main()
{
    std::vector<int> vct = {1,0,0,-1,0,0,0,0,1};
    std::cout << captureForts(vct) << std::endl;
    vct = {0,0,1,-1};
    std::cout << captureForts(vct) << std::endl;

    vct = {1,0,0,-1,0,0,-1,0,0,1};
    std::cout << captureForts(vct) << std::endl;
    return 0;
}
