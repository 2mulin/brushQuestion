/********************************************************************************************
 * @author ling
 * @date 2021/4/20
 * @brief easy 实现strStr()
 * 
 * 1. 直接使用STL实现好的.
 * 
 * 2. KMP算法
 * 这题目的原意就是考察KMP算法.
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int strStr(string haystack, string needle)
{
    auto pos = haystack.find(needle);
    if (pos == string::npos)
        return -1;
    return pos;
}

int main()
{
    return 0;
}