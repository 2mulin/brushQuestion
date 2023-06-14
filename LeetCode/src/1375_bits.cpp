/**
 * @date 2023/6/14
 * @author 2mu
 * @brief medium 二进制字符串前缀一致的次数
 *
 * 1. 暴力
 * 直接for循环遍历flips数组, 然后改变当前二进制字符串位置i的元素 为1;
 * 在一层for循环判断前i个字符是否都是1, 后i个字符都是0; 显然会超时, 不用试了;
 * 
 * 时间复杂度: O(m*n)
 * 空间复杂度: O(m*n)
 * 
 * 2. 脑筋急转弯
 * 如果遍历到 flips[i] 时刚好满足二进制字符串 [前i个字符是否都是1, 后i个字符都是0] 这种要求;
 * 只有一种可能, 1~i这几个index都刚好在 flips前i个元素中全部出现了;
 *  再进一步:  flips前i个元素的最大值一定就是i
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

int numTimesAllBlue(vector<int> &flips)
{
    int cnt = 0;
    int maxIdx = -1; // 当前已遍历到的最大idx
    for(size_t i = 0; i < flips.size(); ++i)
    {
        maxIdx = std::max(maxIdx, flips[i]);
        if(maxIdx == i + 1)
        {
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    return 0;
}