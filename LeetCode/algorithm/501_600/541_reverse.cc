/**
 * @date 2025/1/31
 * @author 2mu 
 * @brief easy 反转字符串II
 * 
 * 1. 模拟
 * 没看出什么特殊的，双指针遍历一遍，按照规则进行反转应该就可以。
 * 
 * 同样的思路，看看官方题解的代码，再看看自己写的，自己写的实在是太垃圾了。
 * 在这一道题目体现的淋漓尽致。
 * 
 * 时间复杂度：O(n)  空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string reverseStr(string s, int k)
{
    int n = s.length();
    for(int i = 0; i < n; i += 2 * k)
    {
        std::reverse(s.begin() + i, s.begin() + std::min(i + k, n));
    }
    return s;
}


int main()
{
    std::cout << reverseStr("abcd", 2) << std::endl;
    return 0;
}
