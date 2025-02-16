/**
 * @date 2025/2/16
 * @author 2mu
 * @brief easy 将每个元素替换为右侧最大元素
 *
 * 1. 常规思维
 * 双循环遍历，第1层正常遍历，比如到达i时，开始第二层循环，就从i开始遍历到最后找到最大值。
 * 然后赋值。
 * 
 * 时间复杂度: O(n*n)     空间复杂度: O(1)
 * 
 * 2. 逆向思维
 * 从后往前遍历，这样很容易就可以维护一个从i到end的最大值元素。
 * 且只需要遍历一次。
 * 
 * 时间复杂度：O(n)       空间复杂度：O(1)
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <climits>
 
 
 using namespace std;
 
 vector<int> replaceElements(vector<int> &arr)
 {
     std::vector<int> result(arr.size(), -1);
     int max_val = -1;
     for(int i = arr.size() - 2; i < arr.size(); --i)
     {
         max_val = std::max(max_val, arr[i + 1]);
         result[i] = max_val;
     }
     return result;
 }
 
 int main()
 {
     std::vector<int> nums = {17,18,5,4,6,1};
     nums = replaceElements(nums);
     for(auto num : nums)
         std::cout << num << '\t';
     std::cout << std::endl;
     return 0;
 }
 