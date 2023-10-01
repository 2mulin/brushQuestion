/**
 * @date 2022/10/1
 * @author 2mu
 * @brief easy 买卖股票的最佳时机
 * 
 * 1. 数组
 * 因为实际上**限制买进,卖出股票次数只有一次**; 所以这是简单题;
 * 很显然, 只需要在股票最低点买入, 然后在最高点卖出即可; 
 * 
 * 解决方法: 使用两个变量分别记录出现过的数组最小值位置minPos;
 * 如果当前位置i, prices[i] - prices[minPos]的值大于0; 这就是一种买入卖出方案;
 * 再有一个ans变量, 记录prices[i] - prices[minPos]的最大值; 即记录利润最高的方案
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 
 * 2.单调栈
 * 从后往前遍历，得到一个单调递增序列的索引，如7 1 3 2 6，栈中由上到下是0，4
 * 7 1 3 2 6
 * 7 6 6 6 6
 * 就是上面的意思
 * 表示的意思就是说prices[i]到prices[s.top()]能看到的最大值就是prices[s.top()];
 * 当i大与s.top时，调用s.pop()
 * 
 * 时间复杂度: O(N)
 * 空间复杂度: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int ans = 0, minPos = 0;
    for(int i = 1; i < prices.size(); ++i)
    {
        if(prices[minPos] > prices[i])
        {
            minPos = i;
        }
        ans = std::max(ans, prices[i] - prices[minPos]);
    }
    return ans;
}

int main()
{
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(prices) << std::endl;
    return 0;
}
