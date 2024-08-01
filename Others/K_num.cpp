/**
 * @author mulin
 * @date 2024/8/1
 * @brief easy 前K个数
 * 
 * 1. 堆
 * 固定堆的大小K, 注意初始化是一个**大顶堆**;
 * 遍历数组, 假设遍历到数字num, 如果当前堆还没满, 直接将num加入堆中; 否则 num和堆顶元素进行判断;
 * 如果 num < 堆顶元素, 那么删除堆顶元素, 使用num替代, 做一次下滤;
 * 
 * 遍历完所有元素之后, 最小的K个数字就在数组中了;
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(k)
 * 
 * 2. 快速排序
 * 快排每次可以确定一个数字的位置, 假设该位置是P; 如果数组idx从0开始; 那么位置P的数字就是第 P+1 大的元素;
 * 因为 位置P 左边的元素都 <= 它, 右边的元素都 >= 它;
 * 
 * 此时可以通过 P+1 和 K比较, P+1 < K, 缩小快排范围到[P+1, K]; 若是P+1 > K, 缩小范围到[0, P]
 * 直到确认K+1位置的元素是多少; 其它位置的元素同理;
 * 
 * 时间复杂度: O(nlogn), 最快情况下是 O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
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

int findKth(vector<int> nums, int n, int K)
{
    std::priority_queue<int> heap;
    for(int i = 0; i < nums.size(); ++i)
    {
        if (heap.size() < K)
            heap.push(nums[i]);
        else
        {
            if(heap.top() > nums[i])
            {
                heap.pop();
                heap.push(nums[i]);
            }
        }
    }
    return heap.top();
}

int main()
{
    vector<int> arr{1, 2, 3, 100, 7, 8, 4, 5};
    cout << findKth(arr, 5, 3) << endl;
    return 0;
}