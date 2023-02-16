/**
 * @date 2022/2/16
 * @author 2mu
 * @brief easy 数组可以形成多少数对
 *
 * 一、哈希表
 * 哈希表记录出现过的数字，一旦重复，删除哈希表中的元素，下次再遇见时，则加入。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> numberOfPairs(vector<int>& nums) 
{
    unordered_set<int> setNums;
    int numPairCnt = 0;
    for(auto num : nums)
    {
        if(setNums.find(num) == setNums.end())
        {
            setNums.insert(num);
        }
        else
        {
            setNums.erase(num);
            ++numPairCnt;
        }
    }
    std::vector<int> vctAns;
    vctAns.push_back(numPairCnt);
    vctAns.push_back(setNums.size());
    return vctAns;
}

int main()
{
    return 0;
}
