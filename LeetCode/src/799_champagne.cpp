/**
 * @date 2022/11/20
 * @author 2mu
 * @brief medium 香槟塔
 * 
 * 一. 模拟
 * 
 * 固定100层的香槟塔，所以这里使用数组模拟。当父节点“溢出”时，
 * 分别平分的往左右孩子增加。
 * 
 * 每次添加1，都往左右孩子增加，会导致超时。因为添加1的次数可能上亿次。
 * 
 * 所以这里直接先所有体积添加到顶层杯子，再将溢出的平分添加到左右杯子中。
 * 每次必须求完一整层，再去求下一层。避免重复遍历每一层。
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<double> row = {(double)poured};// 当前行的杯子，以及每个杯子对应容量

    // 注意for循环的终止条件，算到这一行，已经没必要往下走了。
    for (int i = 1; i <= query_row; i++)
    {
        vector<double> nextRow(i + 1, 0.0);
        for (int j = 0; j < row.size(); j++)
        {
            double volume = row[j];
            if (volume > 1)
            {
                double tmpVal = (volume - 1) / 2;
                nextRow[j] += tmpVal;
                nextRow[j + 1] += tmpVal;
            }
        }
        row = nextRow;
    }
    return min(1.0, row[query_glass]);
}

int main()
{
    // std::cout << champagneTower(2, 1, 1) << std::endl;
    // std::cout << champagneTower(100000009, 33, 17) << std::endl;
    std::cout << champagneTower(1000000000, 99, 99) << std::endl;
    return 0;
}
