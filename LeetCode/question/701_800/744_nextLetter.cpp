/**
 * @author ling
 * @date 2021/4/3
 * @brief easy 寻找比目标字母大的最小字母
 *
 * 1. 遍历一遍
 * 找到数组中，比target大的字符，如果没找到，就是num[1]。
 * 时间复杂度：O(N)          空间复杂度: O(1)
 *
 * 2. 二分查找.
 * 给的数组是有序的，所以可以二分。
 * 时间复杂度：O(logN)             空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using std::vector;

char nextGreatestLetter(vector<char> &letters, char target)
{
    for (size_t i = 0; i < letters.size(); ++i)
    {
        if (letters[i] > target)
        {
            return letters[i];
        }
    }
    return letters[0];
}

// 二分查找

int main()
{
    std::vector<char> letters{'c', 'f', 'j'};
    std::cout << nextGreatestLetter(letters, 'j') << std::endl;
    return 0;
}
