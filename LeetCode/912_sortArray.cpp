/***********************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief medium 排序
 * 
 * 1.快速排序quicksort
 * 快排的思路就不用说了，很清楚了
 * 主要是要注意细节。一定记得实时更新下标，就是每一次循环都在缩小
 * 下一次循环的范围
 * 
 * 2.归并排序
 * 
 **********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge()
{

}

// 归并排序
void partition(vector<int>& arr, int begin, int end)
{
    if(arr.size() <= 1)
        return;
    int meuidm = arr.size() / 2;
    
}

void mergeSort(vector<int>& arr)
{
    partition(arr, 0, arr.size() - 1);
    return;
}

// 快排
void quicksort(vector<int> &nums, int begin, int end)
{
    if (end - begin <= 0)
        return;
    srand(time(nullptr));
    int key = rand() % (end - begin) + begin; // 随机选定一个基点
    int i = begin, j = end;
    while (i < j)
    {
        // 从右到左
        while(j > key)
        {
            if(nums[j] < nums[key])
            {
                swap(nums[j], nums[key]);
                key = j;// 记住这个不能少
                break;
            }
            else
                j--;// 记住这个不能少
        }
        // 从左到右
        while(i < key)
        {
            if (nums[i] > nums[key])
            {
                swap(nums[i], nums[key]);
                key = i;// 记住这个不能少
                break;
            }
            else
                i++;// 记住这个不能少
        }
    }
    quicksort(nums, begin, key - 1);
    quicksort(nums, key + 1, end);
    return;
}

vector<int> sortArray(vector<int> &nums)
{
    partition(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> arr{1,231,5,3,1256,2,1654,23,165,432};
    sortArray(arr);
    for(auto i : arr)
        cout << i << '\t';
    return 0;
}