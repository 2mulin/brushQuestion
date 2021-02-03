/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/15
 * @brief easy 杨辉三角II
 * 1. 好像也挺简单的，和第一题
*******************************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<vector<int>> arr;
    vector<int> ans;

    vector<int> one(1, 1);
    arr.push_back(one);
    for (int i = 1; i < rowIndex + 1; i++)
    {
        vector<int> temp(i + 1);
        temp[0] = arr[i - 1][0];
        temp[i] = arr[i - 1][i - 1];
        for (int j = 1; j < i; j++)
            temp[j] = arr[i - 1][j] + arr[i - 1][j - 1];
        arr.push_back(temp);
    }
    return arr[rowIndex];
}

int main()
{

    return 0;
}