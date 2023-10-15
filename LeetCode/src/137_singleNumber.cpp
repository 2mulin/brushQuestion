/**
 * @date 2023/10/15
 * @author 2mu
 * @brief medium 指出现过一次的数字 
 *
 * 1. 哈希表
 * 使用哈希表记录数组中的元素出现过几次; 最终遍历哈希表找到只出现过一次的数字;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. 电路设计
 * 更优的解法, 有点复杂, 算了吧; 虽然大学学过...
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int> &nums)
{
    std::unordered_map<int, int> mapCnt;
    for(int i = 0; i < nums.size(); ++i)
    {
        mapCnt[nums[i]]++;
    }
    for(auto iter = mapCnt.begin(); iter != mapCnt.end(); ++iter)
    {
        if(iter->second == 1)
            return iter->first;
    }
    return 0;
}

int main()
{
    std::vector<int> vct{1, 3, 3, 3};
    std::cout << singleNumber(vct) << std::endl;
    return 0;
}
