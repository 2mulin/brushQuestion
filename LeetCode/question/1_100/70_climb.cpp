/**
 * @date 2022/8/7
 * @author 2mu
 * @brief easy 爬楼梯
 *
 * 1. dp
 * 经典dp，递推找到规律就可以了。不多bb。
 *
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>

using namespace std;

int arr[46] = {0};

int climbStairs(int n)
{ 
    arr[0] = arr[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    return 0;
}
