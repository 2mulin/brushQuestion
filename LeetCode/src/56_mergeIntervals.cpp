/**
 * @date 2023/8/27
 * @author 2mu
 * @brief medium 合并区间
 *
 * 1. 排序+遍历
 * 先排序, 因为题目给出的要求并没有保证输入是按照顺序排列的, 直接按照每个区间的begin进行排序就行
 * 排序之后, 则开始遍历, 一旦发现遍历到的当前区间 begin <= 上一个区间的end, 则可以合并;
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    std::vector<std::vector<int>> vctAns;
    if(intervals.empty())
        return vctAns;

    // vector的比较, 默认按照元素字典序 排序; (不知道为啥用自己写的lambda表达式会导致内存泄漏, leetcode检测不通过)
    // std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b)->bool{
    //     if(a.empty() || b.empty())
    //         return true;
    //     if(a.front() <= b.front())
    //         return true;
    //     return false;
    // });
    std::sort(intervals.begin(), intervals.end());
    vctAns.push_back(intervals.front());
    for(int i = 1; i < intervals.size(); ++i)
    {
        int prev_end = vctAns.back()[1], curr_begin = intervals[i][0];
        if(prev_end >= curr_begin)
        {
            // 可以合并区间
            vctAns.back()[1] = std::max(prev_end, intervals[i][1]);
        }
        else
        {
            // 不可以合并
            vctAns.push_back(intervals[i]);
        }
    }
    return vctAns;
}

int main()
{
    std::vector<std::vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> vctAns = merge(intervals);
    for(auto interval : vctAns)
    {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]" << std::endl;
    }
    return 0;
}
