/**
 * @date 2025/2/24
 * @author 2mu
 * @brief easy 设计有序流
 *
 * 1. 数组存储+遍历
 * 按照题目意思简单模拟即可，没什么特别的技术含量
 * 
 * 时间复杂度: O(n)       空间复杂度: O(n)
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <unordered_map>
 #include <climits>
 
 
 using namespace std;
 
 
 class OrderedStream
 {
 private:
     int m_ptr = 1;
     std::vector<string> m_vct;
 
 public:
     OrderedStream(int n)
     {
         m_ptr = 1;
         m_vct = std::vector<std::string>(n + 1, "");
     }
 
     vector<string> insert(int idKey, string value)
     {
         m_vct[idKey] = value;
 
         std::vector<std::string> result;
         if (m_vct[this->m_ptr] != "")
         {
             int i = this->m_ptr;
             for (i; i < m_vct.size(); ++i)
             {
                 if (m_vct[i] == "")
                     break;
                 result.push_back(m_vct[i]);
             }
             this->m_ptr = i;
         }
         else
         {
             return {};
         }
         return result;
     }
 };
 
 
 int main()
 {
     return 0;
 }
 