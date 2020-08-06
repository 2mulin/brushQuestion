/**********************************************
 * @author reddragon
 * @date 2020/7/23
 * @brief hard n皇后II
 * 和上一题一样，还是回溯。不过是返回合法放置数目而已
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

void backtrack(vector<string> &board, int row, int &res)
{
    //所有行选定
    if (row == board.size())
    {
        res++;
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

int totalNQueens(int n)
{
    int ans = 0;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, ans);
    return ans;
}

int main()
{
    int ans = totalNQueens(9);
    cout << ans << endl;
    return 0;
}