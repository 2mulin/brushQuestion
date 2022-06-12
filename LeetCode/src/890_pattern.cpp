/**
 * @date 2022/6/12
 * @author 2mu
 * @brief medium 查找和替换
 *
 * 1. 双重映射
 * 将所有word都和pattern比较一次。合法：总共26个字母，如果word中出现的字母数量和pattern中出现的字母个数相同，种类可以不同。
 * 按照要求，利用哈希表，将出现的每个字符和pattern中出现的字母构造映射, 需要构造两个映射，一个从word映射到pattern，一个从pattern映射到word。
 * 后续直接比较映射字母是否相同。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include <algorithm>

using namespace std;

bool isValid(string left, string right)
{
    if(left.size() != right.size())
        return false;
    unordered_map<char, char> leftToRight, rightToLeft;

    for(size_t idx = 0; idx < left.size(); ++idx)
    {
        if(leftToRight.find(left[idx]) == leftToRight.end() && rightToLeft.find(right[idx]) == rightToLeft.end())
        {
            leftToRight.insert(std::pair<char, char>(left[idx], right[idx]));
            rightToLeft.insert(std::pair<char, char>(right[idx], left[idx]));
        }
        else
        {
            auto iter = leftToRight.find(left[idx]); 
            if(iter != leftToRight.end() && iter->second != right[idx])
                return false;
            iter = rightToLeft.find(right[idx]);
            if(iter != rightToLeft.end() && iter->second != left[idx])
                return false;
        }
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> result;
    for(auto word : words)
    {
        if(isValid(word, pattern))
            result.push_back(word);
    }
    return result;
}

int main()
{
    vector<string> words{ "abc","deq","mee","aqq","dkd","ccc"};
    auto result = findAndReplacePattern(words, "abb");
    for(auto word : result)
        std::cout << word << '\t';
    std::cout << std::endl;
    return 0;
}
