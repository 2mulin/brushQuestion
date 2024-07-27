/**
 * @date 2023/8/28
 * @author 2mu
 * @brief medium 插入区间
 *
 * 1. 模拟
 * 不需要排序了, 因为题目说明intervals已经是排好序了;
 * 开始遍历, 并且判断newInterval是否和元素存在交集, 如果存在就进行合并, 并且有交集的区间肯定是连续在一起的, 全部合并之后;
 * 
 * 再考虑插入; 这个插入非常麻烦.... 这里设置可能需要重新遍历一遍, 来决定insert的位置;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    std::vector<std::vector<int>> vctAns;
    if(intervals.empty())
    {
        vctAns.push_back(newInterval);
        return vctAns;
    }
    
    // isPlace 表示是否已出现过交集, isInsert表示是否已经insert到intervals中
    bool isPlace = false, isInsert = false;
    for(int i = 0; i < intervals.size(); ++i)
    {
        // 先判断 newInterval 和当前区间是否有交集
        if(newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1])
        {
            if(isPlace)
            {
                vctAns.push_back(newInterval);
                isPlace = false;// 只需要insert一次, 并且只会insert一次, 因为是有序的, 如果出现交集, 则出现交集的元素都是在一起的; 全部合并完, 再insert;
                isInsert = true;
            }
            vctAns.push_back(intervals[i]);
        }
        else
        {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            isPlace = true;
        }
    }
    if(!isInsert)
    {
        // vctAns也必须按大小顺序, 所以3种情况: 插入到开头, 中间位置, 或者末尾; 也就是TM的任意的位置都有可能......
        // 就是没有任何交集的情况下, newInterval 是可能插入到任意位置的; 排序需要O(nlogn), 所以还不如遍历一遍;
        for(auto iter = vctAns.begin(); iter != vctAns.end(); ++iter)
        {
            if(iter->front() > newInterval[1])
            {
                vctAns.insert(iter, newInterval);
                isInsert = true;
                break;
            }
        }
        // 需要插入到最末尾
        if(!isInsert)
            vctAns.push_back(newInterval);
    }
    return vctAns;
}

int main()
{
    std::vector<std::vector<int>> intervals{{1,9}};
    std::vector<int> newInterval{2, 5};
    std::vector<std::vector<int>> vctAns = insert(intervals, newInterval);
    for(auto interval : vctAns)
    {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]" << std::endl;
    }
    return 0;
}
