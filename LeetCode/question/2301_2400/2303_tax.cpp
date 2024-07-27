/**
 * @date 2022/1/23
 * @author 2mu
 * @brief easy 计算应缴税额总款
 * 
 * 一、直接模拟
 * 直接按照要求计算税款即可。题解有一点做的比较好，就是先按照整数计算税款，最后除以100
 * 减少浮点计算，缺点是如果整数很大，可能会越界。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

double calculateTax(vector<vector<int>> &brackets, int income)
{
    if(income < 0)
        return 0;

    double taxSum = 0;
    int preLimit = 0;
    for(auto pa : brackets)
    {
        int diff = pa[0] - preLimit;
        double rate = pa[1] / (double)100;
        if(income > diff)
        {
            taxSum += diff * rate;
            income -= diff;
        }
        else
        {
            taxSum += income * rate;
            income = 0;
        }
        preLimit = pa[0];
    }
    return taxSum;
}

int main()
{
    std::vector<std::vector<int>> brackets{{3,50},{7,10},{12,25}};
    std::cout << calculateTax(brackets, 10) << std::endl;
    return 0;
}
