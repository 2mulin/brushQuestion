/**
 * @date 2024/10/10
 * @author 2mu
 * @brief easy 优质数对的总数I
 *
 * 1. 遍历
 * 
 * 题目先看数字范围，范围很小，所以即使是双层遍历也就是O(2500)次比较。
 * 所以这题很简单，直接按照规则模拟比较即可。
 * 
 * 时间复杂度: O(n*m)
 * 空间复杂度: O(1)
 * 
 * 2. 枚举
 * 
 * 遍历nums2中出现过的数字a，然后枚举a*k的倍数，最大枚举到nums1数组中最大值。再大肯定不满足
 * 且nums1中的数字可以使用哈希表存储起来，直接判断枚举的倍数是否在哈希表中，在就累加计数。
 * 最后返回总数
 */

#include <iostream>
#include <vector>

using namespace std;

int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int result = 0;
    for(int i = 0; i < nums1.size(); ++i)
    {
        for(int j = 0; j < nums2.size(); ++j)
        {
            if(nums1[i] % (nums2[j] * k) == 0)
                ++result;
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums1 = {1, 2, 4, 12};
    std::vector<int> nums2 = {2 ,4};
    std::cout << numberOfPairs(nums1, nums2, 3) << std::endl;
    return 0;
}
