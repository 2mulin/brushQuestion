/**
 * @date 2024/11/23
 * @author 2mu
 * @brief easy 求出胜利玩家的数目
 *
 * 1. 模拟
 * 按照题目意思进行模拟。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 
 * 
 * 2. 二维数组
 * 官方题解使用二维数组，明显更加简单，清晰。
 * 行号玩家，列号表示某颜色的球。值表示球的数量。
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <tuple>


using namespace std;


int winningPlayerCount(int n, vector<vector<int>> &pick)
{
    int winning = 0;
    std::vector<std::vector<int>> ball_cnt(n, std::vector<int>(11));
    
    for(std::vector<int>& p : pick)
    {
        int player = p[0], ball = p[1];
        ++ball_cnt[player][ball];
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 11; ++j)
        {
            if(ball_cnt[i][j] > i)
            {
                ++winning;
                break;
            }
        }
    }
    return winning;
}


// struct MyHash
// {
//     std::size_t operator()(const std::tuple<int, int>& tup)const noexcept
//     {
//         // 0 < n < 10，所以足够了
//         return std::get<0>(tup) * 100 + std::get<1>(tup);
//     }
// };


// int winningPlayerCount(int n, vector<vector<int>> &pick)
// {
//     std::unordered_set<int> winning; // 胜者的集合，避免重复

//     // key是 <玩家, 颜色> value是数量
//     std::unordered_map<std::tuple<int, int>, int, MyHash> ma_count;
//     for(std::vector<int>& player_color : pick)
//     {
//         std::tuple<int, int> tup(player_color[0], player_color[1]);

//         // 有些平台可能无法使用 [] 查询key为tuple的map
//         auto iter = ma_count.find(tup);
//         if (iter != ma_count.end())
//         {
//             iter->second++;
//             // 用==，这样就不会重复添加胜利玩家了
//             if (iter->second == player_color[0] + 1)
//             {
//                 winning.insert(std::get<0>(tup));
//             }
//         }
//         else
//         {
//             ma_count.insert({tup, 1});
//             if (1 == player_color[0] + 1)
//             {
//                 winning.insert(std::get<0>(tup));
//             }
//         }
//     }
//     return int(winning.size());
// }


int main(int argc, char **argv)
{
    std::vector<std::vector<int>> commands = {{0, 0}, {1, 0}, {1, 0}, {2, 1}, {2, 1}, {2, 0}};
    std::cout << winningPlayerCount(4, commands) << std::endl;
    return 0;
}
