/**
 * @date 2022/2/7
 * @author 2mu
 * @brief medium 警告一小时内使用相同员工卡大于等于三次的人
 *
 * 一、哈希表+排序
 * 
 * 
 * 时间复杂度：O(nlogn + n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int strTimeToMin(string keyTime)
{
    int hour = (keyTime[0] - '0') * 10 + (keyTime[1] - '0');
    int min = (keyTime[3] - '0') * 10 + (keyTime[4] - '0');

    return hour * 60 + min;
}

vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
{
    std::unordered_map<std::string, std::vector<int>> nameToTime;
    size_t sz = keyName.size();
    for(size_t i = 0; i < sz; ++i)
    {
        int min = strTimeToMin(keyTime[i]);
        nameToTime[keyName[i]].push_back(min);
    }

    std::vector<string> vctNames;
    for(auto iter = nameToTime.begin(); iter != nameToTime.end(); ++iter)
    {
        vector<int>& vctTimes = iter->second;
        std::sort(vctTimes.begin(), vctTimes.end());    // 没有保证输入是有序的，所以必须排序
        for(size_t i = 2; i < vctTimes.size(); ++i)
        {
            if(vctTimes[i] - vctTimes[i - 2] <= 60)
            {
                vctNames.push_back(iter->first);
                break;
            }
        }
    }
    // 返回结果需要去重，并且按照字典序排列
    std::sort(vctNames.begin(), vctNames.end());
    return vctNames;
}

int main()
{
    return 0;
}
