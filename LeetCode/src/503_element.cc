/**
 * @date 2024/7/21
 * @author 2mu
 * @brief medium 下一个更大元素II
 *
 * 1. 单调栈
 * 可恶啊, 还是没做出来, 最后看的题解; 注意单调栈, 还有[拉直]操作, 就是遍历两遍;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    size_t sz = nums.size();
    vector<int> result(sz, -1);
    // 单调递减的单调栈, 存放着nums数组的idx, 这些idx都是还没找到第一个最大值的...
    stack<int> stk;

    // 遍历两遍是因为循环数组... 最后stk不为空, 里面的idx就是没找到比他们更大的值
    for (int i = 0; i < sz * 2 - 1; i++) {
        int new_idx = i % sz;

        while (!stk.empty() && nums[stk.top()] < nums[new_idx])
        {
            // 每次弹出一个idx, 说明该idx对应的值 < nums[new_idx]
            // nums[new_idx] 就是第一个比nums[idx]大的值
            result[stk.top()] = nums[new_idx];
            stk.pop();
        }
        stk.push(new_idx);
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums{4,2,3,4,3};
    auto result = nextGreaterElements(nums);
    for(auto val : result)
        std::cout << val << '\t';
    std::cout << std::endl;
    return 0;
}

