#include <iostream>
using namespace std;

int main()
{
    double ans = 0;
    for (int i = 0; i < 12; i++)
    {
        double temp;
        cin >> temp;
        ans += temp;
    }
    cout << "$" << ans / 12 << endl;
    return 0;
}