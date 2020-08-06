/***************************************************************
 * @date 2020/6/10
 * @author reddragon
 * @description: midden
 * 暴力也可以过，但是时间复杂度：O(n3),空间复杂度：O(1)
 * 双指针：时间复杂度：O(n2),空间复杂度：O(1)
 **************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***************************************************************
 * @date 2020/6/10
 * @author reddragon
 * @description: 找到三个数之和和target最接近的值
 * @return int 最接近的值
 **************************************************************/
int threeSumClosest(vector<int> &nums, int target)
{
    // 暴力可以过，但不是我要的结果。时间复杂度：O(n3),空间复杂度：O(1)
    // int ans = nums[0] + nums[1] + nums[2];
    // for(size_t i = 0; i < nums.size();i++)
    // {
    //     for(size_t j = i + 1; j < nums.size(); j++)
    //     {
    //         for(size_t k = j + 1; k < nums.size(); k++)
    //         {
    //             int sum = nums[i] + nums[j] + nums[k];
    //             if(abs(sum - target) < abs(ans - target))
    //                 ans = sum;
    //         }
    //     }
    // }

    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    // 双指针
    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        // 先确定一个数 i,两个指针，low和hi
        size_t low = i + 1, hi = nums.size() - 1;
        while (low < hi)
        {
            int sum = nums[i] + nums[low] + nums[hi];
            // 差值更小就更接近
            if (abs(target - ans) > abs(target - sum))
                ans = sum;
            if (target - sum > 0)
                low++;
            else if (target - sum < 0)
                hi--;
            else
                return target;
        }
        // 优化：去重
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

int main()
{
    vector<int> arr{-1, 2, 1, -4};
    cout << threeSumClosest(arr, 2) << endl;
    return 0;
}