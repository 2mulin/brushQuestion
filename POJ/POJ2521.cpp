#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int n, m, p, c;
    while (cin >> n >> m >> p >> c)
    {
        if (n == m && m == p && p == c && c == 0)
            break;
        else
        {
            cout << p + n - m << std::endl;
        }
    }
    return 0;
}