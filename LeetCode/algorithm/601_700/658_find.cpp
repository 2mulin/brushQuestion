/**
 * @date 2022/8/25
 * @author 2mu
 * @brief medium 找到 K 个最接近x的元素
 *
 * 一. 暴力 (错误做法，不知道当时怎么想的)
 * 遍历一遍数组arr，计算出所有 |arr[i] - x|的值，使用大小为k的链表记录所有的节点。
 * 每当有绝对值小于链表中节点的时候，就更新链表。
 * 
 * 时间复杂度：O(n*k)
 * 空间复杂度：O(k)
 * 
 * 二. 排序
 * 利用std::sort，自定义排序。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 
 * 三. 二分查找
 * 
 * 注意题目，是一个排好序的数组。想都不用想，就是二分查找。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 
 */

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    std::sort(arr.begin(), arr.end(),[x](int a, int b){
        int diffA = abs(a - x), diffB = abs(b - x);
        if(diffA < diffB)
            return true;
        else if(diffA == diffB && a < b)
            return true;
        else
            return false;
    });
    std:sort(arr.begin(), arr.begin() + k);
    return std::vector<int>(arr.begin(), arr.begin() + k);
}

/**
void orderInsert(std::list<std::pair<int,int>>& lstNums, std::pair<int, int> pa)
{
    if(lstNums.empty())
    {
        lstNums.push_back(pa);
        return;
    }
    std::list<std::pair<int,int> >::iterator pos = lstNums.end();
    for(auto iter = lstNums.begin(); iter != lstNums.end(); ++iter)
    {
        if(iter->first > pa.first)
        {
            pos = iter;
            break;
        }
        else if(iter->first == pa.first && iter->second > pa.second)
        {
            pos = iter;
            break;
        }
    }
    lstNums.insert(pos, pa);
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    std::list<std::pair<int,int>> result;
    for(size_t i = 0; i < arr.size(); ++i)
    {
        int diff = abs(arr[i] - x);
        orderInsert(result, std::pair<int, int>{diff, arr[i]});
        if(result.size() > k)
            result.pop_back();
    }
    std::vector<int> ans;
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        ans.push_back(iter->second);
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}
*/

int main()
{
    std::vector<int> arr{1,2,3,4,5};
    
    auto result = findClosestElements(arr, 4, 3);
    for(auto val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
