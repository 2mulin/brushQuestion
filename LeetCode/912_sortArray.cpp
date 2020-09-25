/***********************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief medium 排序
 * 1.快速排序quicksort
 * 
 **********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快排
void quicksort(vector<int> &nums, int begin, int end)
{
    if (end - begin <= 0)
        return;
    int key = rand() % (end - begin) + begin; // 随机选定一个基点
    bool isEnd = false;
    while (!isEnd)
    {
        isEnd = true;
        // 从右到左
        for (int i = end; i > key; i--)
        {
            if (nums[i] < nums[key])
            {
                swap(nums[i], nums[key]);
                key = i;
                isEnd = false;
                break;
            }
        }
        // 从左到右
        for (int i = begin; i < key; i++)
        {
            if (nums[i] > nums[key])
            {
                swap(nums[i], nums[key]);
                key = i;
                isEnd = false;
                break;
            }
        }
    }
    quicksort(nums, begin, key - 1);
    quicksort(nums, key + 1, end);
    return;
}

// quicksort
vector<int> sortArray(vector<int> &nums)
{
    quicksort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    return 0;
}