/**
 * @date 2024/9/26
 * @author 2mu
 * @brief easy 数组元素和和数字和
 *
 * 1. 模拟
 * 先计算出元素和, 和数字和, 然后做差;
 * 需要遍历数组中的每个元素, 时间复杂度是O(N); 求数字每一位的和也挺简单, 就不多BB;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int differenceOfSum(vector<int> &nums)
{
    int element_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int num_sum = 0;
    for(auto num : nums)
    {
        while(num)
        {
            num_sum += (num % 10);
            num /= 10;
        }
    }

    int result = std::abs(element_sum - num_sum);
    return result;
}


int main(int argc, char **argv)
{
    std::vector<int> nums{1, 15, 6, 3};
    std::cout << differenceOfSum(nums) << std::endl;
    return 0;
}
