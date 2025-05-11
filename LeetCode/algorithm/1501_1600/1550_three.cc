/**
 * @date 2025/5/11
 * @author 2mu
 * @brief easy 存在连续三个奇数的数组
 *
 * 1. 枚举
 * 
 * 对数组进行遍历，然后判断是否存在3个连续的奇数就可以。
 * 即枚举数组中 所有连续3个元素，判断是否都是奇数。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 
 bool threeConsecutiveOdds(vector<int>& arr)
 {
     int count = 0, continuity_cnt = 0;
     for(auto num : arr)
     {
         if (num % 2 == 1)
         {
             count++;
             continuity_cnt = std::max(count, continuity_cnt);
         }
         else
             count = 0;
     }
     if (continuity_cnt >= 3)
         return true;
     return false;
 }
 
 
 int main()
 {
     std::vector<int> nums = {2, 6, 4, 1};
     std::cout << threeConsecutiveOdds(nums) << std::endl;
     return 0;
 }
 