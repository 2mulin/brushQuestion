/**
 * @date 2025/1/6
 * @author 2mu
 * @brief medium 
 *
 * 1. 遍历+set
 * 使用一个set保存特殊楼层，然后直接从bottom遍历到top，假设每一层是i
 * 只要i是特殊楼层，那当前连续楼层就中断了，记录一下。
 * 
 * 该方案直接超时，理论上哈希表中查找某个元素是O(1)，但是从这里的实际情况来看，并不是O(1)
 * 反而是排序的O(nlogn)才能通过...
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 排序
 * 该方案是真的牛逼...
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


// int maxConsecutive(int bottom, int top, vector<int> &special)
// {
//     int len = 0, max_len = 0;
//     std::unordered_set<int> hash_table(special.begin(), special.end());
//     for(int i = bottom; i <= top; ++i)
//     {
//         if (hash_table.find(i) != hash_table.end())
//         {
//             max_len = std::max(len, max_len);
//             len = 0;
//         }
//         else
//             ++len;
//     }
//     max_len = std::max(len, max_len);
//     return max_len;
// }


int maxConsecutive(int bottom, int top, vector<int>& special)
{
    special.push_back(bottom - 1);
    special.push_back(top + 1);
    std::sort(special.begin(), special.end());

    int max_len = 0;
    for(int i = 1; i < special.size(); ++i)
    {
        max_len = std::max(max_len, special[i] - special[i - 1] - 1);
    }

    return max_len;
}


int main()
{
    std::vector<int> vct = {4, 6};
    std::cout << maxConsecutive(2, 9, vct) << std::endl;
    return 0;
}
