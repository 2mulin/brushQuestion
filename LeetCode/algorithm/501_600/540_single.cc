/**
 * @date 2024/11/10
 * @author 2mu
 * @brief medium 有序数组中的单一元素
 *
 * 1. 异或
 * 两个相同的数字进行异或运算，最终结果是0。而0和任意数字进行异或运算，结果是该数字。
 * 所以将数组中所有数字做一次异或运算，就是结果。
 * 
 * 但该方法不满足题目要求，因为题目要求O(logn)的时间复杂度，通常是二分，实际上是利用下标的奇数偶数性质二分的。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    int result = 0;
    for(auto num : nums)
    {
        result ^= num;
    }
    return result;
}


int main(int argc, char **argv)
{
    std::vector<int> nums{1,1,2,3,3,4,4,8,8};
    std::cout << singleNonDuplicate(nums) << std::endl;
    return 0;
}
