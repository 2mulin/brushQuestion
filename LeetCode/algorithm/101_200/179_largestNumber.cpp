/********************************************************************************************
 * @author reddragon
 * @date 2021/4/12
 * @brief medium 最大的数
 * 
 * 1，自定义排序
 * 自定义排序规则, 使得排完序之后是最大的.
 * 使用lamuda表达式, 二元谓词.
 * 主要注意两点:        比如这个测试用例: {232,232323,23}  {0,0,0}
 * 通过观察第一个测试用例, 可以看出比较必须循环进行, 知道比出一个大小为止.
 * 至于000, 需要后面处理一下, 也就是说, 不能输出000, 把第一个有效之前的数都删掉
 * 
 * 时间复杂度: O(N^2logN)       空间复杂度: O(N)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string largestNumber(vector<int> &nums)
{
    vector<string> StrArr;
    for (int i = 0; i < nums.size(); ++i)
        StrArr.push_back(to_string(nums[i]));

    sort(StrArr.begin(), StrArr.end(), [](const string &a, const string &b) -> bool {
        int lenA = a.size();
        int lenB = b.size();
        int maxLen = max(lenA, lenB);
        int minLen = max(lenA, lenB);
        int i = 0, j = 0;
        int count = 0;
        while (i < lenA && j < lenB)
        {
            if (a[i] > b[j])
                return true;
            else if (a[i] < b[j])
                return false;
            else
            {
                ++i;
                i %= lenA;
                ++j;
                j %= lenB;
            }
            if (maxLen % minLen == 0 && count > maxLen)
                return false;
            ++count;
        }
        return false;
    });

    // 避免前面多余的0
    string ret;
    bool flag = false;
    for (auto str : StrArr)
    {
        if(!flag)
        {
            if(str == "0")
                continue;
            else
                flag = true;
        }
        ret += str;
    }
    if(ret.empty())
        return "0";
    return ret;
}

int main()
{
    vector<int> nums{0, 0};
    cout << largestNumber(nums) << endl;
    return 0;
}