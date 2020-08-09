/*******************************************************************************
 * @author reddragon
 * @date 2020/8/9
 * @brief hard 柱状图里最大的矩形面积
 * 自己想的暴力解法是真垃圾，官方连暴力解法都比我的好，多多反思
 * 费时一上午，通过研究题解，终于知道了单调栈，在这里怎么用。
 * 后面发现可以不使用stack，也可以算，速度还快些，是单调栈的思路，但是不需要辅助stack
 * 
 * 题解还有一个for一次就可以得到left和right数组的优化
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// 暴力解法：时间O(n*n*n) 空间O(1)
// inline int getMinHeight(vector<int> &heights, int i, int j)
// {
//     int res = INT_MAX;
//     for (int k = i; k <= j; k++)
//         if (heights[k] < res)
//             res = heights[k];
//     return res;
// }

// int largestRectangleArea(vector<int> &heights)
// {
//     if (heights.empty())
//         return 0;
//     int ans = 0;
//     int size = heights.size();
//     vector<int> arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             int minH = getMinHeight(heights, i, j);
//             ans = max(ans, minH * (j - i + 1));
//         }
//     }
//     return ans;
// }

// 暴力解法， 时间O(N*N),空间O(1)
// int largestRectangleArea(vector<int> &heights)
// {
//     int size = heights.size();
//     if(size == 0)
//         return 0;
//     int res = 0;
//     for(int i = 0; i < size; i++)
//     {
//         int left = i , right = i;
//         while(left >= 0 && heights[left] >= heights[i])
//             left--;
//         while(right < size && heights[right] >= heights[i])
//             right++;
//         res = max(res, heights[i] * (right - left - 1));
//     }
//     return res;
// }

// 利用单调栈求出left数组和right数组
int largestRectangleArea(vector<int> &heights)
{
    int size = heights.size();
    if (size == 0)
        return 0;
    vector<int> left(size), right(size);
    // left记录的是左边离当前位置最近的元素值小于当前元素值的位置
    stack<int> s; //辅助计算的单调栈
    s.push(-1);   // 设置哨兵
    for (int i = 0; i < size; i++)
    {
        // 直接算，不使用stack
        // int pre = i - 1;
        // while(pre != -1 && heights[pre] >= heights[i])
        //     pre = left[pre];
        // left[i] = pre;
        while (s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();
        left[i] = s.top(); //记录左边离当前位置最近的且小于当前高度的位置
        s.push(i);
    }
    while (!s.empty())
        s.pop();

    s.push(size); // 设置哨兵
    // right记录的是右边离当前位置最近的元素值小于当前元素值的位置
    for (int i = size - 1; i >= 0; i--)
    {
        // 可以直接算，不需要stack，速度还快些
        // int next = i + 1;
        // while (next < size && heights[next] >= heights[i])
        //     next = right[next];
        // right[i] = next;
        while (s.top() != size && heights[s.top()] >= heights[i])
            s.pop();
        right[i] = s.top(); //记录右边离当前位置最近的且小于当前高度的位置
        s.push(i);
    }

    int res = -1;
    for (int i = 0; i < size; i++)
    {
        if (right[i] != size && left[i] != -1)
        { // 两边都没有到达边界
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        else if (right[i] == size && left[i] != -1)
        { // 到达了右边界
            res = max(res, (size - left[i] - 1) * heights[i]);
        }

        else if (right[i] != size && left[i] == -1)
        { // 到达了左边界
            res = max(res, (right[i]) * heights[i]);
        }
        else
        { // 跨越整个数组长度
            res = max(res, size * heights[i]);
        }
    }
    return res;
}

int main()
{
    vector<int> arr{9,0};
    cout << largestRectangleArea(arr);
    return 0;
}