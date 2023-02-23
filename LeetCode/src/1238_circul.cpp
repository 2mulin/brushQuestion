/**
 * @date 2022/2/23
 * @author 2mu
 * @brief medium 循环码排列
 *
 * 一、格雷码
 * 通过搜索，知道这就是格雷码。那么现在就是从start二进制表示开始，生成后面的格雷码。
 * 
 * 参考：<https://oi-wiki.org/misc/gray-code/>
 * 
 * 时间复杂度：O(2的次方)  需要计算2的次方 次格雷码
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

// 得到num的格雷码表示
int GrayCode(int num)
{
    return num ^ (num >> 1);
}

vector<int> circularPermutation(int n, int start)
{
    std::vector<int> ans(1 << n);
    for(int i = 0;  i < ans.size(); ++i)
    {
        ans[i] = GrayCode(i) ^ start;
    }
    return ans;
}

int main()
{
    std::vector<int> ans = circularPermutation(2, 3);
    for(auto num : ans)
        std::cout << num << std::endl;
    return 0;
}
