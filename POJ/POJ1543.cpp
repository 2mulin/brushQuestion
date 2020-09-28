/********************************************************************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief easy  完美立方
 * 1.枚举：
 * 枚举每一种可能就行了。四个循环嵌套
 ********************************************************************************************/
#include <iostream>
using namespace std;


int main()
{
    int N;
    while(cin >> N)
    {
        for(int i = 4; i <= N; i++)
        {
            for(int a = 2; a <= i - 2; a++)
            {
                for(int b = a + 1; b <= i - 1; b++)
                {
                    for(int c = b + 1; c <= i; c++)
                    {
                        if(i*i*i == a*a*a + b*b*b + c*c*c)
                            cout << "Cube = " << i << ", Triple = (" << a << ',' << b << ',' << c << ')' << endl; 
                    }
                }
            }
        }
    }
    return 0;
}