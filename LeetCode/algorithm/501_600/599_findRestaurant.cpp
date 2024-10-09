/**
 * @author ling
 * @date 2021/3/14
 * @brief easy 两个列表的最小索引和
 *
 * 1. 遍历
 * 时间复杂度：O(N*N)       空间复杂度：O(1)
 * 
 * 2. 哈希表
 * 官方题解答案，显然，使用哈希表可以加速查找，将list1存放到哈希表中。
 * 但是问题也很明显，就是会占用空间。
 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::vector;
using std::string;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    int minSum = INT_MAX;
    vector<string> ans;
    for (size_t i = 0; i < list1.size(); ++i)
    {
        for(size_t j = 0; j < list2.size(); ++j)
        {
            if(list1[i] == list2[j])
            {
                if(minSum > i + j)
                {
                    ans.clear();
                    minSum = i + j;
                    ans.push_back(list1[i]);
                }
                else if (minSum == i + j)
                    ans.push_back(list1[i]);
                else
                    continue;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}