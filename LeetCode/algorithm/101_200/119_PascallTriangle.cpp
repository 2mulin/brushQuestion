/**
 * @date 2025/1/28
 * @author 2mu 
 * @brief easy 杨辉三角II
 * 
 * 1. 模拟
 * 要求返回杨辉三角的第rowIndex行
 * 直接模拟，从第一行开始，到rowIndex就输出？
 * 
 * 使用两个vector模拟下
 * 
 * 时间复杂度：O(n*n)  空间复杂度：O(n)
 * 
 * 2. 题解
 * 第1个是普通的模拟可以使用滚动数组优化空间复杂度。第2个是使用数学递推，可以直接得到第n行两个相邻数字的关系。
 */

#include <iostream>
#include <vector>

using namespace std;


vector<int> getRow(int rowIndex)
{
    std::vector<int> result = {1};
    int idx = 0;
    while(idx < rowIndex)
    {
        int len = result.size();
        std::vector<int> tmp(len + 1, 1);
        for(int i = 1; i < len; ++i)
        {
            tmp[i] = result[i - 1] + result[i];
        }
        ++idx;
        result = tmp;
    }
    return result;
}

int main()
{
    std::vector<int> result = getRow(3);
    for(auto num : result)
    {
        std::cout << num << '\t';
    }
    std::cout << std::endl;
    return 0;
}
