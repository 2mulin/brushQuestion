/********************************************************************************************
 * @author reddragon
 * @date 2021/4/10
 * @brief easy 丑数
 * 
 * 1，暴力
 * 找到所有的因数, 再找到所有的因数的质因数, 看看是否只有2,3,5
 * 时间复杂度:         空间复杂度: O(1)
 * 
 * 2. 数学
 * 所有的丑数都可以写成2^a + 3^b + 5^c , 其次负数一定不是丑数
 * 所以可以直接, 能除以2或者3或者5的时候直接除
 * 最后看是否等于1, 等于1就说明没有其他的质因数了
 * 时间复杂度: O(logN)         空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isUglyNum(int n)
{
    if(n < 0)
        return false;
    vector<int> arr{2, 3, 5};
    for(auto it : arr)
    {
        while(n % it == 0)
            n /= it;
    }
    return n == 1;
}

int main()
{
    cout << isUglyNum(9999999999) << endl;
    return 0;
}