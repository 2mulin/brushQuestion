/****************************************************************************************************
 * @date 2020/6/10
 * @author reddragon
 * @description:
 * 暴力法：遍历每个元素 xx，并查找是否存在一个值与 target - xtarget−x 相等的目标元素。
 * 时间复杂度：O(n2).空间复杂度：O(1)
 * 
 * 哈希表：一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
 * 然后，在第二次迭代中，我们将检查每个元素所对应的目标元素(target - nums[i]target−nums[i])是否存在于表中。
 * 注意，该目标元素不能是 nums[i]nums[i] 本身！
****************************************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2);
    int size = static_cast<int>(nums.size());
    if (size <= 1)
        return ans;
    multimap<int, int> m;
    for (int i = 0; i < size; i++)
        // 第一个是键，键可以重复，值不可以重复
        m.insert(pair<int, int>{nums[i], i});
    for (auto i = m.begin(); i != m.end(); i++)
    {
        auto num = m.find(target - i->first); // 根据key找，看存不存在，返回迭代器
        if (num != m.end())
        {
            // 8 = 4 + 4但是数组里只有一个4
            if (num != i || (num == i && (++num)->first == i->first))
            {
                ans[0] = i->second; // 保存value
                ans[1] = num->second;
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{-3, 4, 3, 90};
    vector<int> ans = twoSum(nums, 7);
    for (auto i : ans)
        cout << i << '\t';
    return 0;
}