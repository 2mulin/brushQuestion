/********************************************************************************************
 * @author reddragon
 * @date 2020/11/3
 * @brief easy 有效的山脉数组
 * 1. 穷举
 * 假设每一个元素是不是山脉数组的顶点，然后判断是否满足
 * 时间复杂度：O(N*N)        空间复杂度：O(N)
 * 
 * 2. 线性扫描
 * 按照题意，先递增，然后到顶点，然后递减
 * 所以可以直接判断，是按照上面的规则，那就是true
 * 时间复杂度: O(N)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

// 线性扫描
bool validMountainArray(vector<int> &A)
{
    if (A.empty())
        return false;
    size_t i = 0;
    while(i + 1 < A.size())
    {
        if (A[i] >= A[i + 1])
            break;
        ++i;
    }
    // 最高点不能是起点或者终点
    if (i == 0 || i == A.size() - 1)
        return false;
    ++i;
    while (i < A.size())
    {
        if (A[i - 1] <= A[i])
            return false;
        ++i;
    }
    return true;
}

// 最笨的方法，O(n*n)
/* bool validMountainArray(vector<int> &A)
{
    if (A.empty())
        return false;
    bool ans = true;
    for (int i = 1; i < A.size() - 1; ++i)
    {
        ans = true;
        if (A[0] >= A[i] || A[i + 1] >= A[i])
        {
            ans = false;
            continue;
        }
        // 前面的每一个数都必须比它小，并且是单调递增的
        for (int j = 1; j < i; ++j)
        {
            if (A[j] > A[i] || A[j] <= A[j - 1])
            {
                ans = false;
                break;
            }
        }
        // 后面的每一个数都必须比它小，并且是单调递减的。
        for (int j = i + 1; j < A.size(); ++j)
        {
            if (A[j] > A[i] || A[j] >= A[j - 1])
            {
                ans = false;
                break;
            }
        }
        if (ans)
            return ans;
    }
    return false;
} */

int main()
{
    vector<int> arr{1, 2, 2, 3};
    cout << validMountainArray(arr) << std::endl;
    return 0;
}