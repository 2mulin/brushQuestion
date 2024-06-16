/**
 * @date 2024/6/17
 * @author 2mu
 * @brief easy 最长特殊序列I
 *
 * 1. 读题目
 * 主要是需要读题目，读懂就会做，读不懂就会做错......这题目意义不大
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>


using namespace std;

int findLUSlength(string a, string b)
{
    return a != b ? max(a.length(), b.length()) : -1;
}

int main(int argc, char **argv)
{
    std::cout << findLUSlength("aaa", "bbbb") << std::endl;
    return 0;
}

