/**
 * @date 2022/7/28
 * @author 2mu
 * @brief easy 数组序号转换
 *
 * 1. 去重 + 排序
 * 利用map，排序加去重。最后打印一下。
 * 
 * 时间复杂度：O(nlogn) n个元素，每次insert到Map都是logn
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> arrayRankTransform(vector<int> &arr)
{
    // map有序 且 去重
    std::map<int, int> numMap;
    for(auto num : arr)
    {
        numMap.insert({num, 0});
    }
    int idx = 1;
    for(auto iter = numMap.begin(); iter != numMap.end(); ++iter)
    {
        iter->second = idx++;
    }

    std::vector<int> result(arr.size(), 0);
    for(size_t i = 0; i < arr.size(); ++i)
    {
        result[i] = numMap[arr[i]];
    }
    return result;
}

int main()
{
    return 0;
}
