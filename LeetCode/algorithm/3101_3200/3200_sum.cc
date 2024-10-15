/**
 * @date 2024/10/15
 * @author 2mu
 * @brief easy 三角形的最大高度
 *
 * 1. 枚举
 * 没看出来什么规律，但是发现红球和篮球的数量最多是100个。
 * 假设有n层三角形，总共需要多少求？ 等差数列前n项和公式求一下即可：(1 + N) N / 2 个
 * 
 * 红篮球总共最多200个，加上公式，可以估计出三角形最高不会超过20层。
 * 然后红球，篮球所在层的数量也是等差数列，公差是2。
 * 
 * 所以可以枚举，从20层 至 1层枚举，得到最大层数
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>


using namespace std;


int maxHeightOfTriangle(int red, int blue)
{
    for(int i = 19; i > 1; --i)
    {
        // 公差为1，前n项求和公式
        int ball_sum = (1 + i) * i / 2;
        if(red + blue < ball_sum)
            continue;

        // 奇数层 == 偶数层 或者 奇数层 + 1 == 偶数层
        int odd_level_count, even_level_count;
        if(i % 2)
        {
            odd_level_count = i / 2 + 1;
            even_level_count = i / 2;
        }
        else
        {
            odd_level_count = even_level_count = i / 2;
        }

        // 公差为2，前n项求和公式
        int odd_num_sum = odd_level_count + odd_level_count * (odd_level_count - 1); // 奇数层 个数总和
        int even_num_sum = 2 * even_level_count + even_level_count * (even_level_count - 1);// 偶数层 个数总和
        if (red >= odd_num_sum && blue >= even_num_sum)
            return i;
        if (red >= even_num_sum && blue >= odd_num_sum)
            return i;
    }
    return 1;
}

int main(int argc, char **argv)
{
    std::cout << maxHeightOfTriangle(9, 3) << std::endl;
    return 0;
}
