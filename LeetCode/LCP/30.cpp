/**
 * @date 2023/2/6
 * @author 2mu
 * @brief LCP30 魔塔游戏
 *
 * 1. 优先队列 + 贪心
 * 
 * 维护一个小根堆, 栈顶是当前碰到的最小负数;
 * 遍历一遍数组当碰到生命值小于0, 则将栈顶元素调整到末尾, 当前生命值加上堆顶元素绝对值, 同时记录调整次数;
 * 当调整次数等于数组大小时, 表示全部调整了一遍还是不行, 只能返回-1;
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int magicTower(vector<int> &nums)
{
    int original_size = nums.size();

    // 细节决定成败, sum值累加很大的话, 可能溢出...
    long long count = 0, sum = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if(nums[i] < 0)
        {
            pq.push(nums[i]);
        }
        // 不合法
        if(sum <= 0)
        {
            if(count == original_size)
                return -1;
            ++count;
            // pq不需要判空, 当sum <= 0时, pq一定不为空
            int min_num = pq.top();
            pq.pop();
            nums.push_back(min_num);
            sum -= min_num;
        }
    }
    return count;
}

int main()
{
    std::vector<int> nums{100,100,100,-250,-60,-140,-50,-50,100,150};
    std::cout << magicTower(nums) << std::endl;
    nums = {-200,-300,400,0};
    std::cout << magicTower(nums) << std::endl;
    return 0;
}