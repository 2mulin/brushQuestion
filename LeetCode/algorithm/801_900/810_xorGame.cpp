/*
 * @author ling
 * @date 2021/5/22
 * @brief easy 黑板异或游戏
 * 
 * 1. 数学
 * 根据数组长度是奇数还是偶数分为两种情况。
 * 如果是偶数：那么先手一定赢，使用反证法可以证明。
 * 如果是奇数：那么先计算当前数组异或和是不是0，如果是，那么先手赢，否则后手一定赢（因为先手删除一个之后，又回到偶数情况了）
 * 时间复杂度： O(N)        空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool xorGame(vector<int> &nums)
{
    if (nums.size() % 2 == 0)
        return true;
    else
    {
        int xorSum = 0;
        for (auto num : nums)
            xorSum ^= num;
        return xorSum == 0;
    }
}

int main()
{
    vector<int> nums{1, 1, 2};
    cout << xorGame(nums) << endl;
    return 0;
}