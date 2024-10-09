/**
 * @date 2022/12/31
 * @author 2mu
 * @brief easy 使每位学生都有座位的最少移动次数
 * 
 * 一、排序
 * 这题仔细想想是比较难，但实际上代码比较简单。对两个数组排序，然后按顺序做差，全部相加就可以了。
 * 主要需要想通的就是为什么按顺序做差之和就是最少移动次数？ 
 * 仔细想想确实没有比这更优的移动次数。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int len =  seats.size(), ans = 0;
    for(int i = 0; i < len; ++i)
    {
        ans += abs(seats[i] - students[i]);
    }
    return ans;
}

int main()
{
    std::vector<int> seat{3,1,5};
    std::vector<int> student{2,7,4};
    std::cout << minMovesToSeat(seat, student) << std::endl;
    return 0;
}
