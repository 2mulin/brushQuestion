/***************************************************************************
 * @date 2020/7/17
 * @author reddragon
 * @description: medium 螺旋打印矩阵
 * 直接看代码。注释都写了，没什么难的，就是注意细节。
 ****************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int top = 0, left = 0;                 // 左上坐标
    int button = row - 1, right = col - 1; // 右下坐标
    while (top <= button && left <= right)
    {
        for (int i = left; i <= right; ++i)
            ans.push_back(matrix[top][i]);
        for (int i = top + 1; i <= button; ++i)
            ans.push_back(matrix[i][right]);
        if(left < right && top < button)
        {// 防止矩阵只有一行或一列的时候, 重复访问
            for (int i = right - 1; i > left; --i)
                ans.push_back(matrix[button][i]);
            for (int i = button; i > top; --i)
                ans.push_back(matrix[i][left]);
        }
        top++;
        button--;
        left++;
        right--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(arr);
    for (auto it : ans)
        cout << it;
    return 0;
}
