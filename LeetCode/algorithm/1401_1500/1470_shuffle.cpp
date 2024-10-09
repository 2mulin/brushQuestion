/**
 * @date 2022/8/29
 * @author 2mu
 * @brief easy 重新排列数组
 *
 * 一. 额外数组
 * 按照要求遍历一遍就可以了。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 
 * 二. 双指针
 * 原地交换，节省空间。算了，会损失时间。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    std::vector<int> result(2*n, 0);
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        result[index] = nums[i];
        index += 2;
    }
    index = n;
    for(int i = 1; i < 2*n; i+=2)
    {
        result[index] = nums[i];
        index += 2; 
    }
    return result;
}

int main()
{

    return 0;
}
