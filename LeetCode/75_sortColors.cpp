/******************************************************
 * @author reddragon
 * @date 2020/7/30
 * @brief 颜色分类 medium
 * 迪杰斯特拉提出的荷兰三色旗问题
 * 1. 计数排序
 * 时间 O(2n) 空间O(1)
 * 2. 双指针，一个指向0该插入的位置，一个指向2该插入的位置
 * 时间：O(n) 空间：O(1)
 *****************************************************/
#include <iostream>
#include <vector>
using namespace std;

// 双指针解法
void sortColors(vector<int> &nums)
{
    int p0 = 0;
    int p2 = nums.size() - 1;
    // 注意i <= p2
    for (int i = 0; i <= p2; i++)
    {
        if (nums[i] == 0)
        {
            swap(nums[p0], nums[i]);
            p0++;
        }
        if (nums[i] == 2)
        {
            swap(nums[p2], nums[i]);
            i--; // 注意i--，因为换到前面的数需要重新比较
            p2--;
        }
    }
}

// 计数排序
// void sortColors(vector<int> &nums)
// {
//     int red = 0;
//     int white = 0;
//     for (auto it = nums.begin(); it != nums.end(); it++)
//     {
//         if (*it == 0)
//             red++;
//         if (*it == 1)
//             white++;
//     }

//     size_t i = 0;
//     for (i; i < red; i++)
//         nums[i] = 0;
//     for (i; i < red + white; i++)
//         nums[i] = 1;
//     for (i; i < nums.size(); i++)
//         nums[i] = 2;
// }

int main()
{
    vector<int> arr{1, 2, 0};
    sortColors(arr);
    for (auto it : arr)
        cout << it;
    return 0;
}