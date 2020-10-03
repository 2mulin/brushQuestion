#include <iostream>
using namespace std;

typedef unsigned long long ull;

// 快速幂

// 求a的b次方 时间复杂度是O(logN)
ull pow(ull a, ull b)
{
    ull ans = 1;
    // 主要是这里循环次数减少了，b每次右移一位，缩小两倍
    while (b)
    {
        if (b & 1) // 位运算(二进制的与运算)
        {
            ans *= a;
        }
        a *= a;
        b = b >> 1; //精髓所在，每次缩小两倍,所以时间复杂度是O(logN)而不是O(N)
    }
    return ans;
}

int main()
{
    cout << pow(3, 5) << endl;
    return 0;
}