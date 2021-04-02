/********************************************************************************************
 * @author reddragon
 * @date 2021/4/2
 * @brief medium 接雨水
 * 
 * 1，动态规划
 * 一个点能够存水的要求就是左右两边都有比他高的点.
 * 所以使用两个dp数组. 记录两边的高度的最大值.
 * 最后一次遍历就完成了
 * 前面这个数组可以优化,不需要, 用一个int表示就行了
 * 时间复杂度: O(N)        空间复杂度: O(2N)
 * 
 * 2. 双指针
 * 分别使用两个数表示左右两边的柱子当前值.如果leftMax < rightMax,
 * 那么就以右边最大值为边界, 从左往右走
 * 只要当前height[i] < leftMax, 那么这个位置就可以积水, 如果比leftMax大,那就更新leftMax
 * 当leftMax > rightMax的时候, 那就以leftMax为边界, 从右往左走
 * 只要当前height[i] > rightMax, 那么这个位置就可以积水.
 * 时间复杂度: O(N)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height)
{
    int sz = height.size();
    // 2个以下的元素, 无法存水
    if(sz <= 2)
        return 0;
    int leftMax = height[0];  // 一个数表示, 节省空间
    vector<int> rightMax(sz, 0); // i ~ sz-i范围最高点
    // 单调栈初始化
    rightMax[sz - 1] = height[sz - 1];
    for (int i = sz - 2; i >= 0; --i)
        rightMax[i] = max(rightMax[i + 1], height[i]);
    // 计算容量
    int ret = 0;
    for (int i = 1; i < sz - 1; ++i)
    {
        leftMax = max(leftMax, height[i]);
        int minHigh = min(leftMax, rightMax[i]);
        if (height[i] < minHigh)
            ret += (minHigh - height[i]);
    }
    return ret;
}

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(arr) << endl;
    return 0;
}