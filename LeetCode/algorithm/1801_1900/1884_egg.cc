/**
 * @date 2024/10/13
 * @author 2mu
 * @brief medium 鸡蛋掉落-两枚鸡蛋
 *
 * 1. dp
 * 不能用二分查找，因为只有2枚鸡蛋。最多只能摔碎一枚。
 * 
 * 使用f[i]表示i层楼的建筑需要的最小操作次数。枚举鸡蛋扔下的位置k，此时有两种情况：
 * 1. 如果鸡蛋碎了，说明答案的范围是[0, k-1], 且此时只剩余一枚鸡蛋只能尝试，需要依次在1，2，3...k-1楼
 * 扔下，需要k-1次
 * 2. 如果鸡蛋没碎，说明答案在[k, i]，并且还是剩余两枚鸡蛋。等价于 f[i - k] 层建筑的子问题，需要尝试。
 * 
 * 状态转移方程：f[i] = min{max{k-1, f[i - k]} + 1}
 * 
 * 这里比较难理解的地方是：题目求的不是具体扔鸡蛋次数，而是类似求出有多少种扔鸡蛋的可能性，每层楼碎都要考虑。
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <climits>


using namespace std;


int twoEggDrop(int n)
{
    std::vector<int> f(n + 1, INT_MAX / 2);
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for(int k = 1; k <= i; ++k)
        {
            f[i] = min(f[i], max(k - 1, f[i - k]) + 1);
        }
    }
    return f[n];
}


int main(int argc, char **argv)
{
    std::cout << twoEggDrop(2) << std::endl;
    return 0;
}
