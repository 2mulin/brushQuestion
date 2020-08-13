/*******************************************************************************
 * @author reddragon
 * @date 2020/8/12
 * @brief medium 格雷码
 * 转化格雷码是有规律的，就当长见识了，不好记。
 *******************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> grayCode(int n)
{
    if (n == 0)
        return vector<int>(1, 0);
    int size = 1;
    size <<= n;// n位二进制最多表示的数
    vector<int> ans(size);
    for (int i = 1; i < size; i++)
        ans[i] = (i ^ (i >> 1));// 灵魂所在，反正我看不懂
    return ans;
}

int main()
{
    vector<int> ans = grayCode(3);
    for (auto i : ans)
        cout << i << '\t';
    return 0;
}