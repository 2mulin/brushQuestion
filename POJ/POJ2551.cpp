#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int ans = 1;
        long long num = 1 % n;
        while (num)
        {
            num = num * 10 + 1;
            num = num % n;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}