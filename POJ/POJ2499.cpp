#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        unsigned long long num1, num2;
        cin >> num1 >> num2;
        unsigned long long left = 0, right = 0;
        while (num1 != num2 || num1 != 1)
        {
            if (num1 > num2)
            {
                int temp = num1 % num2;
                if (temp)
                {
                    left += num1 / num2;
                    num1 = temp;
                }
                else
                {
                    left += num1 / num2 - 1;
                    num1 = 1;
                }
            }
            else
            {
                int temp = num2 % num1;
                if (temp)
                {
                    right += num2 / num1;
                    num2 = temp;
                }
                else
                {
                    right += num2 / num1 - 1;
                    num2 = 1;
                }
            }
        }
        cout << "Scenario #" << i << ':' << endl;
        cout << left << ' ' << right << endl;
        cout << endl;
    }
    return 0;
}