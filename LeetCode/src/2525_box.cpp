/**
 * @date 2023/10/20
 * @author 2mu
 * @brief easy 根据规则将箱子分类
 *
 * 1. 模拟
 * 安装题目要求模拟, 返回结果即可;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

string categorizeBox(int length, int width, int height, int mass)
{
    std::string ans = "Neither";
    // 防止溢出
    long long volume = (long long)length * width * height;
    if(length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9)
    {
        ans = "Bulky";
    }
    if(mass >= 100)
    {
        if(ans == "Bulky")
            ans = "Both";
        else
            ans = "Heavy";
    }
    return ans;
}

int main()
{
    std::cout << categorizeBox(1000, 35, 700, 300) << std::endl;
    return 0;
}
