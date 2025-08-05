/**
 * @date 2025/8/5
 * @author 2mu
 * @brief easy 水果成篮II
 *
 * 1. 模拟
 * 一开始想多了，这就是个简单题，数据量也非常小，直接模拟即可。
 * 反而是一排序，会得到错误答案，因为题目要求先使用最左侧可用篮子。
 * 
 * 而且没有第二种方法.... 哈希表也不能加速
 * 
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;


int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int count = 0;
    for(int j = 0; j < fruits.size(); ++j)
    {
        for(int i = 0; i < baskets.size(); ++i)
        {
            if (baskets[i] >= fruits[j])
            {
                baskets[i] = -1;
                ++count;
                break;
            }
        }
    }
    return fruits.size() - count;
}


int main()
{
    std::vector<int> fruits{4, 2, 5}, baskets{3, 5, 4};
    std::cout << numOfUnplacedFruits(fruits, baskets) << std::endl;
    return 0;
}
