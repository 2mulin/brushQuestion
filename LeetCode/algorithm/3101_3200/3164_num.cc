/**
 * @date 2024/10/11
 * @author 2mu
 * @brief medium 优质数对的总数II
 *
 * 1. 遍历模拟
 * 和I一样，使用遍历模拟的方式，发现会超时。
 * 这里的n和m最大是10的5次方。所以会超时。
 * 
 * 时间复杂度: O(n*m)
 * 空间复杂度: O(n)
 * 
 * 2. 枚举
 * 想办法把双层for循环改为一层for循环。
 * 即先nums1的元素存入到哈希表中。然后for循环遍历nums2中的每个元素a
 * 并且遍历过程中枚举a*k的倍数，即a*k*1，a*k*2，a*k*3...
 * 
 * 一个哈希表不行，必须利用两个哈希表，防止nums2中的元素重复计算...否则还会超时，这题还是挺复杂的
 * 
 * 时间复杂度：O(n + m + u/k * logm)
 * 空间复杂度：O(n + m)
 */

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    // nums1中可以有重复元素，key是元素值，value是元素数量
    std::unordered_map<int, int> hash_table1, hash_table2;
    for(int num : nums1)
    {
        hash_table1[num]++;
    }

    // 只有一个for循环，时间复杂度下降到 O(m * 倍数寻找次数)，倍数寻找次数不会超过10的5次方。
    long long result = 0;
    for(int i = 0; i < nums2.size(); ++i)
    {
        auto iter = hash_table2.find(nums2[i]);
        if(iter != hash_table2.end())
        {
            result += iter->second;
            continue;
        }

        int num = nums2[i] * k, times = 1;
        int num_pair_count = 0;

        // 数组元素最大是 1e6
        while(num <= 1e6)
        {
            iter = hash_table1.find(num);
            if (iter != hash_table1.end())
            {
                num_pair_count += iter->second;
                // num2中的单个元素可以和nums1多个元素组成数对，不能break
                // break; 
            }
            ++times;
            num = nums2[i] * k * times;
        }
        result += num_pair_count;
        hash_table2[nums2[i]] = num_pair_count;
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums1 = {1, 3, 4};
    std::vector<int> nums2 = {1, 3, 4};
    std::cout << numberOfPairs(nums1, nums2, 1) << std::endl;
    return 0;
}
