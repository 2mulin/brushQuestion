/**
 * @date 2024/10/12
 * @author 2mu
 * @brief easy 求出出现两次数字的XOR值
 *
 * 1. 哈希表
 * 利用哈希表判断是否重复，如果是重复数字就可以计算XOR值。
 * 因为nums最多只有50而已，怎么做都会对。
 * 
 * 这里使用不到XOR的性质，害我刚开始还想了半天性质......
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;


int duplicateNumbersXOR(vector<int> &nums)
{
    int result = 0;
    std::unordered_set<int> hash_set;
    for(auto num : nums)
    {
        if(hash_set.find(num) != hash_set.end())
            result ^= num;
        else
            hash_set.insert(num);
    }
    return result;
}


int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 2, 1};
    std::cout << duplicateNumbersXOR(nums) << std::endl;
    return 0;
}
