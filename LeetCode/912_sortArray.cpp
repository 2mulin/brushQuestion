/********************************************************************************************************
 * @author reddragon
 * @date 2020/10/14
 * @brief medium 排序数组
 * 
 * 1.快速排序quicksort
 * 快速排序的主要思路就是通过划分将待排序的序列分成前后两部分，其中前一部分
 * 的数据都比后一部分的小，然后递归调用函数对两部分的序列进行快速排序，以此
 * 让整个序列达到有序。
 * 时间复杂度：O(nlogn)     空间复杂度: O(h)其中h为递归调用的栈空间
 * 
 * 2.归并排序meageSort
 * 归并排序利用分治的思想来对序列排序，对一个长为n的数组排序，我们先将其分成
 * 两个n/2长度的数组，每次先递归调用函数使两个子序列有序，然后我们再
 * 线性合并O(n)两个子序列。
 * 时间复杂度：O(nlogn)      空间复杂度：O(n+logn)
 * 空间复杂度：O(n)。我们需要额外 O(n) 空间的 tmp 数组，且归并排序递归调用的层数最深为logn，
 * 所以我们还需要额外的 O(logn) 的栈空间，所需的空间复杂度即 O(n+logn)=O(n)。
 * 
 * 3.堆排序heapSort
 * 堆排序的思想就是先将待排序的序列建成大根堆，使得每个父节点的元素大于等于它的子节点。
 * 此时整个序列最大值即为堆顶元素，我们将其与末尾元素交换，使末尾元素为最大值，
 * 然后再调整堆顶元素使得剩下的 n-1个元素仍为大根堆，再重复执行以上操作我们即能得到一个有序的序列。
 * 时间复杂度: O(nlogn)     空间复杂度：O(1)
 *********************************************************************************************************/
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;
/* 快速排序
void quicksort(vector<int> &arr, int b, int e)
{
    if(b >= e)
        return;
    srand(time(nullptr));
    int pos = rand() % (e - b) + b;
    cout << pos << endl;
    int low = b, hi = e;
    while(low < hi)
    {
        while(low < pos)
        {
            if(arr[low] > arr[pos])
            {
                swap(arr[low], arr[pos]);
                pos = low;
                break;
            }
            else
                low++;
        }
        while(pos < hi)
        { 
            if(arr[hi] < arr[pos])
            {
                swap(arr[hi], arr[pos]);
                pos = hi;
                break;
            }
            else
                hi--;
        }
    }
    quicksort(arr, b, pos - 1);
    quicksort(arr, pos + 1, e);
} */

/* 归并排序
void meageSort(vector<int> & arr, int low, int hi)
{
    if(hi <= low)
        return;
    // 分
    int mid = (low + hi) / 2;
    meageSort(arr, low, mid);
    meageSort(arr, mid + 1, hi);

    // 归并
    vector<int> temp(hi - low + 1);
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= hi)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            temp[k++] = arr[j];
            j++;
        }
    }
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while(j <= hi)
        temp[k++] = arr[j++];

    k = 0;
    for(int i = low; i <= hi; i++)
        arr[i] = temp[k++];
    return;
} */

// 堆排序
void heapSort(vector<int> &arr)
{
    // 建大顶堆
    int len = arr.size();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        // 下滤
        int pos = i;
        while ((2 * pos + 1 < len && arr[pos] < arr[2 * pos + 1]) || (2 * pos + 2 < len && arr[pos] < arr[2 * pos + 2]))
        {
            int max = 2 * pos + 1;
            // 需要考虑只有一个叶子的情况，即2*pos + 2是空的
            if (2 * pos + 2 < len)
            {
                if (arr[2 * pos + 1] > arr[2 * pos + 2])
                    max = 2 * pos + 1;
                else
                    max = 2 * pos + 2;
            }
            else
                max = 2 * pos + 1;
            swap(arr[pos], arr[max]);
            pos = max;
        }
    }

    while (len--)
    {
        swap(arr[len], arr[0]);
        int pos = 0;
        while ((2 * pos + 1 < len && arr[pos] < arr[2 * pos + 1]) || (2 * pos + 2 < len && arr[pos] < arr[2 * pos + 2]))
        {
            int max = 2 * pos + 1;
            // 需要考虑只有一个叶子的情况，即2*pos + 2是空的
            if (2 * pos + 2 < len)
            {
                if (arr[2 * pos + 1] > arr[2 * pos + 2])
                    max = 2 * pos + 1;
                else
                    max = 2 * pos + 2;
            }
            else
                max = 2 * pos + 1;
            swap(arr[pos], arr[max]);
            pos = max;
        }
    }
    return;
}

void sortArray(vector<int> &arr)
{
    // quicksort(arr,0,arr.size() -1);
    // meageSort(arr, 0, arr.size() - 1);
    heapSort(arr);
}

int main()
{
    vector<int> arr{2, 1, 4, 3, 6, 3, 9, 8};
    sortArray(arr);
    for (int i : arr)
        cout << i << '\t';
    return 0;
}