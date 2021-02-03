/*******************************************************************************
 * @author reddragon
 * @date 2020/8/6
 * @brief 单词搜索 medium
 * dfs：从任何一个点开始作为起点搜索，上下左右搜索。
 * 算是一个挺正常的搜索。
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(int x, int y, vector<vector<char>> &board, size_t len, string word, vector<vector<bool>> &isVisit)
{
    if (len == word.length())
        return true;
    // 四个方向
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];
        // 不能越界
        if (newX >= board.size() || newX < 0)
            continue;
        if (newY >= board[newX].size() || newY < 0)
            continue;
        // 若是已经访问过，不等于接下来字母。此路不通
        if (isVisit[newX][newY] || board[newX][newY] != word[len])
            continue;
        // isVisit回溯
        isVisit[newX][newY] = true;
        if (dfs(newX, newY, board, len + 1, word, isVisit))
            return true;
        isVisit[newX][newY] = false;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word.empty())
        return true;
    size_t row = board.size();
    if (row == 0)
        return false;
    size_t col = board[0].size();
    vector<vector<bool>> isVisit(row, vector<bool>(col, false));
    // 二维数组任何一个点都可以是起点
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            isVisit[i][j] = true;
            if (board[i][j] == word[0] && dfs(i, j, board, 1, word, isVisit))
                return true;
            isVisit[i][j] = false;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << exist(board, word);
    return 0;
}