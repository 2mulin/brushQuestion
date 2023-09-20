/**
 * @date 2023/9/20
 * @author 2mu
 * @brief LCP06 拿硬币
 *
 * 1. 模拟
 * 数据量非常小, 直接模拟, 做一下除法即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int minCount(vector<int> &coins)
{
    int ans = 0;
    for(auto coin : coins)
    {
        ans = (coin + 1) / 2 + ans;
    }
    return ans;
}

int main()
{
    std::vector<int> arr{4, 2, 1};
    std::cout << minCount(arr) << std::endl;
    return 0;
}
