#include <iostream>
using namespace std;

int arr[1001] = {0};
int ans[1001] = {0};

int T(int n)
{
    if (arr[n] != 0)
        return arr[n];
    else
    {
        arr[n] = T(n - 1) + n;
        return arr[n];
    }
}

int W(int n)
{
    if (ans[n] != 0)
        return ans[n];
    else
    {
        ans[n] = W(n - 1) + n * T(n + 1);
        return ans[n];
    }
}

int main()
{
    int n;
    cin >> n;
    arr[1] = 1;
    ans[1] = 3;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        cout << i << ' ' << num << ' ' << W(num) << std::endl;
    }

    return 0;
}