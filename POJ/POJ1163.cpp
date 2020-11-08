/********************************************************************************************
 * @author reddragon
 * @date 2020/11/8
 * @brief easy 路径最大和
 * 
 * 1. 动态规划
 * 入门级的动态规划
 * 找出递推关系，写出状态转移方程，大部分问题就解决了
 * 时间复杂度：O(NlogN)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

int slove(vector<vector<int> > arr)
{
    size_t cow = arr.size();
    for(size_t i = 1; i < cow; ++i)
    {
        arr[i][0] += arr[i-1][0];
        size_t len = arr[i].size();
        for(size_t j = 1; j < len - 1; ++j)
        {
            arr[i][j] += std::max(arr[i - 1][j], arr[i - 1][j - 1]);
        }
        arr[i][len - 1] += arr[i - 1][len - 2];
    }
    int ans = arr[cow - 1][0];
    for(size_t i = 1; i < arr[cow - 1].size(); ++i)
        ans = std::max(ans, arr[cow - 1][i]);
    return ans;
}

int main()
{
    int n = 5;
    while(cin >> n)
    {
        vector<vector<int> > arr;
        for(int i = 1; i <= n; ++i)
        {
            vector<int> temp(i);
            for(int j = 0; j < i; ++j)
                cin >> temp[j];
            arr.push_back(temp);
        }
        cout << slove(arr) << std::endl;

    }
    return 0;
}