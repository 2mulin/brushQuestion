/*******************************************************************************
 * @author reddragon
 * @date 2020/8/5
 * @brief 子集 medium
 * 给一个数组，求出这个数组的所有子集
 * 1.回溯：定义一个回溯方法 backtrack(pos, curr)，第一个参数为索引 pos，第二个参数为当前子集 curr。
 *      1.如果当前子集构造完成，将它添加到输出集合中。
 *      2.否则，从 first 到 n 遍历索引 i  (这里就是for循环)。
 *          1.将整数 nums[i] 添加到当前子集 curr。
 *          2.继续向子集中添加整数：backtrack(i + 1, curr)。
 *          3.从 curr 中删除 nums[i] 进行回溯。
 * 时间：O(N* 2的N次方)     空间：()
 * 
 * 2.穷举：可以再草稿纸上画出解空间树。很清晰
 * 就是和平常生活中做排列使用的方法一个道理
 * 每次碰到一个数就是两种选择，要或者不要，可以写成尾递归。简单易懂，看代码
 * 提交后发现比回溯好多了。
 * 时间：O(N* 2的N次方)
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<vector<int>> ans;
// 穷举
/**************************************
* @param pos 判定当前nums[pos]是否选择
* @param nums 数组，可以取的数
* @param temp 已经取到的数
**************************************/
void backtrace(size_t pos, const vector<int> &nums, vector<int> temp)
{
    if (pos == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    // 不要该数字
    backtrace(pos + 1, nums, temp);
    // 要该数字
    temp.push_back(nums[pos]);
    backtrace(pos + 1, nums, temp);
    return;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    ans.push_back(vector<int>()); // 加入空集
    size_t n = nums.size();
    // 第一个数必选，以此数为开头，判断后面数选还是不选
    for (size_t i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(nums[i]);
        backtrace(i + 1, nums, temp);
    }
    return ans;
}


// 回溯
// /**************************************
// * @param size 取size个数
// * @param pos 至少当前第pos个后的数
// * @param nums 数组，可以取得数
// * @param temp 已经取到的数
// **************************************/
// void backtrace(int size, size_t pos, vector<int> &nums, vector<int> temp)
// {
//     if (size == temp.size())
//     {
//         ans.push_back(temp);
//         return;
//     }
//     for (size_t i = pos; i < nums.size(); i++)
//     {
//         temp.push_back(nums[i]);
//         backtrace(size, i + 1, nums, temp);
//         temp.pop_back(); // 回溯
//     }
// }

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     ans.push_back(vector<int>()); // 空集是子集
//     int n = nums.size();
//     for (size_t i = 1; i <= n; i++)
//     {
//         vector<int> temp;
//         backtrace(i, 0, nums, temp);
//     }
//     return ans;
// }

int main()
{
    vector<int> arr{1, 2, 3};
    vector<vector<int>> res = subsets(arr);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}