/**
 * @date 2023/5/2
 * @author 2mu
 * @brief medium 强整数
 *
 * 1. 枚举
 * 从x, y的0,1,2,3,4....次方之和 开始枚举, 如果满足条件加入哈希表中;
 * 知道x,y的i,j次方之和 大于 bound, 停止;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound)
{
    std::unordered_set<int> ansSet;
    for(int i = 0; i < 20; ++i)
    {
        long long num1 = std::pow(x, i);
        if(num1 > bound)
            break;
        for(int j = 0; j < 20; ++j)
        {
            long long sum = num1 + std::pow(y, j); 
            if(sum <= bound)
                ansSet.insert(sum);
            else
                break;
        }
    }

    return std::vector<int>(ansSet.begin(), ansSet.end());
}


int main()
{
    auto vct = powerfulIntegers(3, 5, 15);
    for(auto num : vct)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    
    vct = powerfulIntegers(81, 21, 900000);
    for(auto num : vct)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    return 0;
}