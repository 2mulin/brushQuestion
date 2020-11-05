/********************************************************************************************
 * @author reddragon
 * @date 2020/11/5
 * @brief easy 前K个数
 * 
 * 1. 堆排序
 * 可以直接排序（降序），然后输出前K个数。
 * 但是没有必要，建立一个大根堆，每次输出最大的，然后恢复大根堆。
 * 循环K次就可以了
 * 
 * 时间复杂度：O(KlogN)        空间复杂度：O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

// 找到数组的前K大个数，并且输出
void K_num(vector<int> arr, int k)
{
    // 建大顶堆
    int sz = arr.size();
    for(int i = sz / 2 - 1; i >= 0; --i)
    {// 从第一个非叶子结点开始
        int root = i;
        int max = root;
        bool isExit = true;
        do{// 下滤
            isExit = true;
            int left = root*2 + 1;
            int right = root*2 + 2;
            if(left < sz && arr[left] > arr[max])
            {
                max = left;
                isExit = false;
            }
            if(right < sz && arr[right] > arr[max])
            {
                max = right;
                isExit = false;
            }
            std::swap(arr[root],arr[max]);
            root = max;
        }while(!isExit);
    }
    while(k--)
    {
        cout << arr[0] << std::endl;
        std::swap(arr[0], arr[sz - 1]);
        --sz;
        // 恢复大顶堆
        int max = 0;
        int root = 0;
        bool isExit = true;
        do{// 下滤
            isExit = true;
            int left = root*2 + 1;
            int right = root*2 + 2;
            if(left < sz && arr[left] > arr[max])
            {
                max = left;
                isExit = false;
            }
            if(right < sz && arr[right] > arr[max])
            {
                max = right;
                isExit = false;
            }
            std::swap(arr[root],arr[max]);
            root = max;
        }while(!isExit);
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        int k;
        cin >> k;
        K_num(arr, k);
    }
    return 0;
}