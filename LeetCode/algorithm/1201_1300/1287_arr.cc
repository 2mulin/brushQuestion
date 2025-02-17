/**
 * @date 2025/2/17
 * @author 2mu
 * @brief easy 有序数组中出现次数超过25%的元素
 *
 * 1. 遍历？
 * 先拿到数组长度计算出25%，然后遍历一遍，使用哈希表记录每个元素出现次数
 * 看下哪个元素出现次数超过25%次。
 * 
 * 时间复杂度: O(n)       空间复杂度: O(n)
 * 
 * 2. 二分查找
 * 注意这个数组是有序的数组，所以是可以利用。起码空间复杂度可以降低。
 * 然后是二分查找比较难想到了。
 * 
 * 时间复杂度: O(n)       空间复杂度: O(1)
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <unordered_map>
 #include <climits>
 
 
 using namespace std;
 
 
 
 int findSpecialInteger(vector<int> &arr)
 {
     int len = arr.size();
     int percent = len * 0.25 + 1;
     std::unordered_map<int, int> ma;
     for(int i = 0; i < len; ++i)
     {
         int val = arr[i];
         ma[val]++;
         if (ma[val] >= percent)
             return val;
     }
     return 0;
 }
 
 
 int main()
 {
     std::vector<int> nums = {1,2,2,6,6,6,6,7,10};
     std::cout << findSpecialInteger(nums) << std::endl;
     return 0;
 }
 