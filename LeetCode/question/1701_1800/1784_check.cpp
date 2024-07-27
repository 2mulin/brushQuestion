/**
 * @date 2022/10/3
 * @author 2mu 在LR字符串中交换相邻字符
 * @brief
 *
 * 一. 阅读理解
 * 可能是翻译不太好，单纯看题目完全不知道是什么意思。题目没啥可以学习的地方。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>

using namespace std;

bool checkOnesSegment(string s)
{
    return s.find("01") == std::string::npos;
}

int main()
{
    return 0;
}
