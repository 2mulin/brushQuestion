/********************************************************************************************
 * @author reddragon
 * @date 2021/1/10
 * @brief easy 汇总区间
 * 
 * 1，遍历一遍
 * 遍历一遍，找到所有连续的区间，并且记录下来
 * 时间复杂度：O(n)
 ********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ret;
    if (nums.empty())
        return ret;
    int start = nums[0], end = nums[0];
    for (size_t i = 1; i <= nums.size(); ++i)
    {
        if (i < nums.size() && nums[i] == end + 1)
            end = nums[i];
        else
        {
            string tmp;
            tmp += to_string(start);
            if (start != end)
            {
                tmp.push_back('-');
                tmp.push_back('>');
                tmp += to_string(end);
            }
            ret.push_back(tmp);
            // 防止内存泄漏
            //if(i < nums.size())
                start = end = nums[i];
        }
    }
    return ret;
}

int main()
{
    vector<int> arr = {-1};
    vector<string> ret = summaryRanges(arr);
    for(auto i : ret)
        cout << i << endl;
    return 0;
}