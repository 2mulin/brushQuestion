/**
 * @date 2023/12/29
 * @author 2mu
 * @brief easy 购买两块巧克力
 *
 * 1. 遍历
 * 使用两个变量记录价格最低的两块巧克力价格, 直接遍历一遍prices数组, 得到最低价格的两块巧克力价格
 * 然后判断下 money 够不够买;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int buyChoco(vector<int> &prices, int money)
{
    int first_low_price = 0, second_low_price = 0;
    for(int price : prices)
    {
        if(first_low_price == 0)
        {
            first_low_price = price;
        }
        else if(second_low_price == 0)
        {
            second_low_price = price;
            if(second_low_price < first_low_price)
                std::swap(second_low_price, first_low_price);
        }
        else if(first_low_price > price)
        {
            second_low_price = first_low_price;
            first_low_price = price;
        }
        else if(second_low_price > price)
        {
            second_low_price = price;
        }
        else
        {
            continue;
        }
    }
    // 买完巧克力后, 可以剩余的钱
    int rest = money - (first_low_price + second_low_price);
    return rest >= 0 ? rest : money;
}

int main()
{
    std::vector<int> prices{3,2,3};
    std::cout << buyChoco(prices, 3) << std::endl;
    prices  = {90,29,6,74};
    std::cout << buyChoco(prices, 82) << std::endl;
    return 0;
}