/*
 * @author ling
 * @date 2021/5/21
 * @brief medium 不相交的线
 * 
 * 1. dp
 * 仔细分析题目就可以发现是一个dp,然后哦再仔细分析题目就可以发现这就是求最长公共子序列
 * 因为每条线不能相交,上下数字相等,这就公共子序列.
 * 求最长公共子序列使用二维dp
 * dp[i][j]表示nums1[0~i]和nums2[0~j]的最长公共子序列的长度.
 * 时间复杂度： O(M*N)        空间复杂度：O(M*N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp
int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();
    if(size1 == 0 || size2 == 0)
        return 0;
    vector<vector<int>> dp(size1, vector<int>(size2, 0));

    // 初始化第一行第一列
    if(nums1[0] == nums2[0])
        dp[0][0] = 1;
    for(int i = 1; i < size1; ++i)
    {
        if(nums1[i] == nums2[0])
            dp[i][0] = 1;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for(int i = 1; i < size2; ++i)
    {
        if(nums2[i] == nums1[0])
            dp[0][i] = 1;
        else
            dp[0][i] = dp[0][i - 1];
    }

    //dp
    for(int i = 1; i < size1; ++i)
    {
        for(int j = 1; j < size2; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(nums1[i] == nums2[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[size1 - 1][size2 - 1];
}

int main()
{
    vector<int> nums1{1,4,2};
    vector<int> nums2{1,2,4};
    cout << maxUncrossedLines(nums1, nums2) << endl;
    return 0;
}