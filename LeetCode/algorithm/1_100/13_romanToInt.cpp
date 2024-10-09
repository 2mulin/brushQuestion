/*
 * @author ling
 * @date 2021/5/15
 * @brief easy 罗马数字转数字
 * 1. 模拟
 * 罗马数字中小的数字都在大的数字后面,如果不是,那就需要减去这个数字
 * 而不是加上它。
 * 时间复杂度： O(N)        空间复杂度：O(1)
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> symbolvalue={
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int romanToInt(string s)
{
    int ans = symbolvalue[s[0]];
    for (size_t i = 1; i < s.length(); ++i)
    {
        int value = symbolvalue[s[i]];
        if(value > symbolvalue[s[i - 1]])
            ans += (value - 2*symbolvalue[s[i - 1]]);
        else
            ans += value;
    }
    return ans;
}

int main()
{
    string str;
    while (cin >> str)
        cout << romanToInt(str) << endl;
    return 0;
}