/***************************************************************************
 * @date 2020/7/17
 * @author reddragon
 * @description: midden 螺旋打印矩阵
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
    int row = matrix.size();
    if (row == 0)
        return ans;
    int col = matrix[0].size();
    // 左上角(top,left), 右上角(top,right), 左下角(bottom,left), 右下角(bottom,right)
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    // 一个循环读掉最外层的一圈
    while (left <= right && top <= bottom)
    {
        // 上。注意是读完整行
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        // 右。注意是读完整列
        for (int i = top + 1; i <= bottom; i++)
            ans.push_back(matrix[i][right]);

        if (left < right && top < bottom)
        {
            // 下，留最后一个
            for (int i = right - 1; i > left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            // 左，留最后一个，最后一个读过了
            for (int i = bottom; i > top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            // 1圈之后，二维数组变小了
        }
        left++;
        right--;
        top++;
        bottom--;
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
