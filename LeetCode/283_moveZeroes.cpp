/********************************************************************************************
 * @author reddragon
 * @date 2020/11/19
 * @brief 283 移动零
 * 
 * 1. 双指针
 * 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
 * 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
 * 注意到以下性质：
 *   1. 左指针左边均为非零数；
 *   2. 右指针左边直到左指针处均为零。
 * 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
 * 时间复杂度：O(N)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    if (nums.empty())
        return;
    size_t i = 0, j = 0;
    for (; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
            continue;
        nums[j] = nums[i];
        ++j;
    }
    while(j < nums.size())
        nums[j++] = 0;
    return;
}

int main()
{
    vector<int> arr{0,1,0,3,12};
    moveZeroes(arr);
    for(auto i : arr)
        cout << i << ' ';
    cout << endl;
    return 0;
}