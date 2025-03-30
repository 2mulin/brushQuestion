/**
 * @date 2025/3/30
 * @author 2mu
 * @brief medium 向字符串添加空格
 *
 * 1. 遍历
 * 遍历同时判断space的位置，并且构造一个新的答案字符串。
 * 
 * 时间复杂度: O(n)       空间复杂度: O(n)
 */

 #include <iostream>
 #include <algorithm>
 #include <climits>
 #include <queue>
 
 
 using namespace std;
 
 
 string addSpaces(string s, vector<int>& spaces) {
     std::string result;
 
     int spaces_idx = 0;
     for(int i = 0; i < s.length(); ++i)
     {
         if (spaces_idx < spaces.size() && i == spaces[spaces_idx])
         {
             result.push_back(' ');
             ++spaces_idx;
         }
         result.push_back(s[i]);
     }
     
     return result;
 }
 
 int main()
 {
     std::vector<int> spaces{8, 13, 15};
     std::cout << addSpaces("LeetcodeHelpsMeLearn", spaces) << std::endl;
     return 0;
 }
 