/***************************************************************************
 * @date 2020/7/6
 * @author reddragon
 * @description: medium 有效的数独
 * 给一个9*9格子，判断是否满足数独要求
 * 
 * 利用一个标记数组标记1-9，然后行遍历，列遍历，九宫格遍历就完事了
 * 时间复杂度：O(243) 空间复杂度O(1)
 * 
 * leetcode官方题解遍历方法不一样
 * 它只要遍历一次就OK了 O(81)
 * 
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    bool arr[10]; // false表示数字没有出现过

    for (int i = 0; i < 9; i++)
    {
        for (int i = 0; i < 10; i++)
            arr[i] = false;
        // 检查行
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (arr[board[i][j]])
                return false; //出现过，说明重复了
            else
                arr[board[i][j]] = true;
        }
        for (int i = 0; i < 10; i++)
            arr[i] = false;
        // 检查列
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] == '.')
                continue;
            if (arr[board[j][i]])
                return false;
            else
                arr[board[j][i]] = true;
        }
    }

    for (int i = 0; i < 8; i += 3)
    {
        for (int j = 0; j < 8; j += 3)
        {
            for (int i = 0; i < 10; i++)
                arr[i] = false;
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    if (board[x][y] == '.')
                        continue;
                    if (arr[board[x][y]])
                        return false;
                    else
                        arr[board[x][y]] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> nums{{'5', '3', '.', '7', '.', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '8', '7', '.', '.', '.'},
                              {'.', '8', '7', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'5', '3', '.', '.', '.', '.', '.', '.', '.'},
                              {'5', '3', '.', '.', '.', '.', '.', '.', '.'},
                              {'5', '3', '.', '.', '.', '.', '.', '.', '.'},
                              {'5', '3', '.', '.', '.', '.', '.', '.', '.'},
                              {'5', '3', '.', '.', '.', '.', '.', '.', '.'}};
    cout << isValidSudoku(nums);
    return 0;
}
