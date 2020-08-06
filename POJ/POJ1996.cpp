#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int *arr1 = new int[a + 1];
        int *arr2 = new int[b + 1];
        int temp[10001] = {0};
        int tempLen = 0;
        for (int i = 0; i <= a; i++)
            cin >> arr1[i];
        for (int i = 0; i <= b; i++)
        {
            cin >> arr2[i];
            temp[i] = arr2[i];
        }
        tempLen = b;

        int ans[10001] = {0};
        // 将arr2代入arr1
        ans[0] += arr1[0];
        for (int i = 1; i <= a; i++)
        {
            for (int j = 0; j <= tempLen; j++)
            {
                ans[j] += temp[j] * arr1[i];
            }
            int temp1[10001] = {0};
            // arr2扩大一次方
            int Len = tempLen;
            for (int j = 0; j <= tempLen; j++)
            {
                for (int k = 0; k <= b; k++)
                {
                    temp1[j + k] += arr2[k] * temp[j];
                    if (j + k > tempLen)
                    {
                        Len = j + k;
                    }
                }
            }
            for (int j = 0; j <= Len; j++)
            {
                temp[j] = temp1[j];
            }
            tempLen = Len;
        }
        while (!ans[tempLen])
            tempLen--;
        for (int i = 0; i < tempLen; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << ans[tempLen] << std::endl;

        delete[] arr1;
        delete[] arr2;
    }
    return 0;
}