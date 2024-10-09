/**
 * @date 2024/6/2
 * @author 2mu
 * @brief easy 分糖果
 *
 * 1. 去重
 * 题目比较简单, 先将糖果类型去重, 检查共有多少种类, 设有x种, 然后x和n/2进行比较;
 * x < n/2, 最多可以吃x种;
 * x >= n/2, 最多可以吃n/2种;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;


int distributeCandies(vector<int> &candyType)
{
    std::unordered_set<int> typeSet;
    for(int type: candyType)
    {
        typeSet.insert(type);
    }
    int limit = candyType.size() / 2;
    if(typeSet.size() > limit)
        return limit;
    return typeSet.size();
}


int main(int argc, char **argv)
{
    std::vector<int> candyType{1,1,2,3};
    std::cout << distributeCandies(candyType) << std::endl;
    return 0;
}
