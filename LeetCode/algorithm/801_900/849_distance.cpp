/**
 * @date 2023/8/22
 * @author 2mu
 * @brief medium 到最近的人的最大距离
 *
 * 1. 双层for循环
 * 遍历整个数组, 当碰到位置上有人时, 就再加一个for循环, 找到下一个有人的位置, 计算两个位置距离;
 * alex只能坐在两者中间, 就可以达到最大距离; 需要关注的是当只有一个空位时, 两者距离是1;
 *
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(1)
 * 
 * 2. 双指针
 * 遍历数组, 当碰到位置上有人时, 记录下来, 然后继续遍历找到下一个有人的位置, 然后比较两者距离;
 * 计较完成后, 记录下来当前位置; 然后继续遍历.
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int maxDistToClosest(vector<int> &seats)
{
    // 题目保证seats的元素数量 >= 2
    int pos = -1, maxDistance = 0;
    // 处理alex做到第一个位置特殊情况
    if(seats.front() == 0)
    {
        int pos = 0;
        for(int i = 0; i < seats.size(); ++i)
        {
            if(seats[i])
            {
                pos = i;
                break;
            }
        }
        maxDistance = max(pos, maxDistance);
    }
    // 处理alex做到最后一个位置特殊情况
    if(seats.back() == 0)
    {
        int pos = 0;
        for(int i = seats.size() - 1; i >= 0; --i)
        {
            if(seats[i])
            {
                pos = i;
                break;
            }
        }
        maxDistance = max((int)seats.size() - pos - 1, maxDistance);
    }

    for(int i = 0; i < seats.size(); ++i)
    {
        if(seats[i])
        {
            if(pos == -1)
            {
                pos = i;
                continue;
            }
            else
            {
                maxDistance = max(maxDistance, (i - pos) / 2);
                pos = i;
            }
        }
    }
    return maxDistance;
}

int main()
{
    std::vector<int> vct = {1,0,0,0,1,0,1};
    std::cout << maxDistToClosest(vct) << std::endl;
    vct = {1,0,0,0};
    std::cout << maxDistToClosest(vct) << std::endl;
    vct = {0, 1};
    std::cout << maxDistToClosest(vct) << std::endl;
    return 0;
}
