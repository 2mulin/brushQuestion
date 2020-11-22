/********************************************************************************************
 * @author reddragon
 * @date 2020/11/22
 * @brief 最大子序列和问题
 * 
 * 1.遍历一次
 * 只要当前子序列的和小于下一个数字，那不如就从下一个数字从新开始计算和。
 * 时间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        // 求解
        int sum = arr[0], ans = arr[0];
        for(int i = 1; i < n; ++i)
        {
            if(sum + arr[i] < arr[i])
            {
                sum = arr[i];
            }
            else
                sum += arr[i];
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}