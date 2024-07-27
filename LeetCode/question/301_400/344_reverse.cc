/**
 * @author 2mu
 * @date 2024/7/27
 * @brief easy 反转字符串
 * 
 * 1. 利用swap
 * 最简单的思路, 就是额外创建容器, 反向遍历一遍记录下来;
 * 但题目要求O(1)空间复杂度, 那就不能额外创建容器;
 * 
 * 所以也可以使用swap交换 数组前半部分和数组后半部分的内容;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        std::swap(s[i], s[len - 1 - i]);
    }
}


int main()
{
    std::vector<char> s{'h','e','l','l','o'};
    reverseString(s);
    return 0;
}
