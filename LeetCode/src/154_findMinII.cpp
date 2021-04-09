/********************************************************************************************
 * @author reddragon
 * @date 2021/4/9
 * @brief hard 寻找旋转数组中的最小值II
 * 
 * 1，全部遍历一遍
 * 全部遍历一遍就可以了.
 * 时间复杂度: O(N)        空间复杂度: O(1)
 * 
 * 2. 二分查找
 * 时间复杂度: O(NlogN)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int findMin(vector<int> &nums)
{
    int minNum = INT_MAX;
    for (auto num : nums)
    {
        minNum = min(minNum, num);
    }
    return minNum;
}

int main()
{
    return 0;
}