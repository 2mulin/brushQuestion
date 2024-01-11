/**
 * @date 2023/1/11
 * @author 2mu
 * @brief medium 一次遍历
 *
 * 1. 一次遍历
 * 由于必须是连续的abc字符串组成, 才是有效字符串; 且条件说明只word字符串只存在a,b,c字符;
 * 则可以顺序遍历整个word字符串, 记录当前字符; 当前字符 <= 上一个字符 时, 则是一组 'abc', 就看当前组缺少多少字符..
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int addMinimum(string word)
{
    if(word.empty())
        return 3;

    int sum = 0;
    std::string cur;
    cur.push_back(word.front());
    for(int i = 0; i < word.length() - 1; ++i)
    {
        if(word[i] >= word[i + 1])
        {
            sum = sum + (3 - cur.length());
            cur.clear();
        }
        cur.push_back(word[i + 1]);
    }
    sum = sum + (3 - cur.length());
    return sum;
}


int main()
{
    std::cout << addMinimum("b") << std::endl;
    std::cout << addMinimum("aaa") << std::endl;
    std::cout << addMinimum("abc") << std::endl;
    return 0;
}