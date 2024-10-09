/**
 * @date 2023/9/29
 * @author 2mu
 * @brief 种花问题 easy
 *
 * 1. 贪心
 * 这题没这么简单, 需要仔细分析已有信息; 假设a,b两个位置已经种了花; 那么中间a,b中间可以种几个花呢?
 * 第一种: b - a < 3, 一个花也种不了
 * 第二种: b - a >= 3, 可以种最多 (b - a - 2) / 2
 * 
 * 然后可以发现开头和结尾如果是0, 计算方式不是上面的公式, 
 * 所以我们思考中假装给flowerbed头加上1,0 然后尾加上0,1 方便计算;
 * 简单来说, 计算头尾公式不需要-2;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int start = -1, i = 0;
    for(; i < flowerbed.size(); ++i)
    {
        if(flowerbed[i])
        {
            // 特殊计算数组头, 只计算一次
            int cnt = (i - start - 1) / 2;
            n -= cnt;
            start = i++;
            break;
        }
    }

    for(; i < flowerbed.size(); ++i)
    {
        if(flowerbed[i])
        {
            // 计算start 到 i中间可以种的花的数量
            int cnt = (i - start - 2) / 2;
            n -= cnt;
            start = i;
        }
    }
    if(start != -1)
    {
        // 特殊计算数组尾巴
        n = n - (flowerbed.size() - start - 1) / 2;
        if(n <= 0)
            return true;
    }
    else
    {
        // 说明数组中全部都是0, 也需要特殊处理
        if(n <= (flowerbed.size() + 1) / 2)
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> vct{1,0,0,0,1};
    std::cout << canPlaceFlowers(vct, 1) << std::endl;
    return 0;
}
