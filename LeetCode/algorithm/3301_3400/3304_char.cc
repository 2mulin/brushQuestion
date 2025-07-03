/**
 * @date 2025/7/3
 * @author 2mu 
 * @brief easy 找出第 K 个字符 I
 *
 * 1. 模拟
 * 范围也不大，直接模拟就可以得到答案。
 * 
 * 时间复杂度：O(nk)
 * 空间复杂度：O(n)
 * 
 * 2. 官方题解
 * 利用数学思路，定位最终k位的字母是从哪个位置得来的，然后计算总共经历几次变化。
 * 
 * 数学公式：k = 2的t次方 + 'a'
 * t表示经历几次变化，计算出t的值，就可以得到k。
 * 
 * 时间复杂度：O(logk)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>

using namespace std;

char kthCharacter(int k)
{
    std::string word = "a";
    while (word.length() < k)
    {
        std::string new_word = word;
        for (int i = 0; i < word.length(); ++i)
        {
            char ch = word[i];
            if (ch == 'z')
                ch = 'a';
            else
                ch += 1;
            new_word.push_back(ch);
        }
        word = new_word;
    }
    return word[k - 1];
}

int main()
{
    std::cout << kthCharacter(5) << std::endl;
    return 0;
}
