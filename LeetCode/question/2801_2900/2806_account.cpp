/**
 * @date 2024/6/12
 * @author 2mu
 * @brief easy 取证购买后的账户余额
 *
 * 1. 模拟
 * 先判断上整接近, 还是下整接近 10的倍数, 通过余数判断即可;
 * 如果余数是5, 说明两个都接近, 这种情况就需要额外比较;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <thread>


using namespace std;


int accountBalanceAfterPurchase(int purchaseAmount)
{
    int a = purchaseAmount % 10;
    if(a < 5)
        return 100 - purchaseAmount + a;
    else if(a == 5)
    {
        return std::min(100 - purchaseAmount + a, 100 - purchaseAmount - (10 - a));
    }
    else
        return 100 - purchaseAmount - (10 - a);
    return -1;
}


int main(int argc, char **argv)
{
    std::cout << accountBalanceAfterPurchase(11) << std::endl;
    std::cout << accountBalanceAfterPurchase(19) << std::endl;
    std::cout << accountBalanceAfterPurchase(15) << std::endl;
    return 0;
}
