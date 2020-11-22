/********************************************************************************************
 * @author reddragon
 * @date 2020/11/22
 * @brief 最大子序列和问题2
 * 
 * 1.遍历一次
 * 只要当前子序列的和小于下一个数字，那不如就从下一个数字从新开始计算和。.
 * 和第一题差不多，就是有一些额外要求
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
        int left = 0,right = 0,s = 0;
        bool isF = true;
        if(arr[0] >= 0)
            isF = false;
        for(int i = 1; i < n; ++i)
        {
            if(arr[i] >= 0)
                isF = false;
            if(sum + arr[i] <= arr[i])
            {
                sum = arr[i];
                s = i;
            }
            else
                sum += arr[i];
            if(ans < sum)
            {
                left = s;
                right = i;
                ans = sum;
            }
        }
        if(isF)
            cout << 0 << ' ' << arr[0] << ' ' << arr[n - 1] << endl;
        else
        {
            if(ans != 0)
                cout << ans << ' ' << arr[left] << ' ' << arr[right] << endl;
            else
                cout << 0 << ' ' << 0 << ' ' << 0 << endl;
        }
    }
    return 0;
}