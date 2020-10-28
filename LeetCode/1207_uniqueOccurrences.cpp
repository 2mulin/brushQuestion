/********************************************************************************************
 * @author reddragon
 * @date 2020/10/28
 * @brief easy 独一无二的出现次数
 * 
 * 1.哈希表
 * 首先使用哈希表记录每个数字的出现次数；随后再利用新的哈希表，统计不同的出现次数的数目。
 * 如果不同的出现次数的数目等于不同数字的数目，则返回 true，否则返回 false
 * 时间复杂度：O(N)          空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::set;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> m;
    for (size_t i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    set<int> s;
    for (auto p : m)
    {
        if (s.find(p.second) != s.end())
            return false;
        s.insert(p.second);
    }
    return true;
}

int main()
{
    vector<int> arr{1,1,2,2,3,3,3};
    cout << uniqueOccurrences(arr) << endl;
    return 0;
}