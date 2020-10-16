/********************************************************************************************
 * @author reddragon
 * @date 2020/10/18
 * @brief easy 有序数组的平方
 * 
 * 1. 归并的思想
 * 先找到数组中最接近0的数的下标，然后利用双指针实现归并排序时的归并操作就可以了。
 * 时间复杂度: O(N)     空间复杂度: O(N)
 * 
 * 2. 改进
 * 找到数组中最接近0的数的下标需要时间，可以从后往前，放着来，先找最大的，省去了时间
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int> &A)
{
    int len = A.size();
    vector<int> ans(len);

    int k = len - 1;// 先找最大的
    int i = 0, j = len - 1;
    while (j != i)
    {
        if (A[i] * A[i] > A[j] * A[j])
        {
            ans[k--] = A[i] * A[i];
            i++;
        }
        else
        {
            ans[k--] = A[j] * A[j];
            j--;
        }
    }
    return ans;
}

/* vector<int> sortedSquares(vector<int> &A)
{
    int len = A.size();
    vector<int> ans(len);

    int mid = 0;
    // 是先判断，在访问，不然数组越界
    while (mid < len && A[mid] < 0)
        mid++;

    int k = 0;
    int i = mid - 1, j = mid;
    while (i >= 0 && j < len)
    {
        if (A[i] * A[i] < A[j] * A[j])
        {
            ans[k++] = A[i] * A[i];
            i--;
        }
        else
        {
            ans[k++] = A[j] * A[j];
            j++;
        }
    }

    while (i >= 0)
    {
        ans[k++] = A[i] * A[i];
        i--;
    }

    while (j < len)
    {
        ans[k++] = A[j] * A[j];
        j++;
    }

    return ans;
} */

int main()
{
    vector<int> arr{-1};
    sortedSquares(arr);

    return 0;
}