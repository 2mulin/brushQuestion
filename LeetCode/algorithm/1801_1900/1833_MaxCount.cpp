/**
 * @author ling
 * @date 2021/7/2
 * @brief medium 雪糕的最大数量
 * 
 * 1. 排序+贪心
 * 每次都选价格最便宜的买,最后肯定能买到最多的雪糕.
 * 排序时间O(nlogN), 再遍历一次就可以了
 * 时间复杂度：O(NlogN)             空间复杂度：O(1)
 * 
 * 2. 计数排序
 * 由于题目数字比较小, , 对出现的每一个费用
 * 记录下来, count[i]表示i费用出现了几次。典型的以空间换取时间
 * 最后由小到大遍历一遍就可以了。
 * 时间复杂度: O(N)                 空间复杂度: O(N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// 方法一: 排序+贪心
int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int ans = 0;
    for (int i = 0; i < costs.size(); ++i)
    {
        if (coins - costs[i] >= 0)
        {
            ++ans;
            coins -= costs[i];
        }
    }
    return ans;
}

// 方法二: 计数排序
int maxIceCream(vector<int> &costs, int coins)
{
    vector<int> count(100005, 0);
    for (int i = 0; i < costs.size(); ++i)
    {
        ++count[costs[i]];
    }
    long long ans = 0;
    for (long long i = 0; i < 100005; ++i)
    {
        if (coins >= i * count[i])
        {
            ans += count[i];
            coins -= i * count[i];
        }
        else
        {
            ans += (coins / i);
            break;
        }
    }
    return ans;
}

int main()
{
    return 0;
}