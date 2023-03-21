/**
 * @date 2022/3/21
 * @author 2mu
 * @brief easy 温度转换
 *
 * 一. 直接计算
 * 用点小技巧，增加数字倍数，计算完后在减小，避免除法导致的误差。
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> convertTemperature(double celsius)
{
    std::vector<double> ans(2, 0);
    ans[0] = celsius + 273.15;
    ans[1] = (celsius * 100 * 180) / 10000 + 32.00;
    return ans;
}

int main()
{
    std::vector<double> ans = convertTemperature(122.11);
    for(auto temperature : ans)
        std::cout << temperature << std::endl;
    return 0;
}
