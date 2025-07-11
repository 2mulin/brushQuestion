/**
 * @date 2025/7/11
 * @author 2mu 
 * @brief medium 无需开会的工作日
 *
 * 1. 暴力
 * 使用一个数组维护，标志每一天是否需要开会。
 * 遍历每一个区间，将区间标志为开会。
 * 
 * 最后遍历数组，统计有几天不会开。
 * 
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(n)
 * 
 * 2. 区间合并
 * 题目说了会议时间可能有重叠，
 * 那就先把会议区间合并，然后遍历一遍查看空闲时间。
 * 
 * 先对区间排序
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int countDays(int days, vector<vector<int>> &meetings)
{
    std::sort(meetings.begin(), meetings.end());
    int left = meetings[0][0], right=meetings[0][1];
    int count = left - 1;
    for(int i = 1; i < meetings.size(); ++i)
    {
        // 注意已经排序了，所以比较的情况变少了
        if (meetings[i][0] > right)
        {
            // 换区间
            count = count + (meetings[i][0] - right - 1);
            left = meetings[i][0];
            right = meetings[i][1];
        }
        else
        {
            right = std::max(right, meetings[i][1]);
        }
    }
    if(right < days)
    {
        count += (days - right);
    }
    return count;
}


// int countDays(int days, vector<vector<int>> &meetings)
// {
//     std::vector<bool> day(days + 1, false);
//     for(auto meeting : meetings)
//     {
//         int start = meeting[0], stop = meeting[1];
//         for(int i = start; i <= stop; ++i)
//         {
//             day[i] = true;
//         }
//     }
//     int result = 0;
//     for(int i = 1; i <= days; ++i)
//     {
//         if (!day[i])
//             ++result;
//     }
//     return result;
// }


int main()
{
    std::vector<std::vector<int>> meetings{{5,7},{1,3},{9,10}};
    std::cout << countDays(10, meetings) << std::endl;
    return 0;
}
