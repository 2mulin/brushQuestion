/**
 * @date 2023/11/8
 * @author 2mu
 * @brief easy 最长平衡字符串
 *
 * 1. 遍历一遍
 * 遍历一遍字符串, 遍历途中记录当前碰到的最长连续0串长度, 然后紧接就记录0串 后面的最长连续1串长度
 * 取二者最小值就是答案;
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

int findTheLongestBalancedSubstring(string s)
{
    int ans = 0;
    int SeqZeroLen = 0, SeqOneLen = 0;
    for(const char& ch : s)
    {
        if(ch == '0')
        {
            if(SeqOneLen)
            {
                ans = std::max(std::min(SeqOneLen, SeqZeroLen), ans);
                SeqOneLen = 0;
                SeqZeroLen = 0;
            }
            SeqZeroLen++;
        }
        else if(ch == '1')
        {
            ++SeqOneLen;
        }
    }
    ans = std::max(std::min(SeqOneLen, SeqZeroLen), ans);
    return ans << 1;
}

int main()
{
    std::cout << findTheLongestBalancedSubstring("01000111") << std::endl;
    std::cout << findTheLongestBalancedSubstring("00111") << std::endl;
    std::cout << findTheLongestBalancedSubstring("001") << std::endl;
    return 0;
}
