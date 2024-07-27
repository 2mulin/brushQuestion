/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/21
 * @brief easy 卖卖股票的最佳时机
 * 1.一次遍历
 * 注意可以买多次，所以说，只要相邻两个价格，前一个小，后一个大，就有的赚，
 * 所以问题就非常简单了。
 * 时间复杂度：O(N)         空间复杂度：O(1)
 * 
 * 还有其他方法，不过这个最好理解，也最高效
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 一次遍历
int maxProfit(vector<int> &prices)
{
    int max_p = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] > 0)
            max_p += prices[i] - prices[i - 1];
    }
    return max_p;
}

int main()
{
    vector<int> arr{7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr) << endl;
    return 0;
}