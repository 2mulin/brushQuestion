/***************************************************
 * @date 2020/7/14
 * @author reddragon
 * @descripation:旋转数组 中等
 * 1 .先延对角线对称交换
 * 2 .每一个行对称交换
 * 时间复杂度：O(n*n)   空间复杂度：O(1)
 ***************************************************/
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    // 延对角线对称交换
    for (int i = 0; i < matrix.size(); i++)
    {
        // 从i+1开始才是对的
        for (int j = i + 1; j < matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 每一个行对称交换
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size() / 2; j++)
        {
            swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
        }
    }
}

int main()
{
    vector<vector<int>> arr{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(arr);
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr.size(); j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}