/*******************************************************************************
 * @author reddragon
 * @date 2020/7/31
 * @brief 组合 midden
 * 1.回溯：每次选中一个数，下次继续选该数后面的数，直到有k个数了
 * 2.二进制排序，有点看不懂
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 回溯
void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &isSelect, int k, int num)
{
    if (temp.size() == k)
        ans.push_back(temp);
    else
    {
        for (size_t i = num; i < isSelect.size(); i++)
        {
            if (!isSelect[i])
            {
                temp.push_back(i);
                isSelect[i] = true;
                backtrack(ans, temp, isSelect, k, i + 1);
                isSelect[i] = false;
                temp.pop_back();
            }
        }
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (n < k)
        return vector<vector<int>>();
    if (n == 1 && k == 1)
        return vector<vector<int>>(1, vector<int>(1, 1));
    vector<vector<int>> ans;
    vector<bool> isSelect(n + 1, false);
    for (size_t i = 1; i <= n; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        isSelect[i] = true;
        backtrack(ans, temp, isSelect, k, i + 1);
        isSelect[i] = false;
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = combine(2, 1);
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (auto i : arr[i])
            cout << i << '\t';
        cout << endl;
    }
    return 0;
}