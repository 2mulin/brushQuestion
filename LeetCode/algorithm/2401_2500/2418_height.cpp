/**
 * @date 2023/4/25
 * @author 2mu
 * @brief easy
 *
 * 1. 哈希表
 * 直接std::sort就可以, 并且题目保证所有人身高没有相同的; 其次又知道 n < 1000, 身高最高是 100000
 * 而且排序之后, 需要保持之前的idx对应关系, 这样才可以知道 name
 * 
 * 所以最快的方式是使用 100000 个元素大小的数组 当作哈希表; 记录身高值 出现在 heigths中的idx
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 2. std::sort
 * 通过提交结果来看, 这个题目还是排序速度更快; 估计是因为 n < 1000; 
 * 1000 * log1000 = 10000左右 < 100000 所以哈希表速度反而慢
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    std::vector<int> hashTable(100005, -1);
    for(size_t idx = 0; idx < heights.size(); ++idx)
    {
        int height = heights[idx];
        hashTable[height] = idx;
    }

    std::vector<std::string> vctNames;
    for(size_t height = hashTable.size() - 1; height > 0; --height)
    {
        if(hashTable[height] > -1)
        {
            // 该身高值出现过
            int idx = hashTable[height];
            vctNames.push_back(names[idx]);
        }
    }
    return vctNames;
}

int main()
{
    std::vector<std::string> names {"Alice","Bob","Bob"};
    std::vector<int> heights{155,185,150};

    names = sortPeople(names, heights);
    for(auto name : names)
    {
        std::cout << name << '\t';
    }
    std::cout << std::endl;
    return 0;
}