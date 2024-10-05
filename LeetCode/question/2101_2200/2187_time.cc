/**
 * @date 2024/10/5
 * @author 2mu 
 * @brief medium 完成旅途的最少时间
 * 
 * 1. 遍历
 * 按照顺序遍历即可，然后每个循环中都判断下time数组中的每个元素
 * 当前时间是否完成了一趟旅途。全部完成后就退出。
 * 
 * 时间复杂度是O(m*n)，n是time数组元素数量，m是循环次数（及最终答案，遍历越久耗时越高）
 * 无法通过，判定为超时
 * 
 * 时间复杂度: O(n*m)
 * 空间复杂度: O(n)
 * 
 * 2. 优化思路
 * 时间复杂度是O(n*m)，m是循环次数，n是time数组元素。那么如果可以减少这两个数字，
 * 也表示时间复杂度在降低，能减低m吗？能减低n吗？
 * 
 * 官方题解有办法，就是进行二分...
 */

#include <iostream>
#include <vector>


long long minimumTime(std::vector<int> &time, int totalTrips)
{
    long long loop_time = 1;
    // 模拟帧循环，一个循环就过去了一秒，检查一次所有time
    while(totalTrips > 0)
    {
        for (auto num : time)
        {
            if (loop_time % num == 0)
            {
                --totalTrips;
            }
        }
        ++loop_time;
    }
    return loop_time - 1;
}


int main()
{
    std::vector<int> time{1, 2, 3};
    std::cout << minimumTime(time, 5) << std::endl;
    time = {2};
    std::cout << minimumTime(time, 1) << std::endl;
    return 0;
}
