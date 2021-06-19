/**
 * @author ling
 * @date 2021/6/19
 * @brief 串联字符串的最大长度
 * 
 * 1. 递归
 * 我直接想到的暴力，但是官方题解的解法和这里差不多，都是这个思路。
 * 因为是26个字母，所以直接使用一个26个bool值得标记数组，表示这几个字母
 * 是否已经出现过了。
 * 对于每个字符串都有两种可能：选或者不选。所以是2^N。然后选中的字符串
 * 需要遍历一遍，所以是O(N * 2^N)
 * 时间复杂度：O(N * 2^N)             空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int recursion(vector<string> arr, vector<bool> flags)
{
    if(arr.empty())
        return 0;
    vector<bool> flagsTmp = flags;
    string s = arr.back();
    arr.pop_back();
    bool isLegal = true;
    for (auto ch : s)
    {
        if(flags[ch - 'a'] == true)
        {
            isLegal = false;
            break;
        }
        else
            flags[ch - 'a'] = true;
    }
    if(isLegal)
        return max(recursion(arr, flags) + (int)s.size(), recursion(arr, flagsTmp));
    return recursion(arr, flagsTmp);
}

int maxLength(vector<string> &arr)
{
    vector<bool> flags(26, false);
    return recursion(arr, flags);
}

int main()
{
    vector<string> arr = {"abcdefghijklm","bcdefghijklmn","cdefghijklmno"
                        ,"defghijklmnop","efghijklmnopq","fghijklmnopqr"
                        ,"ghijklmnopqrs","hijklmnopqrst","ijklmnopqrstu"
                        ,"jklmnopqrstuv","klmnopqrstuvw","lmnopqrstuvwx"
                        ,"mnopqrstuvwxy","nopqrstuvwxyz","opqrstuvwxyza"
                        ,"pqrstuvwxyzab"};
    cout << maxLength(arr) << endl;
    return 0;
}