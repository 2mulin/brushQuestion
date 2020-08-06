/*****************************************************************************
 * @date 2020/2/24
 * @author reddragon
 * @description: 最大子序列的解法
    时间复杂度：O(n)
    一般碰不到这类题，都是考的变种，什么二维的最大矩形，或者一个序列找两个最大序列和
    解法就是维护一个thisSum（当前子序列和）。
    只要当前的序列和 加上 当前数组元素 不比 当前数组元素大的话
    那还不如就直接以当前数组元素为新的起点，最后得到的肯定会更大
******************************************************************************/

#include <iostream>
#include <limits>
using namespace std;

int maxSum(const int *const arr, const int size)
{
    int thisSum = arr[0], Max = arr[0];
    for (int i = 1; i < size; i++)
    {
        thisSum += arr[i];
        if (thisSum < arr[i])
        {
            thisSum = arr[i];
        }
        if (thisSum > Max)
        {
            Max = thisSum;
        }
    }
    return Max;
}

int main()
{
    int arr[5] = {-1, -2, -2, -3, -5};
    cout << maxSum(arr, 5);
    return 0;
}
