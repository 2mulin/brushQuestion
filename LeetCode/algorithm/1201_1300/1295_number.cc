/**
 * @date 2025/4/30
 * @author 2mu
 * @brief easy 统计位数为偶数的数字
 *
 * 1. 遍历
 * 遍历数组中每个元素，并且判断每个元素是几位数字。
 * 最终得出结果。
 * 
 * 时间复杂度: O(n*32)       空间复杂度: O(1)
 */

 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 int getNumberOfDigits(int num)
 {
     int count = 0;
     while(num)
     {
         num /= 10;
         ++count;
     }
     return count;
 }
 
 int findNumbers(vector<int>& nums)
 {
     int result = 0;
     for(auto num : nums)
     {
         if(getNumberOfDigits(num) % 2 == 0)
         {
             ++result;
         }
     }
     return result;
 }
 
 int main()
 {
     std::vector<int> nums{12, 345, 2, 6, 7896};
     std::cout << findNumbers(nums) << std::endl;
     return 0;
 }
 