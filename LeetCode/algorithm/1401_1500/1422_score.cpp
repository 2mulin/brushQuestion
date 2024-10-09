/**
 * @date 2022/8/14
 * @author 2mu
 * @brief easy 分割字符串的最大得分
 *
 * 一. 两次遍历
 * 首先计算出来0和1出现的总次数。然后从左往右遍历，记录当前左边出现的1和0的次数，右边的1和0的次数等于总数减去左边0，1数量。
 * 需要遍历两次字符串。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>

using namespace std;

int maxScore(string s)
{
    int oneSum = 0, zeroSum = 0;
    for(auto ch : s)
    {
        if(ch == '0')
            ++zeroSum;
        if(ch == '1')
            ++oneSum;
    }
    int score = 0;
    int leftOne = 0, leftZero = 0;
    for(int i = 0; i < s.length() - 1; ++i)
    {
        if(s[i] == '0')
            leftZero++;
        if(s[i] == '1')
            leftOne++;
        score = std::max(score, leftZero + (oneSum - leftOne));
    }
    return score;
}

int main()
{
    string s = "00";
    std::cout << maxScore(s) << std::endl;
    return 0;
}
