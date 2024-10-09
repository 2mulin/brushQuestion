/*******************************************************************************
 * @author reddragon
 * @date 2020/7/31
 * @brief 最小覆盖字串 hard
 * 1.暴力解法：找出s所有的字串，然后和t比看是否满足条件
 * 时间：O(n*n*n + m)  空间：O(m)
 * 2.滑动窗口：我们在 s 上滑动窗口，通过移动 r 指针不断扩张窗口。
 * 当窗口包含 t 全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
 * 每次比较当前答案和满足条件的窗口,窗口更小就更新答案
 * 时间：O(n*m)     空间：O(m)
 *******************************************************************************/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 检查当前窗口是否有t中所有的字符
bool check(unordered_map<char, int> &ma)
{
    for (auto i : ma)
        if (i.second > 0)
            return false;
    return true;
}

string minWindow(string s, string t)
{
    if (s.length() < t.length())
        return "";
    unordered_map<char, int> ma;
    for (size_t i = 0; i < t.length(); i++)
        ma[t[i]]++;

    string ans = s;
    // 滑动窗口
    size_t left = 0;
    size_t right = 0;
    if (ma.find(s[0]) != ma.end())
        ma[s[0]]--;
    bool hasAns = false;
    while (left < s.size())
    {
        size_t len = right - left + 1;
        if (check(ma))
        {
            hasAns = true;
            if (ans.length() > len)
                ans = s.substr(left, len);
            // 窗口减小
            if (ma.find(s[left]) != ma.end())
                ma[s[left]]++;
            left++;
        }
        else if (right == s.length() - 1)
        {
            // 窗口减小
            if (ma.find(s[left]) != ma.end())
                ma[s[left]]++;
            left++;
        }
        else
        {
            // 窗口增大
            right++;
            if (ma.find(s[right]) != ma.end())
                ma[s[right]]--;
        }
    }
    if (!hasAns)
        ans = "";
    return ans;
}

int main()
{
    cout << minWindow("a", "aa") << endl;
    return 0;
}