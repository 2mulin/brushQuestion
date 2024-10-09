/**
 * @author ling
 * @date 2021/6/15
 * @brief easy 山脉数组最高的索引
 * 
 * 1.遍历一遍
 * 遍历一遍直到递增变成了递减.
 * 时间复杂度：O(N)             空间复杂度：O(1)
 * 
 * 2.二分查找
 * 找到最小的arr[i] > arr[i + 1]
 * 时间复杂度: O(logN)          空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int left = 1, right = n - 2, ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] > arr[mid + 1])
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int peakIndexInMountainArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] >= arr[i + 1])
            return i;
    }
    return 0;
}

int main()
{
    return 0;
}