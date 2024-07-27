/**
 * @date 2022/7/10
 * @author 2mu
 * @brief medium 最长的斐波那契数子序列
 *
 * 1. 哈希表 + 暴力遍历
 * 遇事不决，全用暴力。只有先暴力解决了，才能想优化的方法。
 * 首先看清题目，要满足要求就是从数组按顺序找三个数，并且num1 + num2 = num3， 然后num2 + num3 = num4, 以此类推，得到最长的序列。
 * 就是数组每次确定前面两个数字，搜寻最后一个数字是否存在就可以了。可以使用哈希表加快查找速度。
 * 
 * 千万不要暴力都没写出来，就想着优化，结果所谓的“优化”只是遗漏了一些情况导致WA
 * 
 * 时间复杂度：O(N*N*N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int lenFibSeq(int idx_1, int idx_2, const std::unordered_map<int,int>& numToIdx, const std::vector<int>& arr)
{
    int count = 0;
    int sum = arr[idx_1] + arr[idx_2];
    if(numToIdx.find(sum) != numToIdx.end())
    {
        count = 2;
        do{
            idx_1 = idx_2;
            idx_2 = numToIdx.at(sum);
            sum = arr[idx_1] + arr[idx_2];
            ++count;
        }while(numToIdx.find(sum) != numToIdx.end());
    }
    return count;
}


int lenLongestFibSubseq(vector<int> &arr)
{
    std::unordered_map<int, int> numToIdx;
    for(size_t i = 0; i < arr.size(); ++i)
        numToIdx[arr[i]] = i;

    int result = 0;
    for(int i = 0; i < arr.size() - 2; ++i)
    {
        for(int j = i + 1; j < arr.size() - 1; ++j)
        {
            int count = lenFibSeq(i, j, numToIdx, arr);
            result = std::max(count, result);
        }
    }

    return result;
}

int main()
{
    std::vector<int> arr = {2,4,7,8,9,10,14,15,18,23,32,50};
    std::cout << lenLongestFibSubseq(arr) << std::endl;
    arr = {1,2,3,4,5,6,7,8};
    std::cout << lenLongestFibSubseq(arr) << std::endl;
    arr = {1,3,7,11,12,14,18};
    std::cout << lenLongestFibSubseq(arr) << std::endl;
    return 0;
}
