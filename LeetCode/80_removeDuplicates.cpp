/*******************************************************************************
 * @author reddragon
 * @date 2020/8/7
 * @brief 删除数组中的重复项2 medium
 * 每个数字最多重复2次
 * 双指针法：一个指针指向当时满足条件的位置，一个指向需要继续测试的位置。
 * 同时需要计数，因为每个数字可以重复两次。
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
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

int main()
{
    vector<int> arr{0, 0, 1, 1, 1, 1, 2, 3, 3};
    removeDuplicates(arr);
    for (auto i : arr)
        cout << i << '\t';
    return 0;
}