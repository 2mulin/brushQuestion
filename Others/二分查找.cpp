#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;
    // 注意这里right是size - 1。如果right = size，但是下面就是循环条件就是left < right
    while (left <= right) // 注意这个等号
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    return 0;
}