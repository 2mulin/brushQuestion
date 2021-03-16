/********************************************************************************************
 * @author reddragon
 * @date 2021/3/16
 * @brief hard 买卖股票的最佳时机III
 * 
 * 1. 动态规划
 * 总共有5种状态
 *      未进行过任何操作；永远是0
 *      只进行过一次买操作；buy1
 *      进行了一次买操作和一次卖操作，即完成了一笔交易；sell1
 *      在完成了一笔交易的前提下，进行了第二次买操作；buy2
 *      完成了全部两笔交易。sell2
 * 
 * 第一个状态没有必要记录, 以buy1, sell1, buy2, sell2记录其余状态
 * 显然有四个状态, 那就是有四个状态转移方程
 * buy1 = max(buy1, 0 - price[i]) (买入或者不买入)
 * sell1 = max(sell1, buy1 + price[i])(不卖出或者卖出)
 * buy2 = max(buy2, sell1 - price[i])(不买入或者买入)
 * sell2 = max(sell2, buy2 + price[i])(不卖出或者卖出)
 * 
 * 总结一下, 五个状态, 每个状态都和前一个状态相关.
 * 每个状态各自有一个状态转移方程
 * 时间复杂度: O(N)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.empty())
        return 0;
    // 初始状态
    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;
    for(auto num : prices)
    {
        buy1 = max(buy1, 0 - num);
        sell1 = max(sell1, buy1 + num);
        buy2 = max(buy2, sell1 - num);
        sell2 = max(sell2, buy2 + num);
    }
    return max(sell1, sell2);   
}

int main()
{
    vector<int> arr{1,2,3,4};
    cout << maxProfit(arr) << endl;
    return 0;
}
