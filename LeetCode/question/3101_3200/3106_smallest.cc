/**
 * @date 2024/7/27
 * @author 2mu
 * @brief medium 满足距离约束且字典序最小的字符串
 *
 * 1. 贪心
 * 
 * 题目要求是任意切换字符串s1中的字符, 使其成为s2, 并使该字符串s2的字典序变小(越小越好);
 * 同时 distance(s1, s2) < k
 * 
 * 从distance的角度考虑, 那就非常复杂; 所以换个角度, 从字典序的角度考虑, 字典序越小, 说明字符串
 * 最好都是aaa等较小的字符;
 * 
 * 所以s2应该是尽可能选择a字母, 除非选择不了...所以使用贪心
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getSmallestString(string s, int k)
{
    for(int i = 0; i < s.length(); ++i)
    {
        int distance = std::min(s[i] - 'a', 'z' - s[i] + 1);
        if(distance <= k)
        {
            k -= distance;
            s[i] = 'a';
        }
        else
        {
            // 一定是减小, 这样才会字典序小, 并且一定不会减到小于 'a'
            s[i] = s[i] - k;
            break;
        }
    }
    return s;
}

int main(int argc, char **argv)
{
    std::cout << getSmallestString("zbbz", 3) << std::endl;
    return 0;
}

