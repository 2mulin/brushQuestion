/*******************************************************************************************
 * @author reddragon
 * @date 2020/9/15
 * @brief easy 杨辉三角II
 * 
 * 1. 模拟
 * 就是模拟杨辉三角, 每次上面左右两个数字之和就是当前值
 * 时间复杂度: O(n*n)      空间复杂度: O(n*n)
 * 
 * 2. 滚动数组
 * 逆向思维, 首先发现从后往前加比较好, 
 * 时间复杂度: O(N*N)      空间复杂度: O(n)
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 滚动数组实现
vector<int> getRow(int rowIndex)
{
    vector<int> ret(rowIndex + 1, 0);
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    return ret;
}

// vector<int> getRow(int rowIndex)
// {
//     vector<vector<int>> arr;
//     vector<int> ans;

//     vector<int> one(1, 1);
//     arr.push_back(one);
//     for (int i = 1; i < rowIndex + 1; i++)
//     {
//         vector<int> temp(i + 1);
//         temp[0] = arr[i - 1][0];
//         temp[i] = arr[i - 1][i - 1];
//         for (int j = 1; j < i; j++)
//             temp[j] = arr[i - 1][j] + arr[i - 1][j - 1];
//         arr.push_back(temp);
//     }
//     return arr[rowIndex];
// }

int main()
{

    return 0;
}