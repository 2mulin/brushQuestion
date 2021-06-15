/**
 * @author ling
 * @date 2021/6/14
 * @brief easy 猜数游戏
 * 
 * 1.二分查找
 * 经典猜数游戏, 二分查找就行了.
 * 时间复杂度：O(logN)           空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int guess(int num)
{}

int guessNumber(int n)
{
    int ret = -2;
    long long low = 1, high = n;
    long long num = (high - low) / 2 + low;
    while (ret != 0)
    {
        num = (low + high) / 2;
        ret = guess(num);
        if (ret == -1)
            high = num - 1;
        if (ret == 1)
            low = num + 1;
    }
    return num;
}

int main()
{
    cout << guessNumber(2) << endl;
    return 0;
}