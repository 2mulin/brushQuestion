/********************************************************************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief easy  生理周期
 * 
 * 1.枚举：
 * 枚举每一种可能，但是枚举有一些技巧可以加速，有些是绝对错误的样例不需要枚举
 ********************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int p,e,i,d;
    int Case = 1;

    while(cin >> p >> e >> i >> d)
    {
        if(p == e && e == i && i == d && d == -1)
            break;
        // 注意是从d开始的
        int k = d + 1;
        for(; (k-p)%23; k++);
        for(; (k - e) % 28; k += 23);
        for(; (k - i) % 33; k += 23*28);
        cout << "Case " << Case++ << ": the next triple peak occurs in " << k - d << " days." << endl;
    }
    return 0;
}