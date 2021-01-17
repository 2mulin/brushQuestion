/********************************************************************************************
 * @author reddragon
 * @date 2020/11/18
 * @brief easy 前K个数
 * 
 * 1. 堆排序
 * 可以直接排序（降序），然后输出前K个数。
 * 但是没有必要，建立一个大根堆，每次输出最大的，然后恢复大根堆。
 * 循环K次就可以了
 * 
 * 时间复杂度：O(n+KlogN)        空间复杂度：O(1)
 * 建堆时间复杂度：O(n)  删除堆顶，并恢复：O(logN),删除K次，所以是  O(KlogN)
 * 
 * 2. 快速排序
 * 快排每次可以确定一个数位置pos，看该pos和K差多少，然后缩小查找区间，
 * 直到pos == K，输出
 * 
 * 数组最多分K次，就可以找到第K大的数
 * 时间复杂度: O(NlogK)         空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 快排的思路
int findKth(vector<int> a, int n, int K)
{
    // write code here
    // 注意是逆序
    srand(time(0));
    int pos = rand() % n;
    int low = 0, high = n - 1;
    while (low < high)
    {
        while (low < pos && a[low] >= a[pos])
            ++low;
        swap(a[low], a[pos]);
        pos = low;
        while (pos < high && a[pos] > a[high])
            --high;
        swap(a[pos], a[high]);
        pos = high;
    }
    if (pos < K - 1)
        return findKth(vector<int>(a.begin() + pos + 1, a.end()), n - pos - 1, K - pos - 1); // 确定的位置在pos左边
    else if (pos > K - 1)
        return findKth(vector<int>(a.begin(), a.begin() + pos), pos, K);
    else
        return a[pos];
}
 */
void down(vector<int> &arr, int n, int pos)
{
    while (pos <= n / 2 - 1)
    {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int maxPos = pos;
        if (left < n && arr[left] > arr[maxPos])
            maxPos = left;
        if (right < n && arr[right] > arr[maxPos])
            maxPos = right;
        swap(arr[pos], arr[maxPos]);
        // 不会再下滤了
        if (pos == maxPos)
            break;
        else
            pos = maxPos;
    }
    return;
}

int findKth(vector<int> a, int n, int K)
{
    // 从下往上做一次下滤
    int pos = n / 2 - 1; // 最后一个非叶子节点
    while (pos >= 0)
    {
        // 下滤操作
        down(a, n, pos);
        --pos;
    }
    for (int i = 1; i < K; ++i)
    {
        swap(a[0], a[n - 1]);
        --n;
        down(a, n, 0);
    }
    return a[0];
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    cout << findKth(arr, 5, 3) << endl;
    return 0;
}