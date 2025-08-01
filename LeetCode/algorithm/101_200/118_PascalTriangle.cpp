/**
 * @date 2025/8/1
 * @author 2mu
 * @brief easy 杨辉三角
 *
 * 1. 遍历
 * 时隔5年的二刷
 * 
 * 按照题目要求简单分析，然后就可以发现遍历一遍即可得到答案。
 * 主要是边界条件的分析。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> result;
    result.push_back({1});
    while(--numRows)
    {
        std::vector<int> arr = result.back();
        std::vector<int> temp(arr.size() + 1, 0);
        for(int i = 0; i < arr.size(); ++i)
        {
            if (i - 1 >= 0)
                temp[i] = arr[i - 1] + arr[i];
            else
                temp[i] = arr[i];
        }
        temp.back() = 1;
        result.push_back(temp);
    }
    return result;
}


int main()
{
    auto result = generate(5);
    for(auto vec : result)
    {
        for(auto num : vec)
            std::cout << num;
        std::cout << std::endl;
    }
    return 0;
}
