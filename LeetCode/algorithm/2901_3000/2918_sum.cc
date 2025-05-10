/**
 * @date 2025/5/10
 * @author 2mu
 * @brief medium 数组的最小元素和
 *
 * 1. 枚举
 * 
 * 先计算左右两个数组总和，然后做差，记录左右两数组相差多少。
 * 然后查看题目要求是最小元素和，什么情况下是最小的呢？
 * 1）某个数组没有0，那另一个加到该数组大小即可，就是最小值。
 * 2）两边都有0，那么就是数组元素总和大的那个数组所有0都换为1，就是最小值。
 * 
 * 时间复杂度: O(n+m)
 * 空间复杂度: O(1)
 */

 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 
 long long minSum(vector<int> &nums1, vector<int> &nums2)
 {
     long long sum1 = 0, sum2 = 0;
     int left_zero = 0, right_zero = 0;
     for(auto num : nums1)
     {
         sum1 += num;
         if (num == 0)
         {
             ++left_zero;
         }
     }
 
     for(auto num : nums2)
     {
         sum2 += num;
         if (num == 0)
         {
             ++right_zero;
         }
     }
     if (left_zero == 0 && right_zero == 0)
     {
         if (sum1 == sum2)
             return sum1;
         else
             return -1;
     }
     else if (left_zero == 0)
     {
         if (sum1 >= sum2 + right_zero)
             return sum1;
         else
             return -1;
     }
     else if (right_zero == 0)
     {
         if (sum1 + left_zero <= sum2)
             return sum2;
         else
             return -1;
     }
     else
     {
         return std::max(sum1 + left_zero, sum2 + right_zero);
     }
     return 0;
 }
 
 
 int main()
 {
     std::vector<int> nums1 = {3, 2, 0, 1, 0};
     std::vector<int> nums2 = {6, 5, 0};
     std::cout << minSum(nums1, nums2) << std::endl;
     return 0;
 }
 