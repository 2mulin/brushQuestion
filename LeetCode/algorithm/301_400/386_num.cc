/**
 * @date 2025/6/8
 * @author 2mu
 * @brief medium 字典序排数
 *
 * 1. 官方题解
 * 只想到了最笨的方法，将所有1~n所有合法数字 转化为string加入到数组中，然后排序。
 * 
 * 官方题解很厉害，主要是第二步比较难理解，也就是num % 10 == 9 || num + 1 > n的条件就 /= 10
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<int> lexicalOrder(int n)
{
    int num = 1;
    std::vector<int> result(n, 0);
    for(int i = 0; i < n; ++i)
    {
        result[i] = num;
        if (num * 10 <= n)
            num *= 10;
        else
        {
            while(num % 10 == 9 || num + 1 > n)
            {
                num /= 10;
            }
            num += 1;
        }
    }
    return result;
}

int main()
{
    std::vector<int> result = lexicalOrder(13);
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
