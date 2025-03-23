/**
 * @date 2025/3/23
 * @author 2mu
 * @brief medium 判断一个括号字符串是否有效
 *
 * 1. 栈
 * 这种题目，就是题目还没看完就想到stack了。
 * 但是这里和stack又有一些区别。
 * 
 * 在这里使用deque，模拟两次判断过程。第一次先过滤掉所有 右括号)
 * 如果还有多余的左括号，再尝试能否转换给去掉。
 * 
 * 好的，以上方案全都不通过，最后还是抄写的官方题解。
 * 
 * 时间复杂度: O(n)       空间复杂度: O(n)
 */

 #include <iostream>
 #include <algorithm>
 #include <climits>
 #include <queue>
 
 
 using namespace std;
 
 
 // 对着题解抄了一遍，没看懂题解
 bool canBeValid(string s, string locked)
 {
     int n = s.size();
     int mx = 0;
     int mn = 0;
     for (int i = 0; i < n; ++i)
     {
         if (locked[i] == '1')
         {
             int diff;
             if (s[i] == '(')
             {
                 diff = 1;
             }
             else{
                 diff = -1;
             }
             mx += diff;
             mn = max(mn + diff, (i + 1) % 2);
         }
         else
         {
             ++mx;
             mn = max(mn - 1, (i + 1) % 2);
         }
         if (mx < mn)
         {
             return false;
         }
     }
 
     return mn == 0;
 }
 
 
 int main()
 {
     std::cout << canBeValid("(((())(((())", "111111010111") << std::endl;
     return 0;
 }
 