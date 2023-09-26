/**
 * @date 2023/9/26
 * @author 2mu
 * @brief 递枕头 easy
 *
 * 1. 模拟
 * 直接n 整除 time, 就可以知道有几个来回, 结果是奇数, 则最后一次从后往前;
 * 结果是偶数, 则最后一次 从前往后; 然后取余得到余数, 就知道是第几个了;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int passThePillow(int n, int time)
{
    int div = time / (n - 1);
    int cnt = time % (n - 1);
    if(div % 2)
    {
        return n - cnt;
    }
    else
    {
        return 1 + cnt;
    }
}

int main()
{
    std::cout << passThePillow(4, 5) << std::endl;
    std::cout << passThePillow(18, 38) << std::endl;
    return 0;
}
