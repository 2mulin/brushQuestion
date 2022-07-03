/**
 * @date 2022/7/3
 * @author 2mu
 * @brief medium 下一个更大元素
 *
 * 1. std::next_permutation
 * 没动脑，借用标准库的实现，直接返回下一个排列顺序。可以满足要求。
 * 
 * 2. 数学
 * 研究题解吧.....
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

int nextGreaterElement(int n)
{
    std::string num = std::to_string(n);
    bool ret = std::next_permutation(num.begin(), num.end());
    if(!ret)
        return -1;
    long long newNum = std::stoll(num);
    if(newNum > INT_MAX)
        return -1;
    return newNum;
}

int main()
{
    std::cout << nextGreaterElement(12) << std::endl;
    std::cout << nextGreaterElement(21) << std::endl;
    return 0;
}
