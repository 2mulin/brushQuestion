/**
 * @date 2025/2/3
 * @author 2mu 
 * @brief easy 验证回文串II
 * 
 * 1. 枚举
 * 枚举所有所有情况，删除每种删除元素的可能性。
 * 然后判断新字符串是否是回文串。空间复杂度有点不对，会超出内存限制...
 * 
 * 想想其他办法
 * 
 * 时间复杂度: O(n*n)    空间复杂度: O(n)
 * 
 * 2. 双指针
 * 使用双指针分别指向第一个元素，以及最后一个元素。一旦相等就继续比较。
 * 不相等则有一次删除元素的机会，可以删除双指针指向的两个元素中任意一个。
 * 枚举下两种情况，看能否成功即可。
 * 
 * 时间复杂度只需要遍历一遍，最多枚举两种情况。空间复杂度很低，只有未修改过的字符串参数。
 * 
 * 时间复杂度: O(n)      空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


bool isValid(const std::string& s, int low, int high)
{
    while(low < high)
    {
        if (s[low] != s[high])
            return false;
        ++low;
        --high;
    }
    return true;
}


bool validPalindrome(string s)
{
    int low = 0, high = s.length() - 1;
    while(low < high)
    {
        if (s[low] == s[high])
        {
            ++low;
            --high;
        }
        else
        {
            if (isValid(s, low + 1, high) || isValid(s, low, high - 1))
                return true;
            else
                return false;
        }
    }
    return true;
}


int main()
{
    std::cout << validPalindrome("aba") << std::endl;
    std::cout << validPalindrome("abca") << std::endl;
    std::cout << validPalindrome("abc") << std::endl;
    return 0;
}
