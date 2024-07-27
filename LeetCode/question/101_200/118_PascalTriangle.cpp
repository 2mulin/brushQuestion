/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/14
 * @brief easy 杨辉三角
 * 1. 好像挺简单的
*******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    if (numRows <= 0)
        return ans;
    vector<int> one(1, 1);
    ans.push_back(one);
    for (int i = 1; i < numRows; i++)
    {
        vector<int> temp(i + 1);
        temp[0] = ans[i - 1][0];
        temp[i] = ans[i - 1][i - 1];
        for (int j = 1; j < i; j++)
            temp[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}