/**
 * @date 2022/7/13
 * @author 2mu
 * @brief medium 行星碰撞
 *
 * 1. 模拟
 * 用一个新的数组一个个接收每个行星，如果最新的一个行星和新数组最后一个元素方向不同，这必然产生爆炸。
 * while循环，直到不能产生爆炸为止。
 * 
 * 比较有意思的是，负数表示往左走，正数表示往右边走。就是{-2,-1,1,2}这种永远不会相撞。
 * （讲道理，行星肯定会撞呀，都是围着恒星转，转一圈不就撞了吗）
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    std::vector<int> ans;
    for(size_t i = 0; i < asteroids.size(); ++i)
    {
        if(ans.empty())
            ans.push_back(asteroids[i]);
        else
        {
            // int result = asteroids[i] * ans.back();
            if(ans.back() > 0 && asteroids[i] < 0)
            {
                if (abs(asteroids[i]) > abs(ans.back()))
                {
                    ans.pop_back();
                    --i;
                }
                else if(abs(asteroids[i]) == abs(ans.back()))
                    ans.pop_back();
            }
            else
                ans.push_back(asteroids[i]);
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums{-1, -2, 2, 1};
    auto result = asteroidCollision(nums);
    for(auto num : result)
        std::cout << num << ",";
    std::cout << std::endl;
    return 0;
}
