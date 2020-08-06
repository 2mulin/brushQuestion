#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int N;
        long S;
        cin >> N >> S;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        //
        int count = 1, ans = INT_MAX;
        long sum = arr[0];
        bool isAns = false;
        int L = 0, R = 0;
        while (1)
        {
            // L右移，缩小区间范围
            if (sum > S)
            {
                isAns = true;
                if (L + 1 > R)
                    break;
                if (ans > count)
                    ans = count;
                sum -= arr[L++];
                count--;
            }
            // R右移,扩大区间范围，增加sum
            if (sum <= S)
            {
                if (R + 1 > N)
                    break;
                sum += arr[++R];
                count++;
            }
        }
        if (isAns)
            cout << ans << endl;
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}