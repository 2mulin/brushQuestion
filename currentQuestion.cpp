/*******************************************************************************
 * @author reddragon
 * @date 2020/8/5
 * @brief 子集 midden
 * 给一个数组，求出这个数组的所有子集
 * 1.回溯：只选择当前pos后面的数，前面数，不选，防止重复
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<vector<int> > ans;
// 回溯
/**************************************
* @param size 取size个数
* @param pos 至少当前第pos个后的数
* @param nums 数组，可以取得数
* @param temp 已经取到的数
**************************************/
void backtrace(int size, size_t pos,vector<int>& nums, vector<int> temp)
{
    if(size == temp.size())
    {
        ans.push_back(temp);
        return;
    }
    for(size_t i = pos; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrace(size,i + 1,nums,temp);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    ans.push_back(vector<int>());// 空集是子集
    int n = nums.size();
    for(size_t i = 1; i <= n; i++)
    {
            vector<int> temp;
        backtrace(i,0,nums,temp);
    }
    return ans;
}

int main()
{
    vector<int> arr{1,2,3};
    vector<vector<int>> res = subsets(arr);
    for (size_t i = 0; i < res.size(); i++)
    {
        for(size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << '\t';
        }
        cout << endl;
    }
    
    return 0;
}               