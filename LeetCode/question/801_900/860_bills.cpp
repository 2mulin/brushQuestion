/**
 * @date 2023/7/22
 * @author 2mu
 * @brief easy 柠檬水找零
 * 
 * 1. 模拟
 * 
 * 按照要求模拟就行, 遍历每一个用户, 如果无法给当前用户找零; 那就直接返回false;
 * 钞票只有3种面额, 5美元, 10美元, 20美元; 记录收到的各种面额钞票的数量;
 * 
 * 需要有一点点 贪心的思路, 碰到20元面额找零时, 尽量把10元面额的钞票找零给用户; 这样给所有用户找零的概率才高;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int m5 = 0, m10 = 0, m20 = 0;
    for(auto bill : bills)
    {
        if(bill == 5)
        {
            ++m5;
        }
        else if(bill == 10)
        {
            if(m5 > 0)
            {
                --m5;
                ++m10;
            }
            else
                return false;
        }
        else if(bill == 20)
        {
            // 需要有一点点 贪心的思路, 这里尽量把 10 元面额的钞票 找零给用户; 这样全部找零的概率才高;
            if(m5 > 0 && m10 > 0)
            {
                --m5;
                --m10;
                ++m20;
            }
            else if(m5 >= 3)
            {
                m5 -= 3;
                ++m20;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    std:vector<int> bills = {5, 5, 5, 10, 20};
    std::cout << lemonadeChange(bills) << std::endl;
    bills = {5, 5, 10, 10, 20};
    std::cout << lemonadeChange(bills) << std::endl;
    bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    std::cout << lemonadeChange(bills) << std::endl;
    return 0;
}
