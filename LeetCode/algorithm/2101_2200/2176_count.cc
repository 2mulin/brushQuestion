/**
 * @date 2025/4/17
 * @author 2mu
 * @brief easy 统计数组中相等且可以被整除的数对
 *
 * 1. 遍历
 * 直接使用双层遍历即可。
 * 使用map节省时间吗？完全看不出来，且数组长度最大100，意义不大
 * 
 * 时间复杂度: O(n*n)       空间复杂度: O(1)
 */

 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 
 int countPairs(vector<int>& nums, int k) {
     int count = 0;
     for(int i = 0; i < nums.size(); ++i)
     {
         for(int j = i + 1; j < nums.size(); ++j)
         {
             if (nums[i] == nums[j] && (i * j) % k == 0)
             {
                 ++count;
             }
         }
     }
     return count;
 }
 
 
 int main()
 {
     std::vector<int> vct{3,1,2,2,2,1,3};
     std::cout << countPairs(vct, 2) << std::endl;
     return 0;
 }
 