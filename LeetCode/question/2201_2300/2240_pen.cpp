/**
 * @date 2023/9/1
 * @author 2mu
 * @brief medium 买钢笔和铅笔的方案数
 *
 * 1. 枚举
 * 看题目意思就是枚举, 那么就直接枚举;
 * 先枚举买钢笔的数量, 然后枚举买铅笔的数量; 只要钢笔或着铅笔数量不同; 那就是不同方案;
 * 
 * 时间复杂度: O(n)     n就是 total / max(cost1, cost2), 所以实际下面的实现还可以优化, 第一个用大的数枚举
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long waysToBuyPensPencils(int total, int cost1, int cost2)
{
    long long ans = 0, penCnt = 0; // 钢笔数量
    long long cost = penCnt * cost1; // 买钢笔需要的钱
    while(cost <= total)
    {
        // 能买n支铅笔, 就是n+1中方案, 0支铅笔也算
        ans = ans + (total - cost) / cost2 + 1;
        ++penCnt;
        cost = penCnt * cost1;
    }
    return ans;
}

int main()
{
    std::cout << waysToBuyPensPencils(20, 10, 5) << std::endl;
    return 0;
}
