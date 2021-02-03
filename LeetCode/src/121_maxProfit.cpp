/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/20
 * @brief easy 卖卖股票的最佳时机
 * 1.暴力枚举
 * 选定买入的时候，再选定卖出的时候，枚举出所有的可能性
 * 时间复杂度：O(N*N)      空间复杂度：O(N)
 * 
 * 2.单调栈
 * 从后往前遍历，得到一个单调递增序列的索引，如7 1 3 2 6，栈中由上到下是0，4
 * 7 1 3 2 6
 * 7 6 6 6 6
 * 就是上面的意思
 * 表示的意思就是说prices[i]到prices[s.top()]能看到的最大值就是prices[s.top()];
 * 当i大与s.top时，调用s.pop()
 * 时间复杂度O(N)        空间复杂度: O(N)
 * 
 * 3.一次遍历
 * 把上面的单调找反过来就对了
 * 7 1 3 2 6
 * 7 1 1 1 1
 * 记录最低点
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 一次遍历
int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++)
    {
        if(minPrice > prices[i])
            minPrice = prices[i];
        else
        {
            int profit = prices[i] - minPrice;
            if(profit > ans)
                ans = profit;
        }
    }
    return ans;
}

/* 单调栈
int maxProfit(vector<int> &prices)
{
    stack<int> st;
    for(int i = prices.size() - 1; i >= 0; i--)
    {
        if(st.empty() || prices[i] > prices[st.top()])
        {
            st.push(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        if(st.top() < i)
            st.pop();
        if(prices[st.top()] - prices[i] > ans)
            ans = prices[st.top()] - prices[i];
    }
    return ans;
} */

/* 暴力枚举
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    // 暴力
    int ans = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    { // i是买入的时候
        int max = prices[i];
        for (int j = i + 1; j < prices.size(); j++)
        { // j是卖出的时候
            if (prices[j] > max)
                max = prices[j];
        }
        if (max - prices[i] > ans)
            ans = max - prices[i];
    }
    return ans;
} */

int main()
{
    vector<int> arr{7,1,5,3,6,4};
    cout << maxProfit(arr) << endl;
    return 0;
}