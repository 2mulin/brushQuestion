/**
 * @date 2023/1/5
 * @author 2mu
 * @brief hard 队列中可以看到的人数
 *
 * 1. 双层循环
 * 最简单的思路, 第一层遍历选定一个起点, 开始第二层遍历, 寻找到该起点可以看到的人;
 * 提交之后超时....
 *
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 单调栈
 * 这里逆向思维更加容易解题, 从后往前遍历, 且维护一个单调递减的 单调栈...
 * 但是注意每个人可以看到右边的人数并不是单调栈大小...还需要额外判断..
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


vector<int> canSeePersonsCount(vector<int> &heights)
{
    std::vector<int> ans(heights.size(), 0);
    std::stack<int> st;
    st.push(heights.back());
    for(int i = heights.size() - 2; i >= 0; --i)
    {
        if(heights[i] <= st.top())
            ans[i] = 1;
        else
        {
            int sum = 0;
            while(!st.empty() && heights[i] >= st.top())
            {
                ++sum;
                st.pop();
            }
            if(st.empty())
                ans[i] = sum;
            else
                ans[i] = sum + 1;// st中有一个比当前heights[i]更大的身高, 也可以看到
        }
        st.push(heights[i]);
    }
    return ans;
}

/**
 * @brief 暴力算法
 * @param heights 
 * @return 
 */
/*
vector<int> canSeePersonsCount(vector<int> &heights)
{
    size_t len = heights.size();
    std::vector<int> answer(len, 0);
    for (size_t i = 0; i < len; ++i)
    {
        // max_height记录遍历过程中, [i,j]最高的人
        int sum = 0, max_height = 0;
        for(size_t j = i + 1; j < len; ++j)
        {
            if(heights[i] <= heights[j])
            {
                ++sum;
                break;
            }
            else
            {
                // i, j之间所有其他人 都比i,j矮
                if(max_height < heights[j])
                {
                    ++sum;
                    max_height = heights[j];
                }
            }
        }
        answer[i] = sum;
    }
    return answer; 
}
*/

int main()
{
    std::vector<int> heights{10,6,8,5,11,9};
    std::vector<int> ans = canSeePersonsCount(heights);
    for(auto num : ans)
    {
        std::cout << num << "\t";
    }
    return 0;
}