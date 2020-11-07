/********************************************************************************************
 * @author reddragon
 * @date 2020/11/7
 * @brief easy 逆序数
 * 
 * 1. 归并排序求逆序对
 * 首先最简单的思路就是双层for循环每两个进行一次比较。
 * 但是这里可以使用归并排序的思想，每次在归并的时候，就可以快速计算
 * 因为归并的时候两个数组都是有序的，所以说，如果左边数组的大于右边数组的数
 * 那么说明左边数组在该数后面的数都会大于该数，也就是全都是逆序对。
 * 在44行代码。
 * 时间复杂度：O(NlogN)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

int func(vector<int>& arr, int low, int high)
{
    int count = 0;
    if(low >= high)
        return 0;
    // 分
    int mid = (low + high + 1) / 2 - 1;
    count += func(arr, low, mid);
    count += func(arr, mid + 1, high);

    // 合
    vector<int> temp(high - low + 1);
    int i = low,j = mid + 1;
    int k = 0;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            ++i;
        }
        else
        {
            temp[k] = arr[j];
            ++j;
            count += (mid - i + 1); // 答案
        }
        ++k;
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];

    k = 0;
    for(int i = low; i <= high; ++i)
        arr[i] = temp[k++];
    return count;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int j = 0; j < n; ++j)
            cin >> arr[j];
        cout << "Scenario #" << i << ":" << std::endl;
        cout << func(arr, 0, arr.size() - 1) << std::endl;
        cout << std::endl;
    }
    return 0;
}