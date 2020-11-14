/********************************************************************************************
 * @author reddragon
 * @date 2020/11/13
 * @brief medium 最长上升子序列
 *
 * 直接看 POJ300题
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int n = nums.size();
    int maxLen = 1;
    // d数组规定是一个单调递增数组
    vector<int> d(n + 1, 0);
    d[maxLen] = nums[0];
    for(int i = 1; i < n; ++i)
    {
        if(nums[i] > d[maxLen])
            d[++maxLen] = nums[i];// 大于，直接加进去
        else
        {
            // 二分查找，找到第一个最接近nums[i]却又比nums[i]大的元素，
            int left = 1, right = maxLen, pos = 0;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(d[mid] < nums[i])
                {
                    pos = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            d[pos + 1] = nums[i];
        }
    }
    return maxLen;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << lengthOfLIS(arr) << endl;
    }
    return 0;
}