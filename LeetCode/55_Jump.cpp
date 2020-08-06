/****************************************************
 * @author reddragon
 * @date 2020/7/17
 * @description: midden 跳跃游戏
 * 贪心的思想。每次记录下最远能到达的距离，一次for循环
 * 看能否到达最后
****************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return true;
    int maxPos = nums[0];
    for (int i = 1; i < nums.size() && i <= maxPos; i++)
    {
        maxPos = max(i + nums[i], maxPos);
    }
    if (maxPos >= nums.size() - 1)
        return true;
    return false;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 8, 74523, 544};
    cout << canJump(arr) << endl;
    return 0;
}