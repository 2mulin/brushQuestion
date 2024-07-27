/**
 * @date 2022/12/27
 * @author 2mu
 * @brief easy 转换字符串的最少次数
 * 
 * 一、贪心
 * 遍历字符串，一旦发现当前字母不是'O'，就进行一次转换。题目要求一次可以转换3个字母。
 * 所以直接将后续3个字母全部转换。最后统计转换次数。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minimumMoves(string s)
{
    int ans = 0;
    for(size_t i = 0; i < s.length(); ++i)
    {
        /**
         * @brief 优化这段代码
         * 这段代码还是可以优化的，不需要做真正的转换，直接将下标的i往后移两个位置即可。
         */
        if (s[i] != 'O')
        {
            ++ans;
            s[i] = 'O';
            if(i + 1 < s.length())
                s[i + 1] = 'O';
            if(i + 2 < s.length())
                s[i + 2] = 'O';
        }
    }
    return ans;
}

int main()
{

    return 0;
}
