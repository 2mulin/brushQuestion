#include <iostream>
#include <cmath>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

bool arr[10001]; //素数表，第1到9999个素数

int main()
{
    //素数筛选法,任何数的倍数一定不是素数
    memset(arr, true, sizeof(arr));
    for (int i = 2; i <= sqrt(10001); i++)
    {
        if (arr[i])
        {
            for (int j = 2 * i; j <= 10001; j += i)
                arr[j] = false;
        }
    }

    int n;
    while (cin >> n && n != 0)
    {
        int count = 0;
        for (int i = n; i >= 2; i--)
        {
            if (arr[i])
            {
                int sum = 0;
                for (int j = i; j >= 2; j--)
                {
                    if (arr[j])
                    {
                        sum += j;
                        if (sum == n)
                            count++;
                        else if (sum > n)
                            break;
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}