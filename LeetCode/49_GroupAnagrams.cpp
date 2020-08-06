/***************************************************************************
 * @date 2020/7/14
 * @author reddragon
 * @description: hard 第49题:字母异位词分组
 * 用的最笨的方法，把每一个字符串都排序，并把string作为key、index作为value保存到map中
 * 遍历整个map，如果key相等，就是一个分组内的字符串。
 ****************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_multimap<string, int> m;
    for (int i = 0; i < strs.size(); i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        m.insert(pair<string, int>(temp, i));
    }
    string temp;
    vector<string> arr;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (temp != it->first)
        {
            if (!arr.empty())
                ans.push_back(arr);
            temp = it->first;
            arr = vector<string>();
            arr.push_back(strs[it->second]);
        }
        else
        {
            arr.push_back(strs[it->second]);
        }
    }
    if (!arr.empty())
        ans.push_back(arr);
    return ans;
}

int main()
{
    vector<string> arr{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(arr);
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        for (int i = 0; i < it->size(); i++)
        {
            cout << it->operator[](i) << '\t';
        }
        cout << endl;
    }

    return 0;
}
