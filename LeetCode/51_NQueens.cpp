/**********************************************
 * @author reddragon
 * @date 2020/7/25
 * @brief hard n皇后
 * 回溯。
 * 主要是注意写法。具体看代码
 **********************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 判断当前棋盘(row,col)放置皇后是否合法
bool isVaild(vector<string> &broad, int row, int col)
{
    int n = broad.size();
    // 检查同一列
    for (int i = 0; i < row; i++)
    {
        if (broad[i][col] == 'Q')
            return false;
    }
    // 右上对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (broad[i][j] == 'Q')
            return false;
    }
    // 左上对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (broad[i][j] == 'Q')
            return false;
    }
    return true;
}

// 回溯
void backtrack(vector<string> &board, int row, vector<vector<string>> &res)
{
    //所有行选定
    if (row == board.size())
    {
        res.emplace_back(board);
        return;
    }

    int n = board[row].size();
    for (int col = 0; col < n; col++)
    {
        if (!isVaild(board, row, col))
            continue;

        board[row][col] = 'Q';
        backtrack(board, row + 1, res);
        board[row][col] = '.';
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, res);
    return res;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(9);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "第" << i << "种合法方式：" << endl;
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}