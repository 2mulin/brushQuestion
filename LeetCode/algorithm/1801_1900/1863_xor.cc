/**
 * @date 2025/4/5
 * @author 2mu
 * @brief easy 找出所有子集的异或总和再求和
 *
 * 1.枚举子集
 * 
 * 注意看题目, 数组长度有限制, 所以可以模拟所有情况, 
 * 将每种子集情况的异或值都计算出来, 最后相加; 计算子集的方法就是:
 * 
 * 枚举nums的每个数字, 每个数字都有两种可能, 选择它作为子集的元素 或者不选它作为子集的元素
 *
 * 时间复杂度: O(n*2的n次方)       空间复杂度: O(n)
 */

 #include <iostream>
 #include <vector>
 #include <numeric>
 
 using namespace std;
 
 
 void _findSubSet(const vector<int>& nums, int idx, int count, int current_xor, vector<int>& results)
 {
     if(count == 0)
     {
         results.push_back(current_xor);
         return;
     }
     if (nums.size() - idx < count)
     {
         // nums中的数字已经不够 用来选, 直接退出
         return;
     }
 
     // 位于idx的数字只有两种可能, 选或者不选
     _findSubSet(nums, idx+1, count, current_xor, results);
     current_xor ^= nums[idx];
     _findSubSet(nums, idx+1, count - 1, current_xor, results);
 }
 
 int subsetXORSum(vector<int> &nums)
 {
     vector<int> xor_results;    
     // 遍历出每一种子集, 计算异或和; 忽略空集, 空集不影响最终结果
     for(int count = nums.size(); count > 0; count--)
     {
         _findSubSet(nums, 0, count, 0, xor_results);
     }
 
     return std::accumulate(xor_results.begin(), xor_results.end(), 0);
 }
 
 int main()
 {
     std::vector<int> nums{5, 1, 6};
     std::cout << subsetXORSum(nums) << std::endl;
     return 0;
 }
 