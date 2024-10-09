/********************************************************************************************
 * @author ling
 * @date 2021/4/20
 * @brief medium 旋转数组
 * 
 * 1. 额外数组
 * 使用额外的数组来将每个元素放置正确的位置上。
 * 时间复杂度： O(n)        空间复杂度：O(n)
 * 
 * 2. 去看题解
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int sz = nums.size();
    vector<int> newArr(sz);
    for (int i = 0; i < sz; ++i)
    {
        int pos = (i + k) % sz;
        newArr[pos] = nums[i];
    }
    nums = newArr;
    return;
}

int main()
{
    vector<int> nums{1,2,3,4,5};
    rotate(nums, 3);
    for(auto num : nums)
        cout << num << endl;
    return 0;
}