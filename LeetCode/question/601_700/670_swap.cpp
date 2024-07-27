/**
 * @date 2023/1/22
 * @author 2mu
 * @brief medium 最大交换
 *
 * 1. 全排列
 * 直接将数字的全排列计算出来, 也很快的, 因为只有一个8个数字, 总共有 8*7*6*5*4*3*2 中可能;
 * 然后从中选出和当前数字只有2位不同的 其它排列数字;
 * 
 * 在当前数字和选择出来的其它排列数字中找到最大值即可;
 * 
 * 时间复杂度: O(n * m)
 * 空间复杂度: O(m)
 * 
 * 2. 枚举
 * 最多8位数字, 然后只能交换一次, 相比于全排列, 枚举所有可能的 交换情况; 会更好一些, 因为只有最多只有28种交换可能...
 * 看了题解才知道, 思维还是不行....
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool satisfy(const std::string& str1, const std::string& str2)
{
    if(str1.length() != str2.length())
        return false;
    int diff = 0;
    for(int i = 0; i < str1.length(); ++i)
    {
        if(str1[i] != str2[i])
        {
            ++diff;
        }
        if(diff > 2)
            return false;
    }
    return true;
}

int maximumSwap(int num)
{
    std::string word = std::to_string(num);
    std::unordered_set<std::string> permutations;
    permutations.insert(word);

    while(std::next_permutation(word.begin(), word.end()))
    {
        permutations.insert(word);
    }

    int max_value = num;
    word = std::to_string(num);
    for(const std::string& permutation : permutations)
    {
        if(satisfy(word, permutation))
        {
            max_value = std::max(max_value, stoi(permutation));
        }
    }
    return max_value;
}

int main()
{
    std::cout << maximumSwap(2736) << std::endl;
    std::cout << maximumSwap(9973) << std::endl;
    return 0;
}