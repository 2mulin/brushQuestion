/************************************************************************************************
 * @date 2020/6/25
 * @author reddragon
 * @description: medium
 * 给定一个数组，求其下一个排列。
 * 如何得到这样的排列顺序？这是本文的重点。我们可以这样来分析：
 * 我们希望下一个数比当前数大，这样才满足“下一个排列”的定义。
 * 因此只需要将后面的「大数」与前面的「小数」交换，就能得到一个更大的数。
 * 比如 123456，将 5 和 6 交换就能得到一个更大的数 123465。
 * 我们还希望下一个数增加的幅度尽可能的小，这样才满足“下一个排列与当前排列紧邻“的要求。
 * 为了满足这个要求，我们需要：在尽可能靠右的低位进行交换，需要从后向前查找,
 * 将一个 尽可能小的「大数」 与前面的「小数」交换。
 * 比如 123465，下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换
 * 将「大数」换到前面后，需要将「大数」后面的所有数重置为升序，升序排列就是最小的排列。
 * 以 123465 为例：首先按照上一步，交换 5 和 4，得到 123564；然后需要将 5 之后的数重置为升序，得到 123546。
 * 显然 123546 比 123564 更小，123546 就是 123465 的下一个排列
************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*******************************************************
 * @description:偷懒的写法，直接使用stl的algorithm库
void nextPermutation(vector<int>& nums) 
{
    if(std::next_permutation(nums.begin(),nums.end()))
        return;
    else
        sort(nums.begin(),nums.end());
    return;
}
********************************************************/

// next_permutation实现
void nextPermutation(vector<int> &nums)
{
    int i = static_cast<int>(nums.size() - 2);
    // 从后往前，找到第一个顺序对
    while (i >= 0 && nums[i + 1] <= nums[i])
        i--;
    if (i >= 0)
    {
        int j = static_cast<int>(nums.size() - 1);
        // 从后往前，找到第一个数大于nums[i]的数交换
        while (j >= 0 && nums[j] <= nums[i])
            j--;
        // 交换
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        // i之后的全部重置为升序
        sort(nums.data() + i + 1, nums.data() + nums.size());
    }
    else // 全部降序，已经是最大字典序
        sort(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums{1, 3, 2};
    nextPermutation(nums);
    for (auto i : nums)
        cout << i << endl;
    return 0;
}