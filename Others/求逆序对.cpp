/**
 * @date 2020/5/22
 * @author reddragon
 * @description: 找逆序对的算法，使用归并排序的思路
 */

#include <iostream>
#include <vector>
using namespace std;

// 合并
int marge(vector<int> &data, int st1, int len1,
          int st2, int len2)
{
    int res = 0;
    vector<int> temp(len1 + len2);
    int tt = 0, i = st1, j = st2;
    while (i < st1 + len1 && j < st2 + len2)
    {
        // data[i]是前半段的，data[j]是后半段的，出现逆序
        if (data[i] > data[j])
        {
            res += (st1 + len1 - i); // 前半段data[i]之后的数都比后半段data[j]大
            temp[tt++] = data[j++];
        }
        else
            temp[tt++] = data[i++];
    }
    while (i < st1 + len1)
        temp[tt++] = data[i++];
    while (j < st2 + len2)
        temp[tt++] = data[j++];
    // 赋给data
    for (int i = 0; i < temp.size(); i++)
        data[st1++] = temp[i];
    return res;
}
/***
 * @param data 数组
 * @param st 数组起点 
 * @param len 数组长度
 * @return int 数组中的逆序对个数
 * 归并排序的分解
 */
int resolve(vector<int> &data, int st, int len)
{
    long long ans = 0;
    if (len <= 1)
        return ans;
    // 划分
    int mid = len / 2;
    ans += resolve(data, st, mid);
    ans += resolve(data, st + mid, len - mid);
    return ans + marge(data, st, mid, st + mid, len - mid);
}

int main()
{
    vector<int> arr{1, 1, 6, 6, 6, 6, 6, 1};
    cout << resolve(arr, 0, arr.size()) << endl;
    return 0;
}