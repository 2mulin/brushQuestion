/********************************************************************************************
 * @author reddragon
 * @date 2020/10/7
 * @brief hard 拨钟问题  http://poj.org/problem?id=1166
 * 
 * 1. 枚举
 * 这题有点变化，直接暴力枚举所有可能也行,9层循环。
 * 网上都说是每个按钮可以按四次。
 * 
 * 2. 高斯消元
 * 九个未知数，九个方程组，可以解出来
 * 等我学了再说 \狗头
 ********************************************************************************************/
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
    int src[9];
    for(int i = 0; i < 9; i++)
        cin >> src[i];
    int arr[9];// 用来枚举的数组
    for(arr[0] = 0; arr[0] < 4; arr[0]++)
    {
        for(arr[1] = 0; arr[1] < 4; arr[1]++)
            for(arr[2] = 0; arr[2] < 4; arr[2]++)
                for(arr[3] = 0; arr[3] < 4; arr[3]++)
                    for(arr[4] = 0; arr[4] < 4; arr[4]++)
                        for(arr[5] = 0; arr[5] < 4; arr[5]++)
                            for(arr[6] = 0; arr[6] < 4; arr[6]++)
                                for(arr[7] = 0; arr[7] < 4; arr[7]++)
                                    for(arr[8] = 0; arr[8] < 4; arr[8]++)
                                    {
                                        int temp[9];// 存放枚举的最终结果
                                        temp[0] = (src[0] + arr[0] + arr[1] + arr[3]) % 4; // 可以改变A时钟的按钮
                                        temp[1] = (src[1] + arr[0] + arr[1] + arr[2] + arr[4]) % 4; // 可以改变B时钟的按钮
                                        temp[2] = (src[2] + arr[1] + arr[2] + arr[5]) % 4;
                                        temp[3] = (src[3] + arr[0] + arr[3] + arr[4] + arr[6]) % 4;
                                        temp[4] = (src[4] + arr[0] + arr[2] + arr[4] + arr[6] + arr[8]) % 4;
                                        temp[5] = (src[5] + arr[2] + arr[4] + arr[5] + arr[8]) % 4;
                                        temp[6] = (src[6] + arr[3] + arr[6] + arr[7]) % 4;
                                        temp[7] = (src[7] + arr[4] + arr[6] + arr[7] + arr[8]) % 4;
                                        temp[8] = (src[8] + arr[5] + arr[7] + arr[8]) % 4;
                                        if (temp[0] + temp[1] + temp[2] + temp[3] + temp[4] + temp[5] + temp[6] + temp[7] + temp[8] == 0)
                                        {
                                            for (int i = 0; i < arr[0]; i++) 
                                                cout << "1 ";
                                            for (int i = 0; i < arr[1]; i++) 
                                                cout << "2 ";
                                            for (int i = 0; i < arr[2]; i++) 
                                                cout << "3 ";
                                            for (int i = 0; i < arr[3]; i++) 
                                                cout << "4 ";
                                            for (int i = 0; i < arr[4]; i++) 
                                                cout << "5 ";
                                            for (int i = 0; i < arr[5]; i++) 
                                                cout << "6 ";
                                            for (int i = 0; i < arr[6]; i++) 
                                                cout << "7 ";
                                            for (int i = 0; i < arr[7]; i++) 
                                                cout << "8 ";
                                            for (int i = 0; i < arr[8]; i++) 
                                                cout << "9 ";
                                            cout << endl;
                                            return (0);
                                        }
                                    }
    }
    return 0;
}