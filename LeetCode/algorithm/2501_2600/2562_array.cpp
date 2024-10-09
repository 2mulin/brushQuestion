/**
 * @date 2023/10/12
 * @author 2mu
 * @brief easy 找出数组的串联值 
 *
 * 1. 双指针
 * 一个指针从前往后遍历, 一个指针从后往前遍历; 知道两个指针相遇时, 表示结束;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long findTheArrayConcVal(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    long long ans = 0;
    while(i <= j)
    {
        if(i != j)
        {
            std::string numStr = std::to_string(nums[i]) + std::to_string(nums[j]);
            // 1 <= nums[i] <= 10000 ; 所以不用担心越界
            ans += stoi(numStr);
        }
        else
        {
            ans += nums[i];
        }
        ++i;
        --j;
    }
    return ans;
}

int main()
{
    std::vector<int> vct{7,52,2,4};
    std::cout << findTheArrayConcVal(vct) << std::endl;
    vct = {2, 2, 2};
    std::cout << findTheArrayConcVal(vct) << std::endl;
    return 0;
}
