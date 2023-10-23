/**
 * @date 2023/10/23
 * @author 2mu
 * @brief easy 老人的数目
 * 
 * 1. 枚举
 * 
 * 枚举每一个字符串中, 表示年龄的字符, 将其读取出来, 转换为数字即可;
 * 最后统计有多少数字年龄 大于 60;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;


int countSeniors(vector<string> &details)
{
    int count = 0;
    for(auto& info : details)
    {
        int age = (info[11] - '0') * 10;
        age = age + info[12] - '0';
        if (age > 60)
            ++count;
    }
    return count;
}


int main()
{
    std::vector<std::string> vct = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    std::cout << countSeniors(vct) << std::endl;    
    return 0;
}
