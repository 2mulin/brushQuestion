// LCS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;

/*
#pragma region 第一种算法：递归
string A;        //字符串1
string B;        //字符串2

int LCS(int i, int j)
{
    //退出递归
    if (i == -1 || j == -1)
        return 0;
    if (A[i] == B[j])
    {
        return 1 + LCS(i - 1, j - 1);
    }
    else
    {
        int num1 = LCS(i - 1, j);
        int num2 = LCS(i, j - 1);
        return num1 > num2 ? num1 : num2;
    }
}

int main()
{
    while (cin >> A >> B)
    {
        int ans = LCS(A.length() - 1, B.length() - 1);
        cout << ans << std::endl;
    }
    return 0;
}

#pragma endregion
*/


#pragma region 第二种算法：动态规划
int** dp;               //记录公共子序列的长度
string A;               //字符串1
string B;               //字符串2


int main()
{
    while (cin >> A >> B)
    {
        int lenA = A.length();
        int lenB = B.length();
        //动态分配
        dp = new int* [lenA + 1];
        for (int i = 0; i < lenA+1; i++)
        {
            dp[i] = new int[lenB + 1];
        }
        //初始化为0
        for (int i = 0; i < lenA+1; i++)
        {
            for (int j = 0; j < lenB+1; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i < lenA+1; i++)
        {
            for (int j = 1; j < lenB+1; j++)
            {
                //相等就是左斜对角+1，不相等就是左边和上方最大的那个。
                if (A[i-1] == B[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        cout << dp[lenA][lenB] << std::endl;

        /*for (int i = 0; i < lenA+1; i++)
        {
            for (int j = 0; j < lenB+1; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }*/
        delete[] dp;
    }
    return 0;
}
#pragma endregion