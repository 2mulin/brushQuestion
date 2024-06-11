/**
 * @date 2024/6/11
 * @author 2mu
 * @brief medium 甲板上的战舰
 *
 * 1. 顺序遍历 + bfs
 * 我们按照从左到右, 从上到下遍历; 初始count为0, 表示当前统计到的战舰数量;
 * 每次遍历都会判断当前位置的左上方是否存在'X', 注意题目不包括左斜上方, 如果不存在, count++, 如果存在, 说明相邻已经被统计过, 不需要重复统计;
 * 遍历完之后, count就是战舰总数;
 * 
 * 时间复杂度: O(m * n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <thread>


using namespace std;


int countBattleships(vector<vector<char>> &board)
{
    int count = 0;
    std::vector<std::vector<int>> direction = {
        {-1, 0},
        {0, -1}
    };
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] == 'X')
            {
                bool repeated = false;
                for(auto direct : direction)
                {
                    int x = i + direct[0], y = j + direct[1];
                    if(x >= 0 && y >= 0 && board[x][y] == 'X')
                    {
                        repeated = true;
                        break;
                    }
                }
                if(!repeated)
                    ++count;
            }
        }
    }
    return count;
}


int main(int argc, char **argv)
{
    std::vector<std::vector<char>> board = {
        {'X', '.', '.', 'X'}, 
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', '.'}
    };
    std::cout << countBattleships(board) << std::endl;
    return 0;
}
