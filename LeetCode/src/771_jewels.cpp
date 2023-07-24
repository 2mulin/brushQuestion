/**
 * @date 2023/7/24
 * @author 2mu
 * @brief easy 宝石和石头
 * 
 * 1. 哈希表
 * 利用哈希表加速, 因为实际上查找 stones 中的字符是否有在 jewels 中出现过; 
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    if(jewels.empty())
        return 0;
    std::unordered_set<char> jewelsHash;
    for(auto ch : jewels)
    {
        jewelsHash.insert(ch);
    }

    int ans = 0;
    for(auto ch : stones)
    {
        if(jewelsHash.find(ch) != jewelsHash.end())
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    std::cout << numJewelsInStones ("aA", "aAAbbbb") << std::endl;
    return 0;
}
