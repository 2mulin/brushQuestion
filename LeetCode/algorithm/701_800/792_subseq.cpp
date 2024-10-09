/**
 * @date 2022/11/17
 * @author 2mu
 * @brief medium 匹配子序列的单词数
 * 
 * 一. 双指针（该方法超时）
 * 
 * 需要将每两个字符串进行比较，一个字符一个字符的比较。
 * 如果字符相等，pos后移。当subStr移到最后，说明已经满足子串条件。
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 二. 二分查找
 * 
 * 移动pos，需要一个一个比较。可以加速。具体方法就是：
 * 将s字符串所有位置对应的字符记录下来。std::vector<std::vector<int>> pos(26)
 * 这样通过字符，就能快速找到字符在s中的所有位置，然后在所有位置中二分查找，找到刚好大于j的位置。
 * 
 * 以此加速移动。
 * 
 * 时间复杂度: O(n*logn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numMatchingSubseq(string s, vector<string> &words)
{
    std::vector<std::vector<int>> pos(26);
    for(int i = 0; i < s.size(); ++i)
    {
        int idx = s[i] - 'a';
        pos[idx].push_back(i);
    }

    int count = 0;
    for(const auto& word : words)
    {
        if(word.size() > s.size())

            continue;// 不可能是字串
        
        int idx = -1; // 已查找到的字符在s中的pos
        int i = 0;
        for(; i < word.size(); ++i)
        {
            std::vector<int>& tmp = pos[word[i] - 'a'];
            if(tmp.empty())
                break;
            // 二分查找
            auto it = std::upper_bound(tmp.begin(), tmp.end(), idx);
            if(it == tmp.end())
                break;
            idx = *it;
        }
        if(i == word.size())
            ++count;
    }
    return count;
}


// 方法一
// bool isSubSeq(std::string& str, std::string& subStr)
// {
//     int j = 0;
//     for(int i = 0; i < str.size(); ++i)
//     {
//         if(str[i] == subStr[j])
//         {
//             ++j;
//         }
//     }
//     if(j == subStr.size())
//         return true;
//     return false;
// }

// int numMatchingSubseq(string s, vector<string> &words)
// {
//     int count = 0;
//     for(auto& word : words)
//     {
//         if(isSubSeq(s, word))
//             ++count;
//     }
//     return count;
// }

int main()
{
    std::vector<std::string> words{"a","bb","acd","ace"};
    std::cout << numMatchingSubseq("abcde", words) << std::endl;
    return 0;
}
