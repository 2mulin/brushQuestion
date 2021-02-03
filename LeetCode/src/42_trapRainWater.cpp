/***************************************************************************
 * @date 2020/7/11
 * @author reddragon
 * @description: hard 第42题:接雨水
 * 以下两个算法都是每次计算一个height[i]所在的那一列所能接的雨水,而不是一个区域的算
 * 这也是我最开始没有思路的原因
 * 1. 暴力法：
 * 当前格子所在若是可以接雨水，那么此格子左右必然还有比它高的其他格子。
 * 取左右格子小的那一个高度与当前格子高度做减法，就可以算出当前格子所在列能够接到的
 * 雨水
 * 时间复杂度：O(n*n) 空间复杂度O(1)
 * 
 * 2. 标记数组：
 * 使用left_max和right_max记录当前位置左或右边最大的高度。
 * 优化暴力法，每个都要搜索一次的缺陷。
 * 时间复杂度：O(n) 空间复杂度O(2*n)
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

// 优化
int trap(vector<int> &height)
{
    if (height.size() <= 2)
        return 0;
    vector<int> left_max(height.size(), 0);  //表示当前位置左边最大的数
    vector<int> right_max(height.size(), 0); //表示当前位置右边最大的数
    for (int i = 1; i < left_max.size(); i++)
    {
        left_max[i] = max(height[i - 1], left_max[i - 1]);
    }
    for (int i = right_max.size() - 2; i >= 0; i--)
    {
        right_max[i] = max(height[i + 1], right_max[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i < height.size() - 1; i++)
    {
        // 左右都比当前高，才会盛水
        if (left_max[i] > height[i] && right_max[i] > height[i])
            ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}

// 暴力 时间O(n*n) 空间O(1)
// int trap(vector<int> &height)
// {
//     int ans = 0;
//     for (int i = 1; i < height.size() - 1; i++)
//     {
//         int left_max = 0, right_max = 0;
//         for (int j = 0; j < i; j++)
//             left_max = max(left_max, height[j]);
//         for (int j = i + 1; j < height.size(); j++)
//             right_max = max(right_max, height[j]);
//         // 左右都比当前高，才会盛水
//         if (left_max > height[i] && right_max > height[i])
//             ans += min(left_max, right_max) - height[i];
//     }
//     return ans;
// }

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(arr) << endl;
    return 0;
}
