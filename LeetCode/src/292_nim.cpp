/**
 * @date 2023/2/4
 * @author 2mu
 * @brief easy nim游戏
 *
 * 1. 数学推理
 * 简单题, 可以发现如果石头只有1,2,3; 那么作为先手的人稳赢; 如果石头为4, 那么后手的人稳赢;
 * 然后继续往后推, 只要是石头数量是4的倍数, 那么先手的人稳输;
 * 
 * 具体数学推理就没有, 这题对于我来说就是找规律而已;
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool canWinNim(int n)
{
    if (n % 4)
        return true;
    return false;
}

int main()
{
    std::cout << canWinNim(3) << std::endl;
    return 0;
}