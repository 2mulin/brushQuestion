/********************************************************************************************
 * @author reddragon
 * @date 2020/11/2
 * @brief POJ Aggressive cows
 * 
 * POJ的cin动不动就超时，记得用std::ios::sync_with_stdio(false);
 * 
 * 1. 穷举+二分
 * 思路：首先分析题意，输入会给出牛栏数目和牛的数目，然后给出每个牛栏的位置
 * 需要使任意两个个牛栏尽可能的远。就是然后让相邻的牛栏尽可能的隔远点
 * 
 * 题目给出了，牛栏位置的范围是[0, 1e9]
 * 穷举：
 * 可以有个想法就是测试所有的牛栏距离，最后求出满足条件的最远的距离。
 * 
 * 但是按照顺序从[0, 1e9]浪费时间，这里可以使用二分。
 * 
 * 时间复杂度：O(NlogN)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;

// 判断ans是否合法，牛的第一个牛栏位置肯定是arr[0]
bool isLegal(const vector<int>& arr, long long ans, int c)
{
    int count = 1; // 起始点可以算上了
    int preCow = 0;// 前一头牛
    for(size_t i = 1; i < arr.size(); i++)
    {
        if(arr[i] - arr[preCow] >= ans)
        {
            count++;
            preCow = i;
        }
    }
    return count >= c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N;// 牛栏个数
    int C;// 奶牛个数
    while(cin >> N >> C)
    {
        vector<int> arr(N);
        for(int i = 0 ; i < N; ++i)
            cin >> arr[i];
        std::sort(arr.begin(), arr.end());

        // 二分法尝试所有答案，看是否满足,缩小范围
        long long L = 0, R = 1e9;
        while(L <= R)
        {
            long long mid = (L + R + 1) / 2;
            if(isLegal(arr, mid, C))
                L = mid + 1;
            else
                R = mid - 1;
        }
        cout << L - 1 << std::endl;
    }
    return 0;
}