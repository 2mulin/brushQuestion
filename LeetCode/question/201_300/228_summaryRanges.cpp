/**
 * @date 2023/8/26
 * @author 2mu
 * @brief easy 汇总区间
 *
 * 1. 双指针 + 遍历
 * 首先题目保证给定的数组中没有重复的数字, 并且是按照升序排列;
 * 所以直接遍历是合理的, 也就是双指针 记录区间位置, 遍历时如果发现当前位置
 * 的元素 - 上一个位置的元素不等于1时, 表示不连续; 
 * 
 * 这题目恶心人的地方在于 处理边界条件, 以及计算越界的问题;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 * 
 * 2. 分组循环
 * 使用两个循环的写法, 时间复杂度并没有增加; 而且代码更简洁易懂, 不用处理边界条件;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    std::vector<string> vctAns;
    if(nums.empty())
        return vctAns;
    if(nums.size() == 1)
    {
        vctAns.push_back(std::to_string(nums.front()));
        return vctAns;
    }
    int x = nums.front(), y = nums.front();
    for(size_t i = 1; i < nums.size(); ++i)
    {
        if( i != nums.size() - 1)
        {
            if(nums[i] != y + 1)
            {
                if(x == y)
                    vctAns.push_back(std::to_string(x));
                else
                    vctAns.push_back(std::to_string(x) + "->" + std::to_string(y));
                x = nums[i];
            }
            y = nums[i];
        }
        else
        {
            if(nums[i] != y + 1)
            {
                if(x == y)
                    vctAns.push_back(std::to_string(x));
                else
                    vctAns.push_back(std::to_string(x) + "->" + std::to_string(y));
                vctAns.push_back(std::to_string(nums[i]));
            }
            else
            {
                y = nums[i];
                vctAns.push_back(std::to_string(x) + "->" + std::to_string(y));
            }
        }
    }
    return vctAns;
}

int main()
{
    std::vector<int> vct = {-2147483648,-2147483647,2147483647};
    std::vector<string> vctAns = summaryRanges(vct);
    for(auto str : vctAns)
        std::cout << str << std::endl;
    return 0;
}
