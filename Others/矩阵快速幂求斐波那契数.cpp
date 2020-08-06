/*********************************************************************
创建时间：2020/3/6
矩阵快速幂求斐波那契数
主要用到了矩阵乘法，位运算，快速幂的原理和这个相同，就是a的b次方，b可以
转换位二进制进行运算，只有当二进制中该位为1的时候，才会乘a，很细节的东西
*********************************************************************/

#include <iostream>
using namespace std;

const int len = 2;

struct node
{
    int mat[len][len];
    void init()
    {
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
    }
};

// 矩阵乘法，时间复杂度O(n^3)
node mul(node x, node y)
{
    node temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            temp.mat[i][j] = 0;
            // 一行乘与一列的和（矩阵乘法）
            for (int k = 0; k < len; k++)
            {
                temp.mat[i][j] += (x.mat[i][k] * y.mat[k][j]);
                temp.mat[i][j] %= 10000;
            }
        }
    }
    return temp;
}

// 矩阵快速幂
node matpow(node x, long num)
{
    node ans;
    ans.init();
    while (num)
    {
        if (num & 1)
        {
            ans = mul(ans, x);
        }
        x = mul(x, x);
        num >>= 1;
    }
    return ans;
}

int main()
{
    long n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        node x;
        x.init();
        node ans = matpow(x, n);
        cout << ans.mat[1][1] << endl;
    }
    return 0;
}