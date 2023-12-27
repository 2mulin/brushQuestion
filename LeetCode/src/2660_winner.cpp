/**
 * @date 2023/12/27
 * @author 2mu
 * @brief easy 保龄球游戏的获胜者
 *
 * 1. 遍历
 * 记录最后一个命中10球的数组idx, 然后每次都和当前位置进行比较, 距离 <= 2 就可以双倍得分;
 * 只需要遍历一遍, 时间复杂度O(n); 并且只使用了2个变量, 空间复杂度O(1)
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;


int getPlayerScore(const std::vector<int>& player)
{
    int score = 0;
    int bowling_idx = -3; // 当前最近一次10球全中, 在数组中的位置
    for(size_t i = 0; i < player.size(); ++i)
    {
        if(i - bowling_idx <= 2)
            score = score + (player[i] << 1);
        else
            score = score + player[i];
        if(player[i] == 10)
            bowling_idx = i;
    }
    return score;
}

int isWinner(vector<int> &player1, vector<int> &player2)
{
    int player1_score = getPlayerScore(player1), player2_score = getPlayerScore(player2);
    if(player1_score > player2_score)
        return 1;
    else if(player1_score < player2_score)
        return 2;
    return 0;
}

int main()
{
    std::vector<int> player1 = {4, 10, 7, 9}, player2 = {6, 5, 2, 3};
    std::cout << isWinner(player1, player2) << std::endl;
    return 0;
}