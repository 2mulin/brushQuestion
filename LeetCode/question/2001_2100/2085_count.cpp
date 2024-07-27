/**
 * @date 2023/1/13
 * @author 2mu
 * @brief easy 统计只出现过一次的字符串
 *
 * 1. 哈希表
 * 使用两个哈希表; 遍历第一个字符串数组, 将str存入到哈希表中, 如果发现当前str已存在哈希表中, 则从当前哈希表中删除, 
 * 并记录到代表重复字符串的哈希表中, 后续再重复则跳过;
 * 
 * 第二个字符串数组, 使用相同方法; 最后取交集即可;
 * 
 * 时间复杂度: O(m + n)
 * 空间复杂度: O(m + n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int countWords(vector<string> &words1, vector<string> &words2)
{
    std::unordered_set<std::string> set1;
    std::unordered_map<std::string, int> repeated;
    for(const std::string& str : words1)
    {
        if (repeated.find(str) != repeated.end())
        {
            continue;
        }
        auto iter = set1.find(str);
        if (iter != set1.end())
        {
            set1.erase(iter);
            repeated[str]++;
        }
        else
        {
            set1.insert(str);
        }
    }
    repeated.clear();

    int count = 0;
    for(const std::string& str : words2)
    {
        if (set1.find(str) != set1.end())
        {
            if (repeated.find(str) == repeated.end())
            {
                ++count;
                repeated[str]++;
            }
            else
            {
                if (repeated[str] == 1)
                {
                    --count;// str在word2中重复出现, 所以不能作为答案;
                    repeated[str]++; // 如果还有重复, 不需要--count
                }
            }
        }
    }
    return count;
}

int main()
{
    std::vector<std::string> words1{"leetcode","is","amazing","as","is"}, words2{"amazing","leetcode","is"};
    std::cout << countWords(words1, words2) << std::endl;
    return 0;
}