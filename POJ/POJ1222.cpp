/********************************************************************************************
 * @author reddragon
 * @date 2020/10/6
 * @brief hard 熄灯问题
 * 
 * 1. 枚举
 * 首先要搞懂一个问题，一个按钮最多按下几次？每个按钮最多按下一次、或者不按。
 * 因为按两次的效果相当于没按、按三次就是按一次的效果。
 * 其次要注意的是，一旦第一行按钮按完确定之后，若是还有未熄灭的灯，那么就只能通过、
 * 按下第二行的按钮来熄灭第一行的灯了。
 * 
 * 位运算可以减低空间复杂度, 题目每次都是5行6列的0和1，显然可以使用位运算缩小空间
 * 一个char是1一字节，八位，足够表示6个01组合
 ********************************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int t = 1; t <= n; t++)
    {
        // 位运算优化空间
        char light[5];
        memset(light,0,sizeof(light));
        for(int i = 0; i < 5; i++)
        {
            for(int j = 5; j >= 0; --j)
            {
                bool num;
                cin >> num;
                if(num)
                    light[i] |= (1 << j);
            }
        }

        char ans[5];// 存放我按下的开关
        memset(ans, 0, sizeof(ans));
        // 枚举第一行所有按下开关的可能，0 ~ (64 -1), 确定第一行实际上后面所有行都确定了。
        for(int i = 0; i < 64; i++)
        {
            char temp[5];// 获得灯的初始状态
            memcpy(temp, light, sizeof(temp));
            memset(ans, 0, sizeof(ans));

            unsigned char switchs = i;// 枚举第一行的开关状态
            for(int j = 0; j < 5; ++j)
            {
                ans[j] = switchs;
                // 让ans[j]起作用
                for(int k = 5; k >= 0; --k)
                {
                    if(switchs & (1 << k))
                    {
                        temp[j] ^= (1 << k);// 中
                        // 左
                        if(k < 5)
                            temp[j] ^= (1 << (k + 1));
                        // 右
                        if(k > 0)
                            temp[j] ^= (1 << (k - 1));
                        // 上下
                        if(j != 0)
                            temp[j - 1] ^= (1 << k);
                        if(j != 4)
                            temp[j + 1] ^= (1 << k);
                    }
                }
                // 第j+1行的状态一定就是第j行的状态。因为第j行亮着的灯要熄灭。
                if(j != 5)
                    switchs = temp[j];
            }
            if(temp[4] == 0)
                break;
        }
        // 输出答案
        cout << "PUZZLE #" << t << endl;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 5; j > 0; --j)
            {
                cout << ((ans[i] >> j) & 1 ) << ' ';
            }
            cout << (ans[i] & 1) << endl;
        }
    }
    return 0;
}