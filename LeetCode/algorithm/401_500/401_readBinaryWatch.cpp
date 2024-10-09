/**
 * @author ling
 * @date 2021/6/21
 * @brief easy 二进制手表
 * 
 * 1. 模拟
 * 首先求出所有可能性, 使用algorithm标准库给出的next_permutation函数可以直接得到.
 * 省的自己去写枚举了, 然后将每种可能转换成时间.最后输出就可以了
 * 时间复杂度：O(1)             空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> readBinaryWatch(int turnedOn)
{
    if (turnedOn >= 9)
        return vector<string>();
    vector<bool> flag(10, 0);
    for(int i = 9; i >= 10 - turnedOn; --i)
        flag[i] = true;
    vector<vector<bool>> permutationVec;
    do
    {
        permutationVec.push_back(flag);
    } while (next_permutation(flag.begin(), flag.end()));
    
    vector<string> ret;
    // 分析每个表达式,求出它们所代表的数字
    for(int i = 0; i < permutationVec.size(); ++i)
    {
        int hour = 0;
        int minute = 0;
        for(int j = 0; j < permutationVec[i].size(); ++j)
        {
            if (j <= 3)
            {
                if(permutationVec[i][j])
                    hour += pow(2, 3 - j);
            }
            else
            {
                
                if(permutationVec[i][j])
                    // 2^5到2^0
                    minute += pow(2, 9 - j);
            }
        }
        string time;
        if (hour < 12)
            time = to_string(hour);
        else
            continue;           // 无效时间
        time += ':';
        if(minute >= 0 && minute <= 9)
        {
            time += "0";
            time += to_string(minute);
        }
        else if(minute >= 10 && minute <= 59)
            time += to_string(minute);
        else
            continue;           // 无效时间
        ret.push_back(time);
    }
    return ret;
}

int main()
{
    vector<string> times = readBinaryWatch(1);
    for(auto s : times)
        cout << s << endl;
    return 0;
}