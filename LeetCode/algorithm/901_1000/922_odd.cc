/**
 * @date 2025/2/4
 * @author 2mu
 * @brief easy 按照奇偶排序数组II
 *
 * 1. 双指针
 * 首先题目有保证数组一半数字是偶数，也就是说一定会有合法答案。
 * 
 * 用双指针，遍历奇数idx，当该idx对应的数字不是奇数时，就想办法从偶数idx中查寻是否有奇数，有就替换。
 * 由于奇数和偶数对半开，所以只需要保证奇数idx都是奇数，那么剩余一半偶数自然也满足条件。
 * 
 * 时间复杂度: O(n)     空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;


vector<int> sortArrayByParityII(vector<int> &nums)
{
    int even_idx = 0, odd_idx = 1;
    while(odd_idx < nums.size())
    {
        if(nums[odd_idx] % 2)
        {
            odd_idx += 2;
        }
        else
        {
            while(nums[even_idx] % 2 != 1)
            {
                even_idx += 2;
            }
            std::swap(nums[odd_idx], nums[even_idx]);
            odd_idx += 2;
            even_idx += 2;
        }
    }
    return nums;
}


int main()
{
    std::vector<int> nums = {2,25,32,1};
    nums = sortArrayByParityII(nums);
    for(auto num : nums)
        std::cout << num << '\t';
    std::cout << std::endl;
    return 0;
}
