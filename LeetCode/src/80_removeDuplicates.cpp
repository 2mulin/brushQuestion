/*******************************************************************************
 * @author reddragon
 * @date 2021/4/6
 * @brief medium 删除数组中的重复项2
 * 
 * 1. 双指针
 * 每个数字最多重复2次
 * 一个指针指向当时满足条件的位置，一个指向需要继续测试的位置。
 * 同时需要计数，因为每个数字可以重复两次。最开始的思路就是
 * 边赋值便记录已经相等元素的个数。等到超过2的时候，就把后面的全部删除。
 * 时间复杂度： O(N)        空间复杂度：O(1)
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// 二刷
int removeDuplicates(vector<int> &nums)
{
    size_t i = 0, j = 0;
    while (j < nums.size())
    {
        if (j + 1 < nums.size() && nums[j] == nums[j + 1])
        {
            int tmp = nums[j];
            j += 2;
            while (j < nums.size() && nums[j] == tmp)
                ++j;
            nums[i++] = tmp;
            nums[i++] = tmp;
            if (j < nums.size())
                nums[i] = nums[j];
            continue;
        }
        nums[i++] = nums[j++];
    }
    return nums.size() - (j - i);
}

// 2020年8月
/* int removeDuplicates(vector<int> &nums)
{
    int len = 0;
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (count < 2)
        {
            nums[len++] = nums[i];
            count++;

            // 可能出现1直接到0.（有些数只有一个，count不会大于2）
            if (i + 1 < nums.size() && nums[len - 1] != nums[i + 1])
                count = 0;
        }
        else
        { // 干掉剩余重复2个以上的数字
            while (i < nums.size() && nums[i] == nums[len - 1])
                i++;
            i--;
            count = 0;
        }
    }
    return len;
}
 */
int main()
{
    vector<int> arr{0, 0, 1, 1, 1, 1, 2, 3, 3};
    removeDuplicates(arr);
    for (auto i : arr)
        cout << i << '\t';
    return 0;
}