/**
 * @author ling
 * @date 2021/5/28
 * @brief medium 汉明距离总和
 * 
 * 1. 暴力
 * 首先实现计算汉明距离的函数,复杂度为O(1).
 * 然后遍历整个数组,枚举所有2个数一组的可能性（两层for循环）,然后加起来。
 * 时间复杂度： O(N*N)        空间复杂度：O(1)
 * 
 * 2. 逐位计算
 * 我们把暴力发的思路换一下，暴力法是先计算每两个数上有几位不相同，反过来
 * 我们可以计算每一位上，该数组中所有的数这一位是0还是1。然后两者相乘就是了。
 * 时间复杂度： O(N)          空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalHammingDistance(vector<int> &nums)
{
    int ans = 0;
    int sz = nums.size();
    for(int i = 0; i < 32; ++i)
    {
        /// 在数组种，第i位是1的数的个数
        int count = 0;
        for(auto val : nums)
        {
            if(val & (1 << i))
                ++count;
        }
        ans += (count * (sz - count));
    }
    return ans;
}
/* 
int HammingDistance(int num1, int num2)
{
    int Xor = num1 ^ num2;
    int ans = 0;
    // 计算有多少位1
    unsigned int cmp = 1;
    while (cmp)
    {
        if (Xor & cmp)
            ++ans;
        cmp <<= 1;
    }
    return ans;
}

int totalHammingDistance(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            ans += HammingDistance(nums[i], nums[j]);
        }
    }
    return ans;
} */

int main()
{
    vector<int> nums{4, 14, 2};
    cout << totalHammingDistance(nums) << endl;
    return 0;
}