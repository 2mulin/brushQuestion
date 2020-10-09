/********************************************************************************************
 * @author reddragon
 * @date 2020/10/8
 * @brief easy 反转字符串
 * 
 * 1. 一层for循环
 * 使用swap交换到N/2
 * 时间复杂度：O(N)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        swap(s[i], s[len - 1 - i]);
    }
}

int main()
{
    return 0;
}